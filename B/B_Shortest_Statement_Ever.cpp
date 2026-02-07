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
vi vec(int x) {
  vi v;
  while (x) {
    v.pb(x % 2);
    x /= 2;
  }
  return v;
}
void solve() {
  int x, y;
  cin >> x >> y;
  auto x1 = x, y1 = y;
  debug(vec(x), vec(y));
  int p = 0, q = 0;
  int last = 32;
  auto fn = [&](int x, int y, int last) -> pair<int, pii> {
    for (int i = last; i <= 31; i++) {
      x = x & (~(1 << i));
      y = y & (~(1 << i));
    }
    int lt = 1 << last;
    if (x > y) {
      return {lt - x, {lt, y}};
    } else {
      return {lt - y, {x, lt}};
    }
  };
  for (int i = 31; i >= 0; i--) {
    int xbit = x & (1 << i);
    int ybit = y & (1 << i);
    if (xbit && !ybit) {
      p |= xbit;
    } else if (!xbit && ybit) {
      q |= ybit;
    } else if (xbit && ybit) {
      int val1 = x + y - (1 << (i + 1)) + 1;
      int lt = 1 << last;
      debug(p, q, lt, x, y);
      auto [val2, pr] = fn(x1, y1, last);
      debug(val1, val2);
      if (val1 <= val2) {
        debug("1");
        p |= xbit;
        q |= (xbit - 1);
      } else {
        debug("2");
        for (int i = last; i >= 0; i--) {
          p = p & (~(1 << i));
          q = q & (~(1 << i));
        }
        debug(pr, p, q);
        p |= pr.F;
        q |= pr.S;
      }
      break;
    } else {
      last = i;
    }
    x = x & (~(1 << i));
    y = y & (~(1 << i));
  }
  // p = x, q = (~x) & y;
  // debug(p, q, xtra);
  int val = abs(x - p) + abs(y - q);
  debug(val);
  cout << p << " " << q << endl;
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
