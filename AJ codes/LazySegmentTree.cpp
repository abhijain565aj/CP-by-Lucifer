#include <bits/stdc++.h>
using namespace std;
// Lazy Segment Tree
template <typename T>
struct LazySegmentTree {
  vector<T> tree;
  vector<T> lazy;
  int n;
  T default_value;
  function<T(T, T)> merge;
  LazySegmentTree(
      int n,
      T default_value = 0,
      function<T(T, T)> merge = [](T l, T r) { return l + r; }) {
    this->n = n;
    this->default_value = default_value;
    this->merge = merge;
    tree.resize(4 * n);
    lazy.resize(4 * n);
  }
  void build(vector<T>& a) {
    buildp(a, 1, 0, n - 1);
  }
  T query(int l, int r) {
    return queryp(1, 0, n - 1, l, r);
  }
  void update(int l, int r, T val) {
    updatep(1, 0, n - 1, l, r, val);
  }
  void update(int pos, T val) {
    updatep(1, 0, n - 1, pos, pos, val);
  }
  void buildp(vector<T>& a, int v, int tl, int tr) {
    if (tl == tr)
      tree[v] = a[tl];
    else {
      int tm = (tl + tr) / 2;
      buildp(a, v * 2, tl, tm);
      buildp(a, v * 2 + 1, tm + 1, tr);
      tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
  }
  void push(int v, int tl, int tr) {
    if (lazy[v] == 0 || tl == tr) return;
    int tm = (tl + tr) / 2;
    tree[v * 2] += lazy[v] * (tm - tl + 1);
    lazy[v * 2] += lazy[v];
    tree[v * 2 + 1] += lazy[v] * (tr - tm);
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
  }
  T queryp(int v, int tl, int tr, int l, int r) {
    if (l > r) return default_value;
    if (l == tl && r == tr) return tree[v];
    int tm = (tl + tr) / 2;
    push(v, tl, tr);
    return merge(
        queryp(v * 2, tl, tm, l, min(r, tm)),
        queryp(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
  void updatep(int v, int tl, int tr, int l, int r, T val) {
    if (l > r) return;
    if (l == tl && r == tr) {
      tree[v] += val * (tr - tl + 1);
      lazy[v] += val;
    } else {
      int tm = (tl + tr) / 2;
      push(v, tl, tr);
      updatep(v * 2, tl, tm, l, min(r, tm), val);
      updatep(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
      tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
  }
};
