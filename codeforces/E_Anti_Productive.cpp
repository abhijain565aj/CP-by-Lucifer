// Solution by Abhi Jain for the problem https://codeforces.com/contest/2280/problem/E
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

// void solve() {
//   int n, l;
//   cin >> n >> l;
//   vi a(n);
//   read(a, n);

//   sort(all(a));
//   map<int, int> dp;
//   auto fn = [&](int x) -> int {
//     if (dp.find(x) != dp.end()) return dp[x];
//     auto b = a;
//     int ans = 0;
//     for (int i = 0; i < n; i++) {
//       ans += max(b[i] - x, 0ll);
//       b[i] = min(b[i], x);
//     }
//     int idx = max_element(all(b)) - b.begin();
//     int v = (l - 1) / x;
//     for (int i = 0; i < n; i++)
//       if (idx != i) {
//         if (b[i] > v) {
//           ans += b[i] - v;
//           b[i] = v;
//         }
//       }
//     return dp[x] = ans;
//   };
//   // finding min x, concave
//   for (int i = 1; i <= l - 1; i++) {
//     debug(i, fn(i));
//   }
//   int ans = INF;
//   int l1 = 0, r = n - 1;
//   while (l1 < r) {
//     int m1 = l1 + (r - l1) / 3;
//     int m2 = r - (r - l1) / 3;
//     // in case of equality check both
//     ans = min(ans, min(fn(m1), fn(m2)));
//     while (m1 < m2 && fn(m1) == fn(m2)) {
//       m1 = (l1 + m1 - 1) / 2;
//       m2 = (r + m2 + 1) / 2;
//     }
//     if (v1 < v2) {
//       r = m2 - 1;
//     } else {
//       l1 = m1 + 1;
//     }
//   }
//   cout << min(fn(l1), fn(l - 1)) << endl;
// }

void solve() {
  int n, l;
  cin >> n >> l;
  l--;
  vi a(n);
  read(a, n);
  sort(all(a));

  vi pref(n + 1);
  for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];
  
  auto fn = [&](int x) -> int {
    int idx = upper_bound(all(a), x) - a.begin();
    return pref[n] - pref[idx] - (n - idx) * x;
  };
  
  int ans = accumulate(all(a), 0LL) - a.back();
  if (l == 1) {
    cout << min(ans, fn(1)) << endl;
    return;
  }
  // all <= sqrt(l)
  int s = sqrt(l);
  int mxA = a.back();
  ans = min(ans, fn(min(s,mxA)));

  // max element something and others < l/mx
  int mx = min(mxA, l);
  int x = s + 1;

  while (x <= mx) {
    int q = l / x;
    int r = min(mx, l / q);
    int cost = (mxA - r) + fn(q) - max(0LL, mxA - q);
    ans = min(ans, cost);
    x = r + 1;
  }

  cout << ans << endl;
}