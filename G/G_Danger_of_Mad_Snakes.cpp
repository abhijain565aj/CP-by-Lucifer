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
#define fo1(i, a, b) for (int i = a; i < b; i++)
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
constexpr int N = 2e3 + 1;
constexpr int INF = 1e18;

vi fac(N);
// Modular Arithmetic
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
ll divide(ll a, ll b, ll m = MOD) {
  return mul(a, inv(b, m), m);
}
ll nCr(int n, int r) {
  if (r > n) return 0;
  if (r < 0) return 0;
  if (r == 0 || r == n) return 1;
  return divide(fac[n], mul(fac[r], fac[n - r]));
}

signed main() {
  fastio;
  fac[0] = 1;
  fo1(i, 1, N) fac[i] = (fac[i - 1] * i) % MOD;
  //   Error_file("0_Error.txt");
  int n, m, r;
  cin >> n >> m >> r;
  vector<array<int, 3>> s(n);
  for (auto& x : s) cin >> x[0] >> x[1] >> x[2];
  vector<bitset<N>> a(n);
  fo(i, n) fo(j, n) {
    a[i][j] = max(abs(s[i][0] - s[j][0]), abs(s[i][1] - s[j][1])) <= r;
  }
  vi cnt(n);
  fo(i, n) cnt[i] = a[i].count();
  // debug(a);
  int ans = 0;
  int total = nCr(n, m);
  debug(total);
  // vvi arr(n, vi(n));
  fo(i, n) fo1(j, i, n) {
    auto ins = a[i] | a[j];
    int f1 = add(total, nCr(n - ins.count(), m));
    int f2 = add(nCr(n - cnt[i], m), nCr(n - cnt[j], m));
    int poss = sub(f1, f2);
    if (i != j) poss = mul(poss, 2);
    ans = add(ans, mul(poss, mul(s[i][2], s[j][2])));
    // debug(i, j, poss, ans);
  }
  cout << ans << endl;
}
