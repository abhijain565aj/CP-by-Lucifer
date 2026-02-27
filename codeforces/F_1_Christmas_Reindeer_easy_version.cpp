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
int N = 1001;
int C = 61;
constexpr int INF = 1e18;
vi fac(N);
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
int nCr(int n, int r) {
  if (r < 0 || n < 0 || r > n)
    return n;
  else
    return mul(fac[n], mul(inv(fac[n - r]), inv(fac[r])));
}

signed main() {
  fastio;
  fac[0] = 1;
  fo1(i, 1, N) fac[i] = (i * fac[i - 1]) % MOD;
  //   Error_file("0_Error.txt");

  int n, m;
  cin >> n >> m;
  vi c(C);
  fo(i, n) {
    int x;
    cin >> x;
    c[x]++;
  }
  auto slv = [&](long long X) -> long long {
    static unordered_map<long long, long long> dp[62], ndp[62];

    for (int k = 0; k <= 61; k++) dp[k].clear();
    dp[0][0] = 1;

    for (int i = 0; i < C; i++) {
      for (int cnti = 0; cnti < c[i]; cnti++) {
        for (int k = 0; k <= 61; k++) ndp[k].clear();

        for (int k = 0; k <= 61; k++) {
          for (auto& [cap, ways] : dp[k]) {
            // skip this reindeer
            ndp[k][cap] = add(ndp[k][cap], ways);

            // take this reindeer
            if (k + 1 <= 61) {
              long long ncap;
              if (k == 0) {
                ncap = (1LL << i);  // FIRST PICK (CRITICAL FIX)
              } else {
                ncap = (cap + (1LL << i)) >> 1;
              }
              if (ncap > X) ncap = X;
              ndp[k + 1][ncap] = add(ndp[k + 1][ncap], ways);
            }
          }
        }

        for (int k = 0; k <= 61; k++) dp[k].swap(ndp[k]);
      }
    }

    long long ans = 0;
    for (int k = 1; k <= 61; k++) {
      if (dp[k].count(X))
        ans = add(ans, dp[k][X]);
    }
    return ans;
  };

  fo(i, m) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      c[x]++, n++;
    } else if (t == 2) {
      c[x]--, n--;
    } else {
      cout << slv(x) << endl;
    }
  }
}
