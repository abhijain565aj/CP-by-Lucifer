// B87678
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

constexpr int MOD = 1000000007;
constexpr int N = 1e5 + 1;
constexpr int INF = 1e12;

void solve() {
  int n;
  cin >> n;
  vvi adj(n);
  fo(i, n - 1) {
    int u, v;
    cin >> u >> v;
    adj[u - 1].pb(v - 1);
    adj[v - 1].pb(u - 1);
  }
  vvi dp(n, vi(4, -1));
  v(v(set<int>)) dp1(n, v(set<int>)(4));
  // 0 parent not deleted, I am not deleted
  // 1 parent not deleted, I am deleted
  // 2 parent deleted, I am not deleted
  // 3 parent deleted, I am deleted
  auto fn = [&](auto&& fn, int node, int par, int type) -> int {
    if (dp[node][type] != -1) return dp[node][type];
    bool prDeleted = type & 2;
    bool meDeleted = type & 1;
    if (meDeleted) {
      int size = adj[node].size() - prDeleted;
      if (size <= 2)
        return dp[node][type] = INF;
      int cnt = 1;
      for (auto child : adj[node]) {
        if (child == par) continue;
        int v1 = fn(fn, child, node, 2);
        int v2 = fn(fn, child, node, 3);
        cnt += min(v1, v2);
        if (v2 < v1) {
          dp1[node][type].insert(child);
        }
      }
      return dp[node][type] = cnt;
    } else {
      v(pii) diff;
      for (auto child : adj[node]) {
        if (child == par) continue;
        int notDel = fn(fn, child, node, 0);
        int del = fn(fn, child, node, 1);
        diff.pb({del - notDel, child});
      }
      int req = adj[node].size() - prDeleted - 2;
      int cnt = 0;
      sort(all(diff));
      for (auto [d, child] : diff) {
        if (req > 0) {
          cnt += fn(fn, child, node, 1);
          dp1[node][type].insert(child);
          req--;
        } else {
          int v1 = fn(fn, child, node, 0);
          int v2 = fn(fn, child, node, 1);
          cnt += min(v1, v2);
          if (v2 < v1) {
            dp1[node][type].insert(child);
          }
        }
      }
      return dp[node][type] = cnt;
    }
  };
  int v1 = fn(fn, 0, -1, 0);
  int v2 = fn(fn, 0, -1, 1);
  cout << min(v1, v2) + n << endl;
  vi deleted_nodes(n);
  auto dfs = [&](auto&& dfs, int node, int par, int type) -> void {
    if (type & 1) deleted_nodes[node] = 1;
    for (auto child : adj[node]) {
      if (child == par) continue;
      dfs(dfs, child, node, type * 2 + (dp1[node][type].find(child) != dp1[node][type].end() ? 1 : 0));
    }
  };
  if (v1 < v2)
    dfs(dfs, 0, -1, 0);
  else
    dfs(dfs, 0, -1, 1);

  fo(i, n) {
    if (deleted_nodes[i]) cout << 2 << ' ' << i + 1 << "\n";
  }
  debug(dp);

  for (int i = 0; i < n; ++i) {
    if (deleted_nodes[i]) adj[i].clear();
    vi v;
    for (auto child : adj[i]) {
      if (!deleted_nodes[child]) {
        v.pb(child);
      }
    }
    adj[i] = v;
  }

  vvi paths;
  vi path;
  vi vis(n, 0);
  auto dfs1 = [&](auto&& dfs1, int node, int par) -> void {
    path.pb(node);
    vis[node] = 1;
    for (auto child : adj[node]) {
      if (child == par) continue;
      dfs1(dfs1, child, node);
    }
  };
  fo(i, n) {
    if (!vis[i] && adj[i].size() <= 1) {
      path.clear();
      dfs1(dfs1, i, -1);
      paths.pb(path);
    }
  }
  debug(paths);
  for (auto p : paths) {
    for (auto x : p) {
      cout << 1 << " " << x + 1 << '\n';
    }
  }
}

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1;
  cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
