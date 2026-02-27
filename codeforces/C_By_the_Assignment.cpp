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
#include "./0_debug.cpp"
#else
#define debug(...)
#define Test(tt)
#define Error_file(x)
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

#define fo(i, n) for (decltype(n) i = 0; i < n; i++)
#define re(i, n) for (decltype(n) i = n - 1; i >= 0; i--)
#define fo1(i, a, b) for (decltype(b) i = a; i < b; i++)
#define re1(i, a, b) for (decltype(a) i = a; i >= b; i--)

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
#define print_space(a, n) \
  for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');

constexpr int MOD = 998244353;
constexpr int N = 1e5 + 1;
constexpr int INF = 1e18;
vector<pair<int, int>> bridges;
vector<int> tin, low, visited;
int timer;
v(set<int>) adj;
vi weights;

void dfs_bridges(int u, int p) {
  visited[u] = 1;
  tin[u] = low[u] = timer++;
  for (int v : adj[u]) {
    if (v == p) continue;
    if (!visited[v]) {
      dfs_bridges(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > tin[u]) {
        bridges.push_back({u, v});  // (u,v) is a bridge
      }
    } else {
      // back edge
      low[u] = min(low[u], tin[v]);
    }
  }
}

void find_bridges(int n) {
  timer = 0;
  bridges.clear();
  tin.assign(n, -1);
  low.assign(n, -1);
  visited.assign(n, 0);

  for (int i = 0; i < n; i++) {
    if (!visited[i]) dfs_bridges(i, -1);
  }
}

void solve() {
  int n, m, V;
  cin >> n >> m >> V;
  weights.resize(n);
  fo(i, n) cin >> weights[i];
  adj.clear();
  adj.resize(n);
  fo(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  find_bridges(n);
  // remove all bridges from adjacency list
  for (auto [u, v] : bridges) {
    adj[u].erase(v);
    adj[v].erase(u);
  }

  vi comp(n, -1);
  int curr = 0;
  auto dfs = [&](auto&& dfs, int u) -> void {
    comp[u] = curr;
    for (int v : adj[u]) {
      if (comp[v] == -1) {
        dfs(dfs, v);
      }
    }
  };
  fo(i, n) if (comp[i] == -1) {
    dfs(dfs, i);
    curr++;
  }
  map<int, vi> components;
  fo(i, n) components[comp[i]].push_back(i);
  debug(components);
  auto Colorable = [&](vi& ver) -> int {
    map<int, int> color;  // -1 = uncolored
    for (auto x : ver) color[x] = -1;
    queue<int> q;
    q.push(ver[0]);
    color[ver[0]] = 0;

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        if (color[v] == -1) {
          color[v] = color[u] ^ 1;  // opposite color
          q.push(v);
        } else if (color[v] == color[u]) {
          return false;  // same color neighbor -> not bipartite
        }
      }
    }
    return true;
  };

  auto Cnt = [&](vi& ver) -> int {
    bool color = Colorable(ver);
    debug(ver, color);
    if (!color) {
      for (auto x : ver)
        if (weights[x] != -1 && weights[x] != 0) return 0;
      return 1;
    } else {
      set<int> s;
      for (auto x : ver) s.insert(weights[x]);
      bool assignable = (*s.begin() == -1);
      s.erase(-1);
      if (s.size() == 0 && assignable)
        return V;
      else if (s.size() == 1 && assignable)
        return 1;
      else if (s.size() == 2)
        return 0;
      return 1;
    }
  };
  int ans = 1;
  for (auto [_, c] : components) {
    int cnt = Cnt(c);
    debug(cnt);
    ans = (ans * cnt) % MOD;
  }
  cout << ans << endl;
}

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1000;
  cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
