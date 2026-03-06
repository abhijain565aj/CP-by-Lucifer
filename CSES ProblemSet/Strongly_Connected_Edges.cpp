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

void solve();
void precompute();
struct DSU {
  vector<int> parent, size;  // parent of each node and size of each component
  int components;            // number of connected components
  DSU(int n) {
    parent.resize(n);
    size.resize(n, 1);
    components = n;
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }
  int find(int x) {
    if (parent[x] == x) {
      return x;
    }
    return parent[x] = find(parent[x]);  // path compression
  }
  void unite(int x, int y) {
    x = find(x);  // find the parent of x
    y = find(y);  // find the parent of y
    if (x != y)   // if x and y are not in the same component
    {
      if (size[x] < size[y]) {
        swap(x, y);
      }
      parent[y] = x;
      size[x] += size[y];
      components--;
    }
  }
  bool same(int x, int y)  // check if x and y are in the same component
  {
    return find(x) == find(y);
  }
  int getSize(int x)  // get the size of the component of x
  {
    return size[find(x)];
  }
  int getComponents()  // get the number of connected components
  {
    return components;
  }
};

signed main() {
  fastio;
  int n, m;
  cin >> n >> m;
  vvi adj(n);
  DSU dsu(n);
  fo(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    dsu.unite(u, v);
    adj[u].pb(v);
    adj[v].pb(u);
  }
  if (dsu.getComponents() != 1) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  vi par(n, -1), init(n), fin(n), vis(n);
  v(pii) bridges;
  int time = 0;
  auto dfs = [&](auto&& dfs, int nd) -> void {
    vis[nd] = 1;
    init[nd] = fin[nd] = time++;
    for (auto c : adj[nd]) {
      if (c == par[nd]) continue;
      if (!vis[c]) {
        par[c] = nd;
        dfs(dfs, c);
      }
      fin[nd] = min(fin[c], fin[nd]);
      if (fin[c] > init[nd]) bridges.pb({nd, c});
    }
  };
  dfs(dfs, 0);
  if (bridges.size()) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  debug(init);
  fo(i, n) for (auto x : adj[i]) {
    if (par[x] == i) {
      cout << i + 1 << " " << x + 1 << "\n";
    } else if (init[i] < init[x]) {
      cout << x + 1 << " " << i + 1 << "\n";
    }
  }
}
