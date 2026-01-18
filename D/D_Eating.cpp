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
  int n, q;
  cin >> n >> q;
  vi w(n);
  read(w, n);
  vi pf_xor(n + 1, 0);
  re(i, n) pf_xor[i] = pf_xor[i + 1] ^ w[i];
  vvi a(n, vi(32, -1));
  fo(i, n) {
    fo(j, 32) {
      if (i != 0) a[i][j] = a[i - 1][j];
      if (w[i] >= (1ll << j)) a[i][j] = i;
    }
  }
  auto msb = [&](int x) -> int {
    for (int j = 31; j >= 0; j--) {
      if (x >= (1ll << j)) return j;
    }
    return 0;
  };
  while (q--) {
    int x;
    cin >> x;
    int ans = 0;
    int sb = msb(x);
    int idx = n - 1;
    int cnt = 0;
    while (true) {
      if (cnt++ > n) break;
      debug(idx);
      if (idx == -1) {
        ans = n;
        break;
      }
      idx = a[idx][sb];
      if (idx == -1) {
        ans = n;
        break;
      }
      int x_1 = x ^ pf_xor[idx + 1];
      if (x_1 >= w[idx]) {
        idx--;
        sb = msb(x ^ pf_xor[idx]);
      } else {
        ans = n - 1 - idx;
        break;
      }
    }
    debug(x, ans);
    cout << ans << " ";
  }
  cout << "\n";
}

signed main() {
  fastio;
    Error_file("0_Error.txt");
  int testCases = 1000;
  cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
