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

constexpr int MOD = 998244353;
constexpr int N = 1e5 + 1;
constexpr int INF = 1e18;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<array<int, 3>, pii> mp;  // current_balance, ) on/off, ( count after on = count, length
  int ans = 0;
  mp[{0, 0, 0}] = {1, 0};
  fo(i, n) {
    debug(i, mp);
    map<array<int, 3>, pii> new_mp;
    for (auto [l, r] : mp) {
      auto [cb, on, cc] = l;
      auto [count, len] = r;
      new_mp[{cb, on, cc}].F += count;
      new_mp[{cb, on, cc}].S += len;
      if (s[i] == '(') {
        if (on) {
          new_mp[{cb + 1, on, min(cc + 1, 2ll)}].F += count;
          new_mp[{cb + 1, on, min(cc + 1, 2ll)}].S += len + count;
        } else {
          new_mp[{cb + 1, on, cc}].F += count;
          new_mp[{cb + 1, on, cc}].S += len + count;
        }
      } else {
        if (cb > 0) {
          new_mp[{cb - 1, 1, cc}].F += count;
          new_mp[{cb - 1, 1, cc}].S += len + count;
        }
      }
    }
    swap(mp, new_mp);
    for (auto& [l, r] : mp) {
      auto& [count, len] = r;
      count %= MOD;
      len %= MOD;
    }
  }
  for (auto [l, r] : mp) {
    auto [cb, on, cc] = l;
    auto [count, len] = r;
    if (cb == 0 && on && cc >= 2) ans = (ans + len - count * 2) % MOD;
  }
  cout << (ans + MOD) % MOD << endl;
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
