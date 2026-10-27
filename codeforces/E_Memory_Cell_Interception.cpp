// Solution by Abhi Jain for the problem https://codeforces.com/contest/2272/problem/E
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

  for(int _t=0; _t<_testCases; _t++) {
    Test(_t + 1);
    solve();
  }
}

void precompute() {
}

void solve() {
  int n, m;
  cin >> n >> m;
  string s,t;
  cin>>s>>t;
  auto fn = [&]() {
    // intervals between consecutive W's in t
    vi pos_w;
    for (int i = 0; i < m; i++)
      if (t[i] == 'W') pos_w.pb(i);
    vi int_l;
    for (int i = 1; i < sz(pos_w); i++) {
      int_l.pb(pos_w[i] - pos_w[i - 1]);
    }
    sort(all(int_l));
    vi pref(sz(int_l) + 1);
    for (int i = 0; i < sz(int_l); i++) {
      pref[i + 1] = pref[i] + int_l[i];
    }
    int wb = false;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'W') {
        wb = true;
      } else if (wb) {
        cout << m + 1 << " ";
      } else {
        int ans = 1;
        if (!pos_w.empty()) {
          int len = i + 1;
          int p = upper_bound(all(int_l), len) - int_l.begin();
          ans = 1 + len + pref[p] + (sz(int_l) - p) * len;
        }
        cout << ans << " ";
      }
    }
    cout << endl;
  };
  fn();
  swap(s,t);
  swap(n,m);
  fn();
}
