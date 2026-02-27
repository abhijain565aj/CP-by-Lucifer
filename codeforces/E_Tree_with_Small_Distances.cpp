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

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int n;
  cin >> n;
  vvi adj(n);
  fo(i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  v(vi) dp(n, vi(3, -1));  // 0 - edgse on me // 1 - edge on parent, not on me // 2 - edge neither on me nor on parent => one child must be on 0;
  auto dfs = [&](auto&& self, int u, int t, int p) {
    if (dp[u][t] != -1) return dp[u][t];
    if (t == 2) {
      if (adj[0].size() == 0) return dp[u][t] = INF;
      int ans = 0;
      for (auto v : adj[u]) {
        if (v == p) continue;
        ans += min(1 + self(self, v, 0, u), self(self, v, 2, u));
      }
      int mn = INF;
      for (auto v : adj[u]) {
        if (v == p) continue;
        mn = min(mn, 1 + self(self, v, 0, u) - self(self, v, 2, u));
      }
      ans += max(0LL, mn);
      return dp[u][t] = ans;
    }
    int ans = 0;
    for (int v : adj[u]) {
      if (v == p) continue;
      if (t == 0)
        ans += min(self(self, v, 1, u), 1 + self(self, v, 0, u));
      else if (t == 1)
        ans += min(1 + self(self, v, 0, u), self(self, v, 2, u));
    }
    return dp[u][t] = ans;
  };
  int ans = 0;
  for (int v : adj[0]) {
    ans += dfs(dfs, v, 0, 0);
  }
  cout << ans << endl;
}
