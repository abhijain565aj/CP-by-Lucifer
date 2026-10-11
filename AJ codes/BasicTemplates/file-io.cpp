#include <bits/stdc++.h>
using namespace std;

#define local true
// Snippet:Input Output from file
// Prefix: file-io
// -- start-snippet
auto file = [](string s = ""){
    if (local) {
        freopen("error.txt", "w", stderr);
        freopen("output.txt", "w", stdout);
        freopen(("input" + s + ".txt").c_str(), "r", stdin);
    }
};
// -- end-snippet
