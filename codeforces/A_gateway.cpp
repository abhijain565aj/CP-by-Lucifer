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
  v(v(pii)) adj(n);
  fo(i, m) {
    int u, v;
    char C;
    cin >> u >> v >> C;
    u--, v--;
    int c = (C == 'R') ? +1 : -1;
    adj[u].pb({v, c});
    adj[v].pb({u, c});
  }
  int LIM = m;  // delta ∈ [-m, +m]

  vvi dist(n, vi(2 * LIM + 1, -1));
  queue<pii> q;
  // (node, delta)

  dist[0][LIM] = 0;
  q.push({0, 0});

  while (!q.empty()) {
    auto [u, delta] = q.front();
    q.pop();

    int d = dist[u][delta + LIM];

    if (u == n - 1 && delta == 0) {
      cout << d << "\n";
      return 0;
    }

    for (auto [v, c] : adj[u]) {
      int ndelta = delta + c;
      if (ndelta < -LIM || ndelta > LIM) continue;
      if (dist[v][ndelta + LIM] != -1) continue;

      dist[v][ndelta + LIM] = d + 1;
      q.push({v, ndelta});
    }
  }

  cout << -1 << "\n";
}
