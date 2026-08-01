import sys
import random
import subprocess
for i in range(1000):
    with open("input.txt", "w") as f:
        f.write("1\n")
        f.write("".join(["l" if random.randint(1, 2)==1 else "r" for _ in range(100)]))
    subprocess.run(["python3", "testing_tool.py", "input.txt", "./a.out"])