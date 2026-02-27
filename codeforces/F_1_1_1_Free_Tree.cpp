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

void solve() {
  int n, q;
  cin >> n >> q;
  vi a(n);
  read(a, n);
  vector<array<int, 3>> edges(n - 1);
  vector<map<int, int>> adj(n);
  int ans = 0;
  for (auto& x : edges) {
    cin >> x[0] >> x[1] >> x[2];
    x[0]--, x[1]--;
    if (a[x[0]] != a[x[1]]) ans += x[2];
    adj[x[0]][x[1]] = x[2];
    adj[x[1]][x[0]] = x[2];
  }
  vi parent(n, -1);
  vector<map<int, int>> mp(n);
  auto dfs = [&](auto&& dfs, int u) -> void {
    for (auto [v, w] : adj[u]) {
      if (v == parent[u]) continue;
      parent[v] = u;
      dfs(dfs, v);
      mp[u][a[v]] += w;
    }
  };
  dfs(dfs, 0);
  while (q--) {
    int v, c;
    cin >> v >> c;
    v--;
    int oldc = a[v];
    a[v] = c;
    if (oldc == c) {
      cout << ans << endl;
      continue;
    }
    int p = parent[v];
    if (p != -1) {
      mp[p][oldc] -= adj[p][v];
      mp[p][a[v]] += adj[p][v];
      if (oldc == a[p])
        ans += adj[p][v];
      else if (c == a[p])
        ans -= adj[p][v];
    }
    ans += mp[v][oldc] - mp[v][a[v]];
    cout << ans << endl;
  }
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
