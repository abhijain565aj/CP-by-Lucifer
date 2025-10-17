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
constexpr int INF = 1e18;

void solve() {
  int n;
  cin >> n;
  vvi adj(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  int mx = 0;
  fo(i, n) mx = max(mx, (int)adj[i].size());
  if (mx <= 2) {
    cout << -1 << endl;
    return;
  }

  vi distance(n, -1);
  vi parent(n, -1);
  auto dfs = [&](auto&& dfs, int node) -> void {
    for (int neigh : adj[node]) {
      if (neigh == parent[node]) continue;
      distance[neigh] = distance[node] + 1;
      parent[neigh] = node;
      dfs(dfs, neigh);
    }
  };
  fo(i, n) if (adj[i].size() > 1) {
    distance[i] = 0;
    dfs(dfs, i);
    break;
  }
  int mxd = max_element(all(distance)) - distance.begin();
  parent.assign(n, -1);
  distance.assign(n, -1);
  dfs(dfs, mxd);

  vi diameter;
  int curr = max_element(all(distance)) - distance.begin();
  while (curr != -1) {
    diameter.pb(curr);
    curr = parent[curr];
  }
  debug(diameter);
  for (int i = 1; i < n - 1; i++) {
    for (int c : adj[diameter[i]]) {
      if (c != diameter[i - 1] && c != diameter[i + 1]) {
        cout << diameter[i - 1] + 1 << " " << diameter[i] + 1 << " " << c + 1 << endl;
        return;
      }
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
