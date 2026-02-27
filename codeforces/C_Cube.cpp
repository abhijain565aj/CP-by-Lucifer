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

// #define int long long
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
constexpr int INF = 1e9;

int n = 12;
int sz = 1 << n;
v(v(vi)) a(n, vvi(n, vi(n)));
v(vvi) dp(n, vvi(sz, vi(sz, INF)));

int fn(int i, int j, int k) {
  if (i < 0) return 0;
  if (dp[i][j][k] != INF) return dp[i][j][k];
  int ans = INF;
  fo(j1, n) fo(k1, n) {
    if (((1 << j1) & j) && ((1 << k1) & k)) {
      ans = min(ans, a[i][j1][k1] + fn(i - 1, j ^ (1 << j1), k ^ (1 << k1)));
    }
  }
  return dp[i][j][k] = ans;
};

signed main() {
  fastio;
  cin >> n;
  sz = 1 << n;
  fo(i, n) fo(j, n) fo(k, n) cin >> a[i][j][k];
  debug(a);
  cout << fn(n - 1, sz - 1, sz - 1) << endl;
  // fo(i, n) fo(j, sz) fo(k, sz) {
  //   int cnt1 = __builtin_popcount(j), cnt2 = __builtin_popcount(k);
  //   if (cnt1 != i + 1 && cnt2 != i + 1) dp[i][j][k] = 0;
  //   int ans = INF;
  //   fo(j1, n) fo(k1, n) {
  //     if (((1 << j1) & j) && ((1 << k1) & k)) {
  //       ans = min(ans, a[i][j1][k1] + (i > 0 ? dp[i - 1][j ^ (1 << j1)][k ^ (1 << k1)] : 0));
  //     }
  //   }
  //   dp[i][j][k] = ans;
  // }
  // cout << dp[n - 1][sz - 1][sz - 1] << endl;
}
