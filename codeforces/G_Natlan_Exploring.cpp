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
constexpr int N = 1e6 + 1;
constexpr int INF = 1e18;

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  vi grnd(N, true);
  vvi fac(N);
  vi pf(N);
  for (int i = 2; i < N; i++) {
    int prime = pf[i] == 0;
    for (int j = i; j < N; j += i) {
      if (!grnd[i])
        grnd[j] = false;
      else
        fac[j].pb(i);
      if (prime) pf[j]++;
    }
    if (i * i < N) grnd[i * i] = false;
  }
  int n;
  cin >> n;
  vi a(n);
  read(a, n);
  auto sgn = [&](int x) -> int {
    return (pf[x] & 1) ? 1 : -1;
  };

  map<int, int> mp;
  fo(i, n) {
    // debug(fac[a[i]]);
    int v = i == 0;
    for (auto f : fac[a[i]]) {
      v += sgn(f) * mp[f];
    }
    v %= MOD;
    if (v < 0) v += MOD;
    for (auto f : fac[a[i]]) {
      mp[f] += v;
      mp[f] %= MOD;
    }
    if (i == n - 1) {
      cout << v << endl;
      return 0;
    }
  }
}
