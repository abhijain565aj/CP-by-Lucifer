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

// Modular Arithmetic
ll mod(ll a, ll m = MOD) {
  return (a % m + m) % m;
}
ll add(ll a, ll b, ll m = MOD) {
  return mod(a + b, m);
}
ll sub(ll a, ll b, ll m = MOD) {
  return mod(a - b, m);
}
ll mul(ll a, ll b, ll m = MOD) {
  return mod(a * b, m);
}
ll power(ll a, ll b, ll m = MOD) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res = mul(res, a, m);
    a = mul(a, a, m);
    b >>= 1;
  }
  return res;
}
ll inv(ll a, ll m = MOD) {
  return power(a, m - 2, m);
}
ll divide(ll a, ll b, ll m = MOD) {
  return mul(a, inv(b, m), m);
}

void solve() {
  int n;
  cin >> n;
  vi a(n);
  read(a, n);
  vi pr(n);
  read(pr, n);
  fo(i, n) pr[i] = divide(pr[i], 1e4);
  int sz = 1 << 10;
  vi dp(sz);
  fo(i, n) {
    if (i == 0) {
      dp[a[i]] = pr[i];
      dp[0] = sub(1, pr[i]);
      continue;
    }
    auto v = dp;
    dp.assign(sz, 0);
    fo(j, sz) {
      dp[j ^ a[i]] = add(dp[j ^ a[i]], mul(v[j], pr[i]));
      dp[j] = add(dp[j], mul(v[j], sub(1, pr[i])));
    }
    debug(dp);
  }
  auto ans = 0;
  fo(i, 1024) {
    ans = add(ans, mul(i * i, dp[i]));
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
