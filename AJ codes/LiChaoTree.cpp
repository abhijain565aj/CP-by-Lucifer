// LiChaoTree
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pb push_back

struct LiChaoTree {
  int n;
  vector<int> tree;
  vector<pii> line;
  LiChaoTree(int n) {
    this->n = n;
    tree.resize(4 * n, 0);
  }
  pii bestLine(int x) {
    return line[queryp(1, 0, n - 1, x)];
  }
  void addLine(pii nline) {
    line.pb(nline);
    updatep(1, 0, n - 1, line.size() - 1);
  }
  int best(int l1, int l2, int x) {
    auto [c1, m1] = line[l1];
    auto [c2, m2] = line[l2];
    int y1 = c1 + m1 * x;
    int y2 = c2 + m2 * x;
    return (y1 < y2) ? l1 : l2;
  }
  int queryp(int v, int tl, int tr, int pos) {
    if (pos == tl && pos == tr) {
      return tree[v];
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
      return best(tree[v], queryp(v * 2, tl, tm, pos), pos);
    } else {
      return best(tree[v], queryp(v * 2 + 1, tm + 1, tr, pos), pos);
    }
  }
  void updatep(int v, int tl, int tr, int new_line) {
    int tm = (tl + tr) / 2;
    if (tl > tr)
      return;
    else if (tl == tr) {
      tree[v] = best(tree[v], new_line, tm);
      return;
    }
    int mid = best(tree[v], new_line, tm);
    int left = best(tree[v], new_line, tl);
    if (mid == new_line)
      swap(tree[v], new_line);
    if (left != mid)
      updatep(v * 2, tl, tm, new_line);
    else
      updatep(v * 2 + 1, tm + 1, tr, new_line);
  }
};
