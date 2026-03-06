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

  using Edge = array<int, 3>;
  vector<Edge> edges(m);
  for (auto& [w, u, v] : edges) {
    cin >> u >> v >> w;
    u--, v--;
  }

  auto og = edges;

  DSU dsu(n);
  sort(all(edges));
  v(v(pii)) adj(n);
  map<Edge, bool> mp;
  for (auto [w, u, v] : edges) {
    if (!dsu.same(u, v)) {
      dsu.unite(u, v);
      adj[u].pb({v, w}), adj[v].pb({u, w});
      mp[{w, u, v}] = true;
    }
  }

  int MX = 20;
  v(v(pii)) D(n, v(pii)(MX, {-1, -1}));
  vi dis(n, -1);
  v(pii) st;
  st.pb({-1, -1});
  auto dfs = [&](auto&& dfs, int nd) -> void {
    for (int i = 0; i < MX; i++) {
      int back = st.size() - (1 << i);
      if (back < 0) break;
      D[nd][i] = st[back];
    }
    for (auto [v, w] : adj[nd])
      if (dis[v] == -1) {
        st.pb({nd, w});
        dis[v] = dis[nd] + 1;
        dfs(dfs, v);
        st.pop_back();
      }
  };
  dis[0] = 0;
  dfs(dfs, 0);
  loop(i, 1, MX - 1) fo(j, n) {
    auto p = D[j][i - 1].F;
    if (p == -1) continue;
    D[j][i].S = max({D[j][i].S, D[j][i - 1].S, D[p][i - 1].S});
  }
  // debug(D);

  auto maxPath = [&](int a, int b) -> int {
    auto mv = [&](int nd, int k) -> pii {
      pii ans = {nd, -1};
      for (int i = 0; i < MX; i++) {
        if (ans.F == -1) return ans;
        if (k & (1 << i)) {
          auto temp = D[ans.F][i];
          ans.F = temp.F;
          ans.S = max(ans.S, temp.S);
        }
      }
      return ans;
    };
    if (dis[a] > dis[b]) swap(a, b);
    auto temp = mv(b, dis[b] - dis[a]);

    b = temp.F;
    int ans = temp.S;
    for (int i = MX - 1; i >= 0; i--) {
      if (D[a][i].F != D[b][i].F) {
        ans = max(ans, D[a][i].S);
        ans = max(ans, D[b][i].S);
        a = D[a][i].F;
        b = D[b][i].F;
        debug(a, b);
        if (a == b) break;
      }
    }
    if (a != b) {
      ans = max(ans, D[a][0].S);
      ans = max(ans, D[b][0].S);
      a = D[a][0].F;
      b = D[b][0].F;
    }
    assert(a == b);
    return ans;
  };

  for (auto [w, u, v] : og) {
    bool var = mp[{w, u, v}] || maxPath(u, v) == w;
    YN(var);
  }
}
