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
constexpr int N = 401;
constexpr int INF = 1e18;
v(v(pii)) dp1(N, v(pii)(N, {-1, -1}));
v(v(pii)) dp2(N, v(pii)(N, {-1, -1}));
v(v(pii)) dp3(N, v(pii)(N, {-1, -1}));
v(v(pii)) dp4(N, v(pii)(N, {-1, -1}));
v(v(pii)) dp5(N, v(pii)(N, {-1, -1}));
// count, sum
pii solve2(int h, int w);
pii solve3(int h, int w);
pii solve4(int h, int w);
pii solve5(int h, int w);
pii solve1(int h, int w) {
  if (h < 0 || w < 0) return {0, 0};
  if (h == 0 || w == 0) return {1, 0};
  if (dp1[h][w].F != -1) return dp1[h][w];
  auto s2 = solve2(h - 2, w - 2);
  auto s3 = solve3(h - 2, w - 2);
  auto s4 = solve4(h - 2, w - 2);
  auto s5 = solve5(h - 2, w - 2);
  dp1[h][w].F = 1 + (h - 1) * (w - 1) * s2.F - (w - 1) * s3.F - (h - 1) * s4.F + s5.F;
  dp1[h][w].F = (dp1[h][w].F % MOD + MOD) % MOD;
  dp1[h][w].S = dp1[h][w].F * h * w + s2.S * (h - 1) * (w - 1) - s3.S * (w - 1) - s4.S * (h - 1) + s5.S;
  dp1[h][w].S = (dp1[h][w].S % MOD + MOD) % MOD;
  debug(h, w, dp1[h][w]);
  return dp1[h][w];
}
pii solve2(int h, int w) {
  if (h < 0 || w < 0) return {0, 0};
  if (h == 0 || w == 0) return {0, 0};
  if (dp2[h][w].F != -1) return dp2[h][w];
  int cnt = 0, sum = 0;
  fo1(i, 1, h + 1) {
    auto [count, s] = solve1(i, w);
    cnt = (cnt + count) % MOD;
    sum = (sum + s) % MOD;
  }
  fo1(i, 1, w) {
    auto [count, s] = solve1(h, i);
    cnt = (cnt + count) % MOD;
    sum = (sum + s) % MOD;
  }
  auto [count, s] = solve2(h - 1, w - 1);
  cnt = (cnt + count) % MOD;
  sum = (sum + s) % MOD;
  dp2[h][w] = {cnt % MOD, sum % MOD};
  debug(h, w, dp2[h][w]);
  return dp2[h][w];
}

pii solve3(int h, int w) {
  if (h < 0 || w < 0) return {0, 0};
  if (h == 0 || w == 0) return {0, 0};
  if (dp3[h][w].F != -1) return dp3[h][w];
  int cnt = 0, sum = 0;
  fo1(i, 1, h + 1) {
    auto [count, s] = solve1(i, w);
    count *= i, s *= i;
    cnt = (cnt + count) % MOD;
    sum = (sum + s) % MOD;
  }
  fo1(i, 1, w) {
    auto [count, s] = solve1(h, i);
    count *= h, s *= h;
    cnt = (cnt + count) % MOD;
    sum = (sum + s) % MOD;
  }
  auto [count, s] = solve3(h - 1, w - 1);
  cnt = (cnt + count) % MOD;
  sum = (sum + s) % MOD;
  dp3[h][w] = {cnt % MOD, sum % MOD};
  debug(h, w, dp3[h][w]);
  return dp3[h][w];
}

pii solve4(int h, int w) {
  if (h < 0 || w < 0) return {0, 0};
  if (h == 0 || w == 0) return {0, 0};
  if (dp4[h][w].F != -1) return dp4[h][w];
  int cnt = 0, sum = 0;
  fo1(i, 1, h + 1) {
    auto [count, s] = solve1(i, w);
    count *= w, s *= w;
    cnt = (cnt + count) % MOD;
    sum = (sum + s) % MOD;
  }
  fo1(i, 1, w) {
    auto [count, s] = solve1(h, i);
    count *= i, s *= i;
    cnt = (cnt + count) % MOD;
    sum = (sum + s) % MOD;
  }
  auto [count, s] = solve4(h - 1, w - 1);
  cnt = (cnt + count) % MOD;
  sum = (sum + s) % MOD;
  dp4[h][w] = {cnt % MOD, sum % MOD};
  debug(h, w, dp4[h][w]);
  return dp4[h][w];
}
pii solve5(int h, int w) {
  if (h < 0 || w < 0) return {0, 0};
  if (h == 0 || w == 0) return {0, 0};
  if (dp5[h][w].F != -1) return dp5[h][w];
  int cnt = 0, sum = 0;
  fo1(i, 1, h + 1) {
    auto [count, s] = solve1(i, w);
    count *= i * w, s *= i * w;
    cnt = (cnt + count) % MOD;
    sum = (sum + s) % MOD;
  }
  fo1(i, 1, w) {
    auto [count, s] = solve1(h, i);
    count *= h * i, s *= h * i;
    cnt = (cnt + count) % MOD;
    sum = (sum + s) % MOD;
  }
  auto [count, s] = solve5(h - 1, w - 1);
  cnt = (cnt + count) % MOD;
  sum = (sum + s) % MOD;
  dp5[h][w] = {cnt % MOD, sum % MOD};
  debug(h, w, dp5[h][w]);
  return dp5[h][w];
}
signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1;
  //   cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    int h, w;
    cin >> h >> w;
    cout << solve1(h, w).S;
  }
}
