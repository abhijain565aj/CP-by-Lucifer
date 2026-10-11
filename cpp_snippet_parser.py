#!/usr/bin/env python3
"""
Generate .vscode/cpp.code-snippets from marked blocks in ./AJ codes/.

In any .cpp/.h/.hpp file:

    // Snippet: Binary Search
    // Prefix: bs
    // -- start-snippet
    int {{1:left}} = 0, {{2:right}} = n - 1;
    int {{3:mid}} = ({{1:left}} + {{2:right}}) / 2;
    {{cursor}}
    // -- end-snippet

Markers:
  Snippet       Required snippet name.
  Prefix        Optional trigger text; defaults to the snippet name.
  {{1}}         Tab stop; repeated numbers are linked.
  {{1:default}} Tab stop with default text.
  {{1|a,b|}}    Choice dropdown.
  {{cursor}}    Final cursor position; otherwise added at the end.

Run: python3 cpp_snippet_parser.py
Override paths with --root, --vscode-dir, or --output.
"""

import argparse
import json
import re
import sys
from pathlib import Path

EXTENSIONS = {".cpp", ".cc", ".cxx", ".h", ".hh", ".hpp"}
EXCLUDED_DIRS = {
    ".git", ".hg", ".svn", ".vscode", ".idea", "build",
    "cmake-build-debug", "cmake-build-release", "node_modules",
    "vendor", "dist", "out",
}

HEADER = re.compile(r"^\s*//\s*Snippet\s*:\s*(.*?)\s*$", re.I)
PREFIX = re.compile(r"^\s*//\s*Prefix\s*:\s*(.*?)\s*$", re.I)
START = re.compile(r"^\s*//\s*--\s*start-snippet\s*$", re.I)
END = re.compile(r"^\s*//\s*--\s*end-snippet\s*$", re.I)
PLACEHOLDER = re.compile(
    r"\{\{cursor\}\}|\{\{0\}\}|\{\{(\d+)\}\}|"
    r"\{\{(\d+):([^{}]*)\}\}|\{\{(\d+)\|([^{}]*)\|\}\}"
)

# Always included, even when AJ codes/ has no snippets. Its tab stops edit the
# generated marker template's name, prefix, and body directly.
BUILTIN = {
    "AJ Snippet Template": {
        "prefix": "aj-snippet",
        "body": [
            "// Snippet: ${1:Snippet Name}",
            "// Prefix: ${2:prefix}",
            "// -- start-snippet",
            "${3:Write your C++ code here}",
            "// -- end-snippet",
            "$0",
        ],
        "description": "Insert a template for defining a C++ snippet",
    }
}


def escape_text(text):
    return text.replace("\\", "\\\\").replace("$", r"\$").replace("}", r"\}")


def convert_line(line):
    """Convert custom {{...}} placeholders to VS Code snippet syntax."""
    result, last, final_stop = [], 0, False

    for match in PLACEHOLDER.finditer(line):
        # A preceding backslash means this placeholder should remain literal.
        literal = match.start() > 0 and line[match.start() - 1] == "\\"
        start = match.start() - 1 if literal else match.start()
        result.append(escape_text(line[last:start]))
        token = match.group(0)

        if literal:
            result.append(escape_text(token))
        elif token in ("{{cursor}}", "{{0}}"):
            result.append("$0")
            final_stop = True
        elif match.group(1) is not None:
            number = int(match.group(1))
            result.append(f"${number}")
            final_stop |= number == 0
        elif match.group(2) is not None:
            number, default = int(match.group(2)), match.group(3)
            default = default.replace("\\", "\\\\").replace("$", r"\$").replace("}", r"\}")
            result.append(f"${{{number}:{default}}}")
            final_stop |= number == 0
        else:
            number = int(match.group(4))
            choices = match.group(5).split(",")
            choices = [
                c.replace("\\", "\\\\").replace("$", r"\$").replace(",", r"\,").replace("|", r"\|")
                for c in choices
            ]
            result.append("${" + str(number) + "|" + ",".join(choices) + "|}")
            final_stop |= number == 0

        last = match.end()

    result.append(escape_text(line[last:]))
    return "".join(result), final_stop


def parse_file(path):
    lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
    found, i = [], 0

    while i < len(lines):
        header = HEADER.match(lines[i])
        if not header:
            i += 1
            continue

        name, prefix = header.group(1).strip(), header.group(1).strip()
        j = i + 1

        if j < len(lines) and (m := PREFIX.match(lines[j])):
            prefix = m.group(1).strip()
            j += 1

        if not name:
            raise ValueError(f"{path}:{i + 1}: missing snippet name")
        if j >= len(lines) or not START.match(lines[j]):
            i += 1
            continue

        j += 1
        body, has_final = [], False
        while j < len(lines) and not END.match(lines[j]):
            converted, has_stop = convert_line(lines[j])
            body.append(converted)
            has_final |= has_stop
            j += 1

        if j >= len(lines):
            raise ValueError(f"{path}:{i + 1}: missing -- end-snippet for '{name}'")
        if not has_final:
            body.append("$0")

        found.append((name, {
            "prefix": prefix or name,
            "body": body,
            "description": f"Snippet '{name}' from {path.name}",
        }, f"{path}:{i + 1}"))
        i = j + 1

    return found


def main():
    script_dir = Path(__file__).resolve().parent
    cli = argparse.ArgumentParser(description="Generate VS Code C++ snippets from marked source blocks.")
    cli.add_argument("--root", type=Path, default=script_dir / "AJ codes",
                     help="source directory (default: ./AJ codes)")
    cli.add_argument("--vscode-dir", type=Path, default=script_dir / ".vscode",
                     help="output directory (default: ./.vscode)")
    cli.add_argument("--output", type=Path, help="explicit output JSON path")
    args = cli.parse_args()

    root = args.root.expanduser().resolve()
    if not root.is_dir():
        print(f"error: source directory not found: {root}", file=sys.stderr)
        return 2

    files = sorted(
        p for p in root.rglob("*")
        if p.is_file()
        and p.suffix.lower() in EXTENSIONS
        and not any(part in EXCLUDED_DIRS for part in p.relative_to(root).parts[:-1])
    )

    snippets = dict(BUILTIN)
    sources = {name: "<built-in>" for name in snippets}
    created = []
    try:
        for path in files:
            for name, snippet, source in parse_file(path):
                if name in snippets:
                    raise ValueError(
                        f"duplicate snippet name '{name}' in {sources[name]} and {source}"
                    )
                snippets[name] = snippet
                sources[name] = source
                created.append((name, snippet["prefix"], source))
    except (OSError, ValueError) as error:
        print(f"error: {error}", file=sys.stderr)
        return 1

    output = args.output.expanduser().resolve() if args.output else (
        args.vscode_dir.expanduser().resolve() / "cpp.code-snippets"
    )
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(snippets, indent=4, ensure_ascii=False) + "\\n", encoding="utf-8")

    print(f"Scanned {len(files)} C++ files from {root}")
    print(f"Created {len(created) + 1} snippets in {output}:")
    print("  + AJ Snippet Template  [prefix: aj-snippet]  (<built-in>)")
    for name, prefix, source in created:
        print(f"  + {name}  [prefix: {prefix}]  ({source})")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
