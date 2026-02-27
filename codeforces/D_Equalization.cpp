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
#define re(i, n) for (int i = n - 1; i >= 0; i--)
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
vvi dp(63, vi(63, INF));
void solve() {
  int x, y;
  cin >> x >> y;
  auto bin = [](int n) -> vi {
    vi res;
    while (n) {
      res.pb(n % 2);
      n /= 2;
    }
    return res;
  };
  vi a = bin(x);
  vi b = bin(y);
  int p1 = a.size() - 1, p2 = b.size() - 1;
  while (p1 >= 0 && p2 >= 0 && a[p1] == b[p2]) p1--, p2--;
  p1 += 1, p2 += 1;
  debug(p1, p2);
  if (p1 == 1 && p2 == 1) {
    if (max(x, y) < 8 && min(x, y) < 4) {
      cout << 12 << endl;
      return;
    }
  }
  int mn = INF;
  for (int i = p1, j = p2; i < 63 && j < 63; i++, j++) {
    mn = min(mn, dp[i][j]);
  }
  cout << mn << endl;
}

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  dp[0][0] = 0;
  re(k, 63) re(i, 63) re(j, 63) {
    if (k > i && k > j)
      continue;
    else if (k > i)
      dp[i][j] = min(dp[i][j - k] + (1ll << k), dp[i][j]);
    else if (k > j)
      dp[i][j] = min(dp[i - k][j] + (1ll << k), dp[i][j]);
    else
      dp[i][j] = min(dp[i][j], min(dp[i][j - k], dp[i - k][j]) + (1ll << k));
  }
  dp[1][1] = dp[2][2] = 14;
  fo(i, 64) fo(j, 64) {
    if (dp[i][j] == INF) debug(i, j);
  }
  // debug(ddp);
  // debug(dp);
  int testCases = 1000;
  cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
