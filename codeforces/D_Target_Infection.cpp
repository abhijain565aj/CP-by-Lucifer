// Solution by Abhi Jain for the problem https://codeforces.com/contest/2271/problem/D
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

#ifndef ONLINE_JUDGE
#include "./Templates/DEBUG.cpp"
#define local true
#else
#define debug(...)
#define Test(tt)
#define Error_file(x)
#define local false
#endif

#define int long long

#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vvi vector<vi>
#define pii pair<int, int>
#define v(x) vector<x>

#define fo(i, n) for (int i = 0; i < n; i++)
#define re(i, n) for (int i = n - 1; i >= 0; i--)

#define YN(possible) cout << ((possible) ? "YES" : "NO") << endl;
#define all(x) (x).begin(), (x).end()
#define sortall(x) sort(all(x))
#define F first
#define S second
#define pb push_back

#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

#define read(a, n) \
  for (int i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) \
  for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');

void file(string s = "") {
  if (local) {
    // freopen("error.txt", "w", stderr);
    // freopen("output.txt", "w", stdout);
    // freopen(("input" + s + ".txt").c_str(), "r", stdin);
    return;
  }
}

constexpr int MOD = 1000000007;
constexpr int N = 1e5 + 1;
constexpr int INF = 1e18;

void solve();
void precompute();

signed main() {
  fastio;
  file();
  precompute();

  int testCases = 1;
  cin >> testCases;

  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}

void precompute() {
}

void solve() {
  int n;
  int m, k;
  cin >> n >> m >> k;
  v(pii) iv(n);
  vi pref(n + 1);
  vi ls(n), rs(n);
  fo(i, n) {
      cin >> iv[i].F >> iv[i].S;
      ls[i] = iv[i].F;
      rs[i] = iv[i].S;
      pref[i + 1] = pref[i] + (iv[i].S - iv[i].F + 1);
  }

  // count infected in [x, x + m - 1]
  auto cnt = [&](int x) -> int {
      int l = x, r = x + m - 1;
      int i = lower_bound(rs.begin(), rs.end(), l) - rs.begin();
      int j = upper_bound(ls.begin(), ls.end(), r) - ls.begin() - 1;
      // debug(x,i,j);
      
      if (i > j) return 0LL;

      int res = pref[j + 1] - pref[i];
      res -= max(0LL, l - iv[i].F);
      res -= max(0LL, iv[j].S - r);
      return res;
  };

  auto bs = [&](int l, int r, bool inc) -> int {
      while (l <= r) {
          int mid = l + (r - l) / 2;
          int val = cnt(mid);

          if (val == k) return mid;

          if (inc) {
              if (val < k) l = mid + 1;
              else r = mid - 1;
          } else {
              if (val > k) l = mid + 1;
              else r = mid - 1;
          }
      }
      return -1LL;
  };

  if (k == 0) {
      cout << iv.back().S + 1 << '\n';
      return;
  }

  int prev = 0;
  fo(i, n) {
      auto [l, r] = iv[i];

      // inc [prev + 1, l]
      int L = prev + 1, R = l;
      int x = cnt(L), y = cnt(R);
      if (x <= k && k <= y) {
          cout << bs(L, R, true) << '\n';
          return;
      }

      // dec [l, r + 1]
      L = l, R = r + 1;
      x = cnt(L), y = cnt(R);
      if (x >= k && k >= y) {
          cout << bs(L, R, false) << '\n';
          return;
      }

      prev = r;
  }

  cout << -1 << '\n';
}
