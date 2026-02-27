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
  int n, m, k;
  cin >> n >> m >> k;
  vvi adj(n);
  fo(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  set<array<int, 3>> A;
  fo(i, k) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--, c--;
    A.insert({a, b, c});
  }
  v(v(pii)) mp(n+1, v(pii)(n, {INF, -1}));
  mp[n][0] = {0, -1};
  queue<pii> q;
  q.push({n, 0});
  while (!q.empty()) {  // n*m*log(k)
    auto [pr, nd] = q.front();
    q.pop();
    for (auto nbr : adj[nd]) {
      if (A.find({pr, nd, nbr}) != A.end()) continue;
      if (mp[nd][nbr].F > mp[pr][nd].F + 1) {
        mp[nd][nbr] = {mp[pr][nd].F + 1, pr};
        q.push({nd, nbr});
      }
    }
  }
  int ans = INF, pr = -1;
  fo(i, n - 1) {
    ans = min(ans, mp[i][n - 1].F);
    if (ans == mp[i][n - 1].F) pr = i;
  }
  if (ans == INF) {
    cout << -1 << endl;
    return 0;
  }
  vi path;
  path.pb(n);
  int nd = n - 1;
  while (pr != n) {
    path.pb(pr + 1);
    auto npr = mp[pr][nd].S;
    nd = pr;
    pr = npr;
  }
  reverse(all(path));
  cout << ans << endl;
  print_space(path, ans + 1);
}
