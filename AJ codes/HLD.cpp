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
      function<T(T, T)> merge = [](T l, T r) { return max(l, r); }) {
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

template <class T, bool VALS_IN_EDGES>
class HLD {
 private:
  int N, R, tim = 0;  // n, root node, time
  vector<vector<int>> adj;
  vector<int> par, siz, depth, rt, pos;  // parent, size, depth, root, position arrays
  SegmentTree<T> segtree;                // Modify as needed
  /** Compute the size of each subtree and set parent-child relationship
   * Subtree of node v corresponds to segment [ pos[v], pos[v] + sz[v] ) */
  void dfs_sz(int v) {
    if (par[v] != -1) adj[v].erase(find(adj[v].begin(), adj[v].end(), par[v]));
    for (int& u : adj[v]) {
      par[u] = v, depth[u] = depth[v] + 1;
      dfs_sz(u);
      siz[v] += siz[u];
      if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
    }
  }
  /** Assign positions for nodes
    * Path from v to the last vertex in ascending heavy path
      corresponds to [ pos[rt[v]], pos[v] ] */
  void dfs_hld(int v) {
    pos[v] = tim++;
    for (int u : adj[v]) {
      rt[u] = (u == adj[v][0] ? rt[v] : u);
      dfs_hld(u);
    }
  }
  /** process all heavy path and combine their results */
  template <class B>
  void process(int u, int v, B op) {
    for (; rt[u] != rt[v]; v = par[rt[v]]) {
      if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
      op(pos[rt[v]], pos[v]);
    }
    if (depth[u] > depth[v]) swap(u, v);
    op(pos[u] + VALS_IN_EDGES, pos[v]);
  }

 public:
  HLD(vector<vector<int>> _adj, int _R)
      : N(_adj.size()), R(_R), adj(_adj), par(N, -1), siz(N, 1), depth(N), rt(N), pos(N), segtree(N)  // modify as needed
  {
    rt[R] = R;
    dfs_sz(R);   // initialise par, sz, depth
    dfs_hld(R);  // initialise root, pos
  }
  T query_path(int u, int v) {
    T res = 0;  // default value, modify depending on problem
    process(u, v, [&](int l, int r) {
      res = max(res, segtree.range_max(l, r + 1));  // modify depending on problem
    });
    return res;
  }
  void modify_node(int u, T val) { segtree.set(pos[u], val); }
};
// int main() {
//   HLD<int, 0> H(adj, 0);
//   for (int i = 0; i < n; i++) {
//     H.modify_node(i, v[i]);
//   }
//   while (q--) {
//     if (type == 1) {
//       cin >> s >> x;
//       --s;
//       H.modify_node(s, x);
//     } else if (type == 2) {
//       cin >> a >> b;
//       --a, --b;
//       cout << H.query_path(a, b) << " ";
//     }
//   }
// }