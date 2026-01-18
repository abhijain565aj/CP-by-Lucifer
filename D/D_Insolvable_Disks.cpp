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
  int n;
  cin >> n;
  vi x(n);
  fo(i, n) cin >> x[i];

  if (n == 1) {
    cout << 0 << endl;
    return;
  }
  int res = 1;
  for (int i = 0; i < n;) {
    int r = 0, lo = 0, hi = INF;
    int mo = 0, me = INF;
    bool odd = true;
    i++;

    for (; i < n; i++) {
      int g = x[i] - x[i - 1];
      int adj = g - r;
      bool next_odd = !odd;
      int nlo = lo, nhi = hi;

      if (next_odd)
        nlo = max(nlo, -adj);
      else
        nhi = min(nhi, adj);

      if (nlo >= nhi) break;

      int extra = 0;
      int pm = next_odd ? mo : me;
      if (pm < INF) extra = max(0LL, adj - pm);

      int next_gap = (i + 1 < n) ? (x[i + 1] - x[i]) : 0;
      if (extra >= next_gap) break;

      // update block
      r = adj;
      lo = nlo;
      hi = nhi;
      if (next_odd)
        mo = min(mo, adj);
      else
        me = min(me, adj);
      odd = next_odd;
      res++;
    }
  }

  cout << res << '\n';
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
