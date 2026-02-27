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

vvi factors(N);
void solve() {
  int n, q;
  cin >> n >> q;
  vi a(n);
  read(a, n);
  map<int, vi> freq;
  fo(i, n) {
    freq[a[i]].pb(i);
  }
  while (q--) {
    debug(q);
    int k, l, r;
    cin >> k >> l >> r;
    l--, r--;
    int ind = l - 1;
    int ans = 0;
    while (k > 1 && ind < r) {
      debug(k, ind, ans);
      auto& fac = factors[k];
      int mini = -1;
      int minf = -1;
      for (int f : fac) {
        auto it = upper_bound(all(freq[f]), ind);
        if (it != freq[f].end() && (*it) <= r) {
          if (mini == -1 || *it < mini) {
            mini = *it;
            minf = f;
          }
        }
      }
      if (mini == -1) break;
      ind = max(ind, l);
      ans += k * (mini - ind);
      while (k % minf == 0) {
        k = k / minf;
      }
      ind = mini;
    }
    ind = max(ind, l);
    debug(k, ind, ans, r);
    ans += k * (r - ind + 1);
    cout << ans << "\n";
  }
}

signed main() {
  fastio;
  //   Error_file("0_Error.txt");

  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      factors[j].pb(i);
    }
  }
  int testCases = 1000;
  cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
