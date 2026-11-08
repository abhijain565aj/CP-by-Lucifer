// Solution by Abhi Jain for the problem https://cses.fi/problemset/task/3413
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
constexpr int N = 3005;
constexpr int INF = 1e18;

void solve();
void precompute();

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  precompute();

  int _testCases = 1;
  // cin >> _testCases;

  for (int _t = 0; _t < _testCases; _t++) {
    Test(_t + 1);
    solve();
  }
}

void precompute() {}
string s[N];
int up[N][N], lef[N][N], square[N][N];
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int c = 0; c < k; c++) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s[i][j] - 'A' == c) {
          up[i + 1][j + 1] = up[i][j + 1] + 1;
          lef[i + 1][j + 1] = lef[i + 1][j] + 1;
          square[i + 1][j + 1] = min({square[i][j], up[i][j + 1], lef[i + 1][j]}) + 1;
          ans += square[i + 1][j + 1];
        } else {
          up[i + 1][j + 1] = lef[i + 1][j + 1] = square[i + 1][j + 1] = 0;
        }
      }
    }
    cout << ans << "\n";
  }
}