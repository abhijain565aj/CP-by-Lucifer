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
  int n, m;
  cin >> n >> m;
  vi par(n, -1);
  fo(i, n - 1) par[i] = i + 1;
  fo(i, m) {
    int u, v;
    cin >> u >> v;
    par[u - 1] = max(par[u - 1], v - 1);
  }
  vvi adj(n);
  fo(i, n) if (par[i] != -1) {
    adj[par[i]].pb(i);
  }
  vi st(n), dist(n);
  int lc = 0;
  vector<map<int, int>> mp(n);
  auto dfs = [&](int u, int p, auto&& dfs) -> void {
    st[u] = 1;
    mp[u][dist[u]]++;
    for (auto v : adj[u]) {
      if (v == p) continue;
      dist[v] = dist[u] + 1;
      dfs(v, u, dfs);
      st[u] += st[v];

      if (mp[v].size() > mp[u].size()) swap(mp[u], mp[v]);
      for (auto pr : mp[v]) {
        lc += dist[u] * pr.S * mp[u][pr.F];
        mp[u][pr.F] += pr.S;
      }
    }
  };
  dfs(n - 1, -1, dfs);
  fo(i, n) {
    int curr = (st[i] - 1) * 2;
    for (auto v : adj[i]) {
      curr += st[v] * (st[i] - st[v] - 1);
    }
    lc += curr / 2 * dist[i];
  }

  vi de;
  fo(i, n) de.pb(dist[i]);
  sortall(de);

  int sum = 0;
  fo(i, n) {
    int more = lower_bound(all(de), dist[i]) - de.begin();
    sum += dist[i] * (n - more - 1);
  }
  debug(sum, lc);
  cout << sum - lc << endl;
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
