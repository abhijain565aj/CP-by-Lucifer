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

// #define int long long
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
constexpr int N = 1e7 + 1;
constexpr int INF = 1e9 + 1;
// v(vi) primef(N);
vi primef(N);
vi primes;
ll power(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
void solve() {
  ll n, m;
  cin >> n >> m;
  int ans = 0;
  // map<int, int> left;
  // map<int, int> right;
  auto fn = [&](int x, int p) -> int {
    int res = 0;
    while (x > 0) {
      res += x / p;
      x /= p;
    }
    return res;
  };
  // set<int> primes_r;
  // auto prime_factors = [&](int x) -> void {
  //   while (x > 1) {
  //     int p = primef[x];
  //     primes_r.insert(p);
  //     while (x % p == 0) x /= p;
  //   }
  // };
  // auto add = [&](int x) {
  //   for (auto [p, c] : prime_factors(x)) {
  //     left[p] -= c;
  //     right[p] += c;
  //   }
  // };

  // for (auto pr : primes)
  //   if (pr <= n)
  //     fn(n, pr);
  //   else
  //     break;

  // add(n);
  map<int, int> max_powers;
  for (auto pr : primes)
    if (pr <= n) {
      ll power_val = pr;
      int mx_pow = 1;
      while (power_val * (ll)pr <= m) mx_pow++, power_val *= (ll)pr;
      max_powers[pr] = mx_pow;
    }

  auto g = [&](int v, int p) -> int {
    debug(v, p);
    int left = fn(v, p);
    int right = fn(n, p);
    if (left == right) return INF;
    for (int i = max_powers[p]; i >= 1; i--)
      if (left / i != right / i) return left / i;
    return 0;
  };
  int p = upper_bound(all(primes), n) - primes.begin();
  p = primes[p - 1];
  for (int i = n - 1; i >= p; --i) {
    // prime_factors(i + 1);
    debug(i);
    int curr = INF;
    // for (auto p : primes_r) {
    for (int j = 0; j <= 100; j++) {
      curr = min(g(i, primes[j]), curr);
      if (curr == 0) break;
    }
    ans += curr;
    debug(i, curr, ans);
    if (curr == 0) break;
  }
  cout << ans << endl;
}

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  // primes.reserve(664579);
  for (int i = 2; i < N; ++i) {
    if (primef[i] == 0) {
      primes.pb(i);
      for (int j = i; j < N; j += i) {
        primef[j] = i;
      }
    }
  }
  int testCases = 1000;
  cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
