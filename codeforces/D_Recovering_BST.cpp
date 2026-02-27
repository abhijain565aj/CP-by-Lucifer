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
// typedef long long ll;
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

signed main() {
  fastio;
  int n;
  cin >> n;
  vi a(n);
  read(a, n);
  vvi adj(n, vi(n));
  fo(i, n) fo(j, n) adj[i][j] = __gcd(a[i], a[j]) > 1;
  // debug(adj);
  vector<vector<vi>> dp(n, vvi(n, vi(2, -1)));
  // fo(i, n) dp[i][i][i] = 1;
  // auto fn = [&](auto&& self, int l, int r, int root) -> int {
  //   if (l > r) return true;
  //   if (dp[l][r].find(root) != dp[l][r].end()) return dp[l][r][root];
  //   debug(l, r, root);
  //   dp[l][r][root] = 0;
  //   bool left = false, right = false;
  //   if (l == root) left = true;
  //   if (r == root) right = true;
  //   for (int i = l; i < root; i++)
  //     if (adj[root][i] && self(self, l, root - 1, i)) {
  //       left = true;
  //       break;
  //     }
  //   for (int i = root + 1; i <= r; i++)
  //     if (adj[root][i] && self(self, root + 1, r, i)) {
  //       right = true;
  //       break;
  //     }
  //   if (left && right) dp[l][r][root] = 1;
  //   return dp[l][r][root];
  // };
  auto fn = [&](auto&& self, int l, int r, int side) -> int {
    if (l >= r) return true;
    if (dp[l][r][side] != -1) return dp[l][r][side];
    dp[l][r][side] = 0;
    int root = side ? r : l;
    if (root == l) {
      for (int i = l + 1; i <= r; i++) {
        if (adj[root][i] && self(self, l + 1, i, 1) && self(self, i, r, 0)) {
          return dp[l][r][side] = 1;
        }
      }
    } else {
      for (int i = l; i < r; i++) {
        if (adj[root][i] && self(self, l, i, 1) && self(self, i, r - 1, 0)) {
          return dp[l][r][side] = 1;
        }
      }
    }
    return dp[l][r][side];
  };
  fo(i, n) {
    if (fn(fn, 0, i, 1) && fn(fn, i, n - 1, 0)) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
