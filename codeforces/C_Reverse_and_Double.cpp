// Solution by Abhi Jain for the problem https://codeforces.com/contest/2280/problem/C
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

constexpr int MOD = 1000000007;
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

void solve() {
  int n;
  cin >> n;
  vi a(n);
  read(a, n);

  int ans = -1;
  int mxi = -1;
  vi diff(n - 1);

  for (int i = 1; i < n; i++) {
    diff[i - 1] = abs(a[i] - a[i - 1]);
    if (ans < diff[i - 1]) {
      ans = diff[i - 1];
      mxi = i;
    }
  }

  vi pref(n - 1), suff(n - 1);
  pref[0] = diff[0];
  for (int i = 1; i < n - 1; i++) pref[i] = max(pref[i - 1], diff[i]);
  suff[n - 2] = diff[n - 2];
  for (int i = n - 3; i >= 0; i--) suff[i] = max(suff[i + 1], diff[i]);

  int running = 0;
  for (int j = mxi; j < n; j++) {
    if (j > mxi) running = max(running, 2 * diff[j - 1]);
    int curr = (mxi >= 2) ? pref[mxi - 2] : 0;
    curr = max(curr, running);
    curr = max(curr, (j < n - 2) ? suff[j + 1] : 0);
    curr = max(curr, abs(a[mxi - 1] - 2 * a[j]));
    if (j < n - 1) curr = max(curr, abs(2 * a[mxi] - a[j + 1]));
    ans = min(ans, curr);
  }
  running = 0;
  for (int j = mxi - 1; j >= 0; j--) {
    if (j < mxi - 1) running = max(running, 2 * diff[j]);
    int curr = (j >= 2) ? pref[j - 2] : 0;
    curr = max(curr, running);
    curr = max(curr, (mxi < n - 1) ? suff[mxi] : 0);
    if (j > 0) curr = max(curr, abs(a[j - 1] - 2 * a[mxi - 1]));
    curr = max(curr, abs(2 * a[j] - a[mxi]));
    ans = min(ans, curr);
  }
  cout << ans << endl;
}