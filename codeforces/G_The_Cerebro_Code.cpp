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
int n = 2000;
int l, r = 2000;
vvi dp(n, vi(r, -1));
vvi dpt(n, vi(r, -1));
vvi dpb(n, vi(r, -1));
int fnt(int, int);
int fnb(int, int);
int fn(int ind, int val) {
  if (val < 0 || val >= r) return 0;
  if (ind >= n) return 1;
  debug("fn", ind, val);
  if (dp[ind][val] != -1) return dp[ind][val];
  if (ind & 1) {
    return dp[ind][val] = fnt(ind + 1, val - 1);
  } else {
    return dp[ind][val] = fnb(ind + 1, val + 1);
  }
}
int fnt(int ind, int val) {
  debug("t", ind, val);
  if (val < 0) return 0;
  if (ind >= n) return 1;
  if (dpt[ind][val] != -1) return dpt[ind][val];
  return dpt[ind][val] = (fnt(ind, val - 1) + fn(ind, val)) % MOD;
}
int fnb(int ind, int val) {
  debug("b", ind, val);
  if (val >= r) return 0;
  if (ind >= n) return 1;
  if (dpb[ind][val] != -1) return dpb[ind][val];
  return dpb[ind][val] = (fnb(ind, val + 1) + fn(ind, val)) % MOD;
}
signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  cin >> n >> l >> r;
  r = r - l + 1;
  cout << (2 * fnt(0, r)) % MOD;
}
