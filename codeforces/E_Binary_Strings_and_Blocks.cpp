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
// #include "./0_debug.cpp"
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

#define fo(i, n) for (ll i = 0; i < n; i++)
#define re(i, n) for (ll i = n - 1; i >= 0; i--)
#define fo1(i, a, b) for (ll i = a; i < b; i++)
#define re1(i, a, b) for (ll i = a; i >= b; i--)

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

constexpr ll MOD = 998244353;
constexpr ll N = 3e5 + 10;
constexpr ll INF = 1e18;

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

vi Fac(N), iFac(N);
ll nCr(ll n, ll r) {
  if (r > n || r < 0)
    return 0;
  return mul(Fac[n], mul(iFac[r], iFac[n - r]));
}

void solve() {
  int n, m;
  cin >> n >> m;
  v(pii) a(m);
  fo(i, m) cin >> a[i].F >> a[i].S;

  vi need(n, 0);  // need[r-1] = max l for intervals ending at r

  for (auto& pr : a) {
    int l = pr.F;
    int r = pr.S;
    need[r - 1] = max(need[r - 1], l);
  }

  vi dp(n, 0);
  dp[0] = 1;
  int S = 1;
  int live = 0;

  for (int r = 1; r < n; ++r) {
    dp[r] = mod(S);

    int nlive = max(live, need[r]);

    ll removed = 0;
    for (int t = live; t < nlive; ++t) {
      if (dp[t] != 0) {
        removed = add(removed, dp[t]);
        dp[t] = 0;
      }
    }
    removed %= MOD;
    live = nlive;
    S = mod(sub(2 * S, removed));
  }

  cout << mul(2, S) << '\n';
}

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1000;
  Fac[0] = 1;
  fo1(i, 1, N) Fac[i] = mul(Fac[i - 1], i);
  iFac[N - 1] = inv(Fac[N - 1]);
  re1(i, N - 2, 0) iFac[i] = mul(iFac[i + 1], i + 1);
  cin >> testCases;
  fo(tt, testCases) {
    // Test(tt + 1);
    solve();
  }
}
