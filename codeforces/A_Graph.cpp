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
  int n, m;
  cin >> n >> m;
  vector<vector<pii>> adj(n);
  fo(i, m) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].pb({v, w});
    adj[v].pb({u, w});
  }
  vi vis(n, 0);
  v(pii) dist(n, {0, 0});
  int comp = 1;
  auto dfs = [&](auto&& self, int u) -> void {
    vis[u] = comp;
    for (auto& [v, w] : adj[u]) {
      if (!vis[v]) {
        dist[v] = {-dist[u].F, w - dist[u].S};
        self(self, v);
      }
    }
  };
  fo(i, n) {
    if (!vis[i]) {
      dist[i] = {1, 0};
      dfs(dfs, i);
      comp++;
    }
  }
  debug(vis);
  debug(dist);
  bool check = true;
  vb has(comp, false);
  vi oldans(comp, -1);
  fo(i, n) for (auto& [v, w] : adj[i]) {
    if (dist[i].F + dist[v].F != 0) {
      debug(i, v, w);
      int val = w - (dist[i].S + dist[v].S);
      if (dist[i].F == -1) val = -val;
      int c = vis[i];
      if (has[c] && oldans[c] != val) {
        check = false;
        break;
      }
      has[c] = true;
      oldans[c] = val;
    } else if (dist[i].S + dist[v].S != w) {
      check = false;
      break;
    }
  }
  debug(oldans);
  YN(check);
  if (!check) return 0;
  map<int, vector<pair<double, double>>> mp;
  fo(i, n) mp[vis[i]].pb(dist[i]);
  debug(mp);
  auto val = [&](int c) -> double {
    vector<double> vals;
    for (auto& [a, b] : mp[c]) {
      vals.pb((double)(-a * b));
    }
    debug(c, vals);
    sortall(vals);
    return vals[vals.size() / 2];
  };
  vector<double> ans(comp, 0.0);
  fo1(i, 1, comp) {
    if (has[i])
      ans[i] = oldans[i] / 2.0;
    else
      ans[i] = val(i);
  }
  cout << fixed << setprecision(10);
  for (int i = 0; i < n; i++) {
    cout << (double)dist[i].F * ans[vis[i]] + (double)dist[i].S << (i == n - 1 ? '\n' : ' ');
  }
}
