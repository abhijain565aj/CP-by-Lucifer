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
constexpr int N = 1e5 + 1;
constexpr int INF = 1e9;

void solve() {
  int n, m, l;
  cin >> l >> n >> m;
  vi a(l);
  read(a, l);
  vvi b(n, vi(m));
  fo(i, n) fo(j, m) cin >> b[i][j];
  v(v(vi)) dp1(n, v(vi)(m, vi(l, -1)));
  auto dp2 = dp1;
  auto fn = [&](auto&& fn, int r, int c, int idx, int dpn) -> bool {
    if (r >= n || c >= m || idx >= l) return 0;
    if (dpn == 1 && dp1[r][c][idx] != -1) return dp1[r][c][idx];
    if (dpn == 2 && dp2[r][c][idx] != -1) return dp2[r][c][idx];
    if (dpn == 1) {
      if (b[r][c] != a[idx]) return dp1[r][c][idx] = 0;
      return dp1[r][c][idx] = !fn(fn, r + 1, c + 1, idx + 1, 2);
    } else {
      return dp2[r][c][idx] = fn(fn, r, c, idx, 1) || fn(fn, r, c + 1, idx, 2) || fn(fn, r + 1, c, idx, 2);
    }
  };
  cout << (fn(fn, 0, 0, 0, 2) ? "T\n" : "N\n");
};

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1000;
  cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
