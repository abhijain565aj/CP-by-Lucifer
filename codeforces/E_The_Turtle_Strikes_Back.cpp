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
  vvi a(n + 1, vi(m + 1));
  fo(i, n) fo(j, m) cin >> a[i + 1][j + 1];

  vvi dp(n + 2, vi(m + 2, -INF));
  dp[n][m] = a[n][m];
  re1(i, n, 1) re1(j, m, 1) {
    if (i == n && j == m) continue;
    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]) + a[i][j];
  }

  vvi dp2(n + 2, vi(m + 2, -INF));
  dp2[1][1] = a[1][1];
  fo1(i, 1, n + 1) fo1(j, 1, m + 1) {
    if (i == 1 && j == 1) continue;
    dp2[i][j] = max(dp2[i - 1][j], dp2[i][j - 1]) + a[i][j];
  }

  debug(dp, dp2);

  vvi dp3(n + 2, vi(m + 2)), dp4(n + 2, vi(m + 2));
  fo1(i, 1, n + 1) fo1(j, 1, m + 1) {
    dp3[i][j] = dp[i][j] + dp2[i][j - 1];
    dp4[i][j] = dp[i][j] + dp2[i - 1][j];
  }

  vvi mxdp3(n + 2, vi(m + 2, -INF)), mxdp4(n + 2, vi(m + 2, -INF));
  re1(i, n, 1) re1(j, m, 1) {
    mxdp3[i][j] = max(mxdp3[i + 1][j], dp3[i][j]);
    mxdp4[i][j] = max(mxdp4[i][j + 1], dp4[i][j]);
  }

  int ans = INF;
  fo1(i, 1, n + 1) fo1(j, 1, m + 1) {
    int curr = dp[i][j] + dp2[i][j] - 3 * a[i][j];
    curr = max({curr, mxdp3[i + 1][j], mxdp4[i][j + 1]});
    ans = min(ans, curr);
  }
  cout << ans << endl;
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
