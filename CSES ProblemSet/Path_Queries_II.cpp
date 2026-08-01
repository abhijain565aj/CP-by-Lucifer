// Solution by Abhi Jain aka Lucifer aka abhijain565aj
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order, order_of_key

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "./DEBUG.cpp"
#define local true
#else
#define debug(...)
#define Test(tt)
#define Error_file(x)
#define local false
#endif

#define int long long
typedef long long ll;
typedef long double ld;

#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vvi vector<vi>
#define pii pair<int, int>
#define v(x) vector<x>

#define fo(i, n) for (int i = 0; i < n; i++)
#define re(i, n) for (int i = n - 1; i >= 0; i--)
#define loop(i, a, b) for (int i = a; (a >= b) ? i >= b : i <= b; (a >= b) ? i-- : i++)

#define YN(possible) cout << ((possible) ? "YES" : "NO") << endl;
#define all(x) (x).begin(), (x).end()
#define sortall(x) sort(all(x))
#define F first
#define S second
#define pb push_back
// a.resize(unique(all(a)) - a.begin());

#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

#define read(a, n) \
  for (int i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) \
  for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');

void file(string s = "") {
  if (local) {
    // freopen("error.txt", "w", stderr);
    // freopen("output.txt", "w", stdout);
    // freopen(("input" + s + ".txt").c_str(), "r", stdin);
    return;
  }
}

constexpr int MOD = 1000000007;
constexpr int N = 1e5 + 1;
constexpr int INF = 1e18;

int treeArr[10 * N];
template <typename T>
struct SegmentTree {
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
    // tree.resize(4 * n);
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
      treeArr[v] = a[tl];
    } else {
      int tm = (tl + tr) / 2;
      buildp(a, v * 2, tl, tm);
      buildp(a, v * 2 + 1, tm + 1, tr);
      treeArr[v] = merge(treeArr[v * 2], treeArr[v * 2 + 1]);
    }
  }
  T queryp(int v, int tl, int tr, int l, int r) {
    if (l > r) {
      return default_value;
    }
    if (l == tl && r == tr) {
      return treeArr[v];
    }
    int tm = (tl + tr) / 2;
    return merge(queryp(v * 2, tl, tm, l, min(r, tm)), queryp(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
  void updatep(int v, int tl, int tr, int pos, T new_val) {
    if (tl == tr) {
      treeArr[v] = new_val;
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm) {
        updatep(v * 2, tl, tm, pos, new_val);
      } else {
        updatep(v * 2 + 1, tm + 1, tr, pos, new_val);
      }
      treeArr[v] = merge(treeArr[v * 2], treeArr[v * 2 + 1]);
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
      res = max(res, segtree.query(l, r));  // modify depending on problem
    });
    return res;
  }
  void modify_node(int u, T val) { segtree.update(pos[u], val); }
};
signed main() {
  fastio;
  int n, q;
  cin >> n >> q;
  vi val(n);
  read(val, n);
  vvi adj(n);
  fo(i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  HLD<int, 0> H(adj, 0);
  for (int i = 0; i < n; i++) {
    H.modify_node(i, val[i]);
  }
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int s, x;
      cin >> s >> x;
      H.modify_node(s - 1, x);
    } else if (type == 2) {
      int a, b;
      cin >> a >> b;
      cout << H.query_path(a - 1, b - 1) << " ";
    }
  }
}
