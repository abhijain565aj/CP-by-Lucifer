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
  int n;
  cin >> n;
  vi a(n);
  read(a, n);

  vi pre(n, 0);
  fo(i, n) pre[i] = (i > 0 ? pre[i - 1] + a[i] : a[i]);

  vi prepre(n, 0);
  fo(i, n) prepre[i] = (i > 0 ? prepre[i - 1] + pre[i] : pre[i]);

  int total = prepre.back();
  v(pii) bsums(n);
  fo(i, n) {
    bsums[i] = {(n - i), total};
    total -= (n - i) * a[i];
  }

  v(pii) bpref(n);
  bpref[0] = bsums[0];
  fo1(i, 1, n) bpref[i] = {bpref[i - 1].F + bsums[i].F, bpref[i - 1].S + bsums[i].S};

  debug(pre, prepre, bsums, bpref);
  auto fn = [&](int ind) -> int {
    if (ind <= 0) return 0;
    int j = lower_bound(all(bpref), make_pair(ind, -INF)) - bpref.begin();
    debug(ind, j);
    int ans = 0;
    if (j > 0) ans += bpref[j - 1].S, ind -= bpref[j - 1].F;
    debug(ans, ind);
    if (ind == 0) return ans;
    if (j == 0) return ans + prepre[ind - 1];
    ans += prepre[j + ind - 1] - prepre[j - 1] - ind * pre[j - 1];
    return ans;
  };

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << fn(r) - fn(l - 1) << endl;
  }
}

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1;
  // cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
