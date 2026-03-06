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

void file(string s = "") {
  if (local) {
    // freopen("error.txt", "w", stderr);
    // freopen("output.txt", "w", stdout);
    // freopen(("input" + s + ".txt").c_str(), "r", stdin);
    return;
  }
}

constexpr int MOD = 1000000007;
constexpr int N = 1e5 + 1;
constexpr int INF = 1e18;

void solve();
void precompute();

signed main() {
  fastio;
  file();
  precompute();

  int testCases = 1;
  // cin >> testCases;

  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}

void precompute() {
}

void solve1() {
  int n, k;
  cin >> n >> k;
  vi a(n);
  read(a, n);
  vvi dp(n + 1, vi(k + 1, 0));  // dp[i][j] = result for [i,...,n-1] with j subarrays
  for (int i = n - 1; i >= 0; i--) {
    dp[i][0] = INF;
    for (int j = 1; j <= k; j++) {
      dp[i][j] = INF;
      int sum = 0;
      for (int k = i; k < n; k++) {
        sum += a[k];
        dp[i][j] = min(dp[k + 1][j - 1] + sum * sum, dp[i][j]);
      }
    }
  }
  // debug(dp);
  cout << dp[0][k] << endl;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vi a(n);
  read(a, n);
  vi pre(n);
  fo(i, n) pre[i] = a[i] + ((i > 0) ? pre[i - 1] : 0);
  debug(pre);

  vvi dp(n + 1, vi(k + 2, -1));
  auto opt = dp;
  fo(i, n + 1) fo(j, k + 2) opt[i][j] = i;
  fo(i, k + 2) dp[n][i] = 0;
  debug(dp, opt);
  // dp[i][j] = result for [i,...,n-1] with j subarrays
  for (int i = n - 1; i >= 0; i--) {
    for (int j = k; j >= 1; j--) {
      for (int t = opt[i][j + 1]; t <= min(opt[i + 1][j], n - 1); t++) {
        int sum = pre[t] - ((i > 0) ? pre[i - 1] : 0);
        if (dp[i][j] == -1 || dp[i][j] >= dp[t + 1][j - 1] + sum * sum) {
          if (dp[t + 1][j - 1] != -1) {
            dp[i][j] = dp[t + 1][j - 1] + sum * sum;
            opt[i][j] = t;
          }
        }
      }
    }
  }
  debug(dp);
  cout << dp[0][k] << endl;
}