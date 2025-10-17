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
  int L, R;
  cin >> L >> R;
  int n = R - L + 1;
  vi a(n);
  fo(i, n) a[i] = L + i;
  auto b = a;
  auto msb = [](int x) {
    debug(x);
    while (x & (x - 1)) x &= (x - 1);
    return x;
  };
  auto solve = [&](auto&& solve, int l, int r) {
    debug(l, r);
    int diff = r - l + 1;
    if (diff <= 1) return;
    int mx = msb(diff);
    debug(l, r, mx);
    solve(solve, r - mx + 1, r);
    reverse(a.begin() + l - L, a.begin() + r - mx + 1 - L);
    map<int, int> mp;
    fo(i, n) mp[a[i]] = i;
    for (int i = l; i <= r - mx; i++) {
      if (mp.find(a[i - L] + mx) == mp.end()) continue;
      swap(a[i - L], a[mp[a[i - L] + mx]]);
    }
    debug(a);
  };
  solve(solve, L, R);
  // int delta = n;
  // for (int i = 0; delta != 0;) {
  //   int dx = msb(delta);
  //   reverse(a.begin() + i, a.begin() + i + dx);
  //   i += dx;
  //   delta -= dx;
  // }
  int ans = 0;
  fo(i, n) {
    ans += a[i] | b[i];
  }
  cout << ans << endl;
  print_space(a, n);
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
