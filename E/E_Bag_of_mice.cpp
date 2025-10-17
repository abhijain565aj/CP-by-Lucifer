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
#define ld long double

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

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int w, b;
  cin >> w >> b;
  v(v(v(ld))) dp(w + 1, v(v(ld))(b + 1, v(ld)(2, -1)));
  // 0 - princess 1 - dragon
  auto fn = [&](auto&& fn, int i, int j, int k) -> long double {
    if (dp[i][j][k] >= 0) return dp[i][j][k];
    ld i1 = i, j1 = j;
    debug(i, j, k);
    if (i == 0 && j >= 0) {
      dp[i][j] = {0, 1};
      return dp[i][j][k];
    }
    if (i > 0 && j == 0) {
      dp[i][j] = {1, 1};
      return dp[i][j][k];
    }
    if (k == 0) {
      dp[i][j][k] = i1 / (j1 + i1) + (j1 / (i1 + j1)) * (1.0 - fn(fn, i, j - 1, 1 - k));
    } else if (k == 1) {
      ld after = (j1 - 1.0) / (i1 + j1 - 1.0) * (1.0 - ((j > 1) ? fn(fn, i, j - 2, 0) : 1.0)) + i1 / (i1 + j1 - 1) * (1.0 - fn(fn, i - 1, j - 1, 0));
      dp[i][j][1] = i1 / (i1 + j1) + (j1 / (i1 + j1)) * after;
    }
    debug(i, j, k, dp[i][j][k]);
    return dp[i][j][k];
  };
  cout << fixed << setprecision(12) << fn(fn, w, b, 0) << endl;
  debug(dp);
}
