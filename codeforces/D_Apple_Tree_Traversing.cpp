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
  int n;
  cin >> n;
  vector<set<int>> adj(n);
  fo(i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  vector<array<int, 3>> ans;
  map<int, int> dist;
  map<int, int> par;
  queue<int> q;
  auto remove = [&](auto&& remove, int u) -> void {
    dist.clear();
    par.clear();
    auto dfs = [&](auto&& dfs, int u, int p) -> void {
      par[u] = p;
      for (auto c : adj[u]) {
        if (c == p) continue;
        dist[c] = dist[u] + 1;
        dfs(dfs, c, u);
      }
    };
    dfs(dfs, u, -1);
    int mxd = 0, mxi = u;
    for (auto [nd, d] : dist)
      if (d > mxd)
        mxd = d, mxi = nd;
      else if (d == mxd)
        mxi = max(mxi, nd);

    dist.clear();
    par.clear();
    dfs(dfs, mxi, -1);
    int mxd1 = 0, mxi1 = mxi;
    for (auto [nd, d] : dist)
      if (d > mxd1)
        mxd1 = d, mxi1 = nd;
      else if (d == mxd1)
        mxi1 = max(mxi1, nd);

    vi diameter;
    diameter.pb(mxi1);
    int curr = mxi1;
    while (par[curr] != -1) {
      curr = par[curr];
      diameter.pb(curr);
    }
    debug(diameter);
    set<int> dm(all(diameter));
    for (auto pt : diameter) {
      for (auto nd : adj[pt]) {
        adj[nd].erase(pt);
        if (dm.find(nd) == dm.end())
          q.push(nd);
      }
    }
    ans.pb({mxd1 + 1, max(mxi1, mxi), min(mxi1, mxi)});
  };
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    remove(remove, u);
  }
  sortall(ans);
  reverse(all(ans));
  for (auto [i, j, k] : ans) {
    cout << i << " " << j + 1 << " " << k + 1 << " ";
  }
  cout << endl;
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
