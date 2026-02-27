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
constexpr int INF = 1e18;

void solve();

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1;
  // cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vvi adj(n);
  fo(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  using tup = array<int, 3>;
  vector<tup> queries(q);
  fo(i, q) {
    int u, v, k;
    cin >> u >> v >> k;
    u--, v--;
    queries[i] = {u, v, k};
  }
  vi init(n, -1);
  vi last(n, -1);
  vi vis(n, 0);
  vi par(n, -1);
  int time = 0;
  vb articulation(n, false);
  auto dfs = [&](auto&& dfs, int u) -> void {
    debug(u);
    vis[u] = 1;
    init[u] = last[u] = time++;
    for (int v : adj[u]) {
      if (v == par[u]) continue;
      if (!vis[v]) {
        par[v] = u;
        dfs(dfs, v);
        if (last[v] > init[u] && adj[u].size() > 1) articulation[u] = true;
        last[u] = min(last[u], last[v]);
      } else {
        if (last[v] > init[u] && adj[u].size() > 1) articulation[u] = true;
        last[u] = min(last[u], last[v]);
      }
    }
    if (par[u] != -1 && adj[u].size() > 1 && last[u] > init[par[u]])
      articulation[u] = true;
  };
  dfs(dfs, 0);
  fo(i, n) if (articulation[i]) cout << i + 1 << " ";


}
