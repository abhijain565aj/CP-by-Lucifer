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

ll mod(ll a, ll m = MOD) {
  return (a % m + m) % m;
}
ll add(ll a, ll b, ll m = MOD) {
  return mod(a + b, m);
}
ll sub(ll a, ll b, ll m = MOD) {
  return mod(a - b, m);
}
ll mul(ll a, ll b, ll m = MOD) {
  return mod(a * b, m);
}
ll power(ll a, ll b, ll m = MOD) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res = mul(res, a, m);
    a = mul(a, a, m);
    b >>= 1;
  }
  return res;
}
ll inv(ll a, ll m = MOD) {
  return power(a, m - 2, m);
}
ll div(ll a, ll b, ll m = MOD) {
  return mul(a, inv(b, m), m);
}

void solve() {
  int n;
  cin >> n;
  vi a(n);
  read(a, n);

  map<int, int> freq;
  for (auto x : a) freq[x]++;
  int maxc = 0;
  for (auto p : freq) {
    if (p.S > maxc) {
      maxc = p.S;
    }
  }

  // 1 1 1 1 2 2 2 3 3 4
  // total = 2 * 3 * 4 * 5 = 120 - 1 (null) = 119
  // with 1 (max mod) all possible => 4 * 4 * 3 * 2 = 96
  // 8 = 3, 4, (3 4), 2, (2 2), (2 2 2), (3 3), (3 3 4)
  // 3 * 2 * 1 = 6 (each atleast 1)
  // 3*2 + 3*1 = 9
  // 4 * 3 * 2 = 24 - 1 = 23

  // Identity = all subset count >= max_amount
  // counting < min_amount
  vi dp(maxc, 0);
  dp[0] = 1;
  for (auto [p, f] : freq) {
    re(j, maxc) {
      if (j - f >= 0)
        dp[j] = add(dp[j], mul(dp[j - f], f));
    }
  }
  int total = 1;
  for (auto [p, f] : freq) {
    total = mul(total, (f + 1));
  }
  int np = 0;
  fo(i, maxc) {
    np = add(np, dp[i]);
  }
  debug(total, np);
  int ans = sub(total, np);
  cout << ans << endl;
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
