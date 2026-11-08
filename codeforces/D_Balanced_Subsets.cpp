// Solution by Abhi Jain for the problem https://codeforces.com/contest/2280/problem/D
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "./Templates/DEBUG.cpp"
#define local true
#else
#define debug(...)
#define Test(tt)
#define local false
#endif

#define int long long

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define v(x) vector<x>

#define YN(possible) cout << ((possible) ? "YES" : "NO") << endl;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back

#define read(a, n) \
  for (int i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) \
  for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');

constexpr int MOD = 998244353;
constexpr int N = 1e5 + 1;
constexpr int INF = 1e18;

void solve();
void precompute();

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  precompute();

  int _testCases = 1;
  cin >> _testCases;

  for (int _t = 0; _t < _testCases; _t++) {
    Test(_t + 1);
    solve();
  }
}

void precompute() {}

// Modular Arithmetic
int mod(int a, int m = MOD) {
  return (a % m + m) % m;
}
int add(int a, int b, int m = MOD) {
  return mod(a + b, m);
}
int sub(int a, int b, int m = MOD) {
  return mod(a - b, m);
}
int mul(int a, int b, int m = MOD) {
  return mod(a * b, m);
}
int power(int a, int b, int m = MOD) {
  int res = 1;
  while (b) {
    if (b & 1) res = mul(res, a, m);
    a = mul(a, a, m);
    b >>= 1;
  }
  return res;
}
int inv(int a, int m = MOD) {
  return power(a, m - 2, m);
}
int divide(int a, int b, int m = MOD) {
  return mul(a, inv(b, m), m);
}

void solve() {
  int n;
  cin >> n;
  vi a(n);
  read(a, n);
  vector<bool> exists(3 * n + 10, false);
  vvi dp(3 * n, vi(3, 0));
  for (int i = 0; i < n; i++) {
    exists[a[i] - 1] = true;
    for (int j = 0; j < 3; j++) dp[a[i] - 1][j] = -1;
  }
  map<int, array<int, 3>> t;
  t[0] = {1, 1, 0};
  t[1] = {1, 0, 1};
  t[2] = {0, 1, 1};
  auto fn = [&](auto&& fn, int x, int cs) -> int {
    if (dp[x][cs] != -1) {
      return dp[x][cs];
    }
    debug(x, cs);
    for (int j = 0; j < 3; j++) {
      if (t[cs][j] && !exists[x + j + 1]) return dp[x][cs] = 0;
    }
    debug(x, cs);
    if (cs == 0 || cs == 1) {
      dp[x][cs] = add(fn(fn, x + 1, cs + 1), 1);
    } else if (cs == 2) {
      dp[x][cs] = add(add(fn(fn, x + 2, 0), fn(fn, x + 2, 1)), 1);
    }
    return dp[x][cs];
  };
  int ans = add(n, mod((n * (n - 1)) / 2));
  for (int i = 0; i < 3 * n; i++)
    for (int cs = 0; cs < 3; cs++) {
      ans = add(ans, fn(fn, i, cs));
    };
  cout << ans << endl;
}