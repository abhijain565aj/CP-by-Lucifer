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
#include "./DEBUG.cpp"
#define local true
#else
#define debug(...)
#define Test(tt)
#define Error_file(x)
#define local false
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

#define fo(i, n) for (int i = 0; i < n; i++)
#define re(i, n) for (int i = n - 1; i >= 0; i--)
#define loop(i, a, b) for (int i = a; (a >= b) ? i >= b : i <= b; (a >= b) ? i-- : i++)

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
#define print(a, n) \
  for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');

constexpr int MOD = 1000000007;
constexpr int N = 1e6 + 1;
constexpr int INF = 1e18;

signed main() {
  fastio;
  vvi fac(N);
  for (int i = 2; i < N; i++) {
    if (fac[i].empty()) {
      for (int j = i; j < N; j += i) {
        fac[j].pb(i);
      }
    }
  }
  int n;
  cin >> n;
  vi a(n);
  read(a, n);
  vi mp(N, 0);
  fo(i, n) {
    auto& f = fac[a[i]];
    debug(a[i], f);
    for (int i = 0; i < (1 << f.size()); i++) {
      int prod = 1;
      fo(j, (int)f.size()) {
        if (i & (1 << j)) {
          prod *= f[j];
        }
      }
      mp[prod]++;
    }
  }
  auto nC2 = [](int n) -> int {
    return (n * (n - 1)) / 2;
  };
  int ans = 0;
  for (int i = 1; i < N; i++) {
    if (fac[i].size() & 1)
      ans -= nC2(mp[i]);
    else
      ans += nC2(mp[i]);
  }
  cout << ans << endl;
}
