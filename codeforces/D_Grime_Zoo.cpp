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

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  string s;
  cin >> s;
  int x, y;
  cin >> x >> y;
  int n = s.size();
  int ans = INF;
  int fix = 0;

  vi pref(n), suf(n);
  fo(i, n) pref[i] = (s[i] == '0') + (i > 0 ? pref[i - 1] : 0);
  re(i, n) suf[i] = (s[i] == '0') + (i < n - 1 ? suf[i + 1] : 0);
  vi pref1(n), suf1(n);
  fo(i, n) pref1[i] = (s[i] == '1') + (i > 0 ? pref1[i - 1] : 0);
  re(i, n) suf1[i] = (s[i] == '1') + (i < n - 1 ? suf1[i + 1] : 0);
  vi prefq(n), sufq(n);
  fo(i, n) prefq[i] = (s[i] == '?') + (i > 0 ? prefq[i - 1] : 0);
  re(i, n) sufq[i] = (s[i] == '?') + (i < n - 1 ? sufq[i + 1] : 0);

  fo(i, n) if (s[i] == '1') fix += pref[i] * x + suf[i] * y;

  int curr = fix;
  fo(i, n) if (s[i] == '?') curr += pref[i] * x + suf[i] * y;
  int curr1 = curr;
  ans = min(ans, curr);
  if (x >= y) {
    re(i, n) {
      if (s[i] == '?') {
        curr -= suf[i] * y + pref[i] * x;
        curr += suf1[i] * x + pref1[i] * y;
        curr -= (sufq[i] - 1) * y;
        curr += (prefq[i] - 1) * y;
      }
      ans = min(ans, curr);
    }
  }
  curr = curr1;
  if (y >= x) {
    fo(i, n) {
      if (s[i] == '?') {
        curr -= suf[i] * y + pref[i] * x;
        curr += suf1[i] * x + pref1[i] * y;
        curr -= (prefq[i] - 1) * x;
        curr += (sufq[i] - 1) * x;
      }
      ans = min(ans, curr);
    }
  }
  cout << ans << endl;
}
