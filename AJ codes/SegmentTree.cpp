#include <bits/stdc++.h>
using namespace std;
// Segment Tree
template <typename T>
struct SegmentTree {
  vector<T> tree;
  int n;
  T default_value;
  function<T(T, T)> merge;
  SegmentTree(
      int n,
      T default_value = 0,
      function<T(T, T)> merge = [](T l, T r) { return l + r; }) {
    this->n = n;
    this->default_value = default_value;
    this->merge = merge;
    tree.resize(4 * n);
  }
  void build(vector<T>& a) {
    buildp(a, 1, 0, n - 1);
  }
  T query(int l, int r) {
    return queryp(1, 0, n - 1, l, r);
  }
  void update(int pos, T new_val) {
    updatep(1, 0, n - 1, pos, new_val);
  }

  void buildp(vector<T>& a, int v, int tl, int tr) {
    if (tl == tr) {
      tree[v] = a[tl];
    } else {
      int tm = (tl + tr) / 2;
      buildp(a, v * 2, tl, tm);
      buildp(a, v * 2 + 1, tm + 1, tr);
      tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
  }
  T queryp(int v, int tl, int tr, int l, int r) {
    if (l > r) {
      return default_value;
    }
    if (l == tl && r == tr) {
      return tree[v];
    }
    int tm = (tl + tr) / 2;
    return merge(queryp(v * 2, tl, tm, l, min(r, tm)), queryp(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
  void updatep(int v, int tl, int tr, int pos, T new_val) {
    if (tl == tr) {
      tree[v] = new_val;
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm) {
        updatep(v * 2, tl, tm, pos, new_val);
      } else {
        updatep(v * 2 + 1, tm + 1, tr, pos, new_val);
      }
      tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
  }
};
