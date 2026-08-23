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
  cin >> testCases;

  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}

void precompute() {
}

void solve() {
  string a, b;
  cin >> a >> b;

  int n = a.size();
  int m = b.size();

  vi A(n), B(m);
  fo(i, n) A[i] = a[i] - '0';
  fo(i, m) B[i] = b[i] - '0';

  int SZ = 10;
  v(v(vi)) dp(n + 1, vvi(m + 1, vi(SZ, -1e9)));
  dp[0][0][0] = 0;
  // dp[i][j][k] = max length which can be made common by a[0..i-1] and b[0..j-1] with diff k
  auto M = [&](int x) -> int {
    return (x + SZ) % SZ;
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < SZ; k++) {
        dp[i + 1][j + 1][k] = max({dp[i][j + 1][M(k - A[i])], dp[i + 1][j][M(k + B[j])], dp[i][j][M(k - A[i] + B[j])]});
      }
      // increasing the difference 0 only if we can ensure the digit increases by 1 in both strings
      // ending with 0 case a bit weird
      auto& curr = dp[i + 1][j + 1][0];
      if (curr == dp[i][j][0]) {
      } else if (A[i] == 0 && curr == dp[i][j + 1][0]) {
        curr--;
      } else if (B[j] == 0 && curr == dp[i + 1][j][0]) {
        curr--;
      }
      curr++;
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      cerr << max(dp[i][j][0], -1ll) << " ";
    }
    cerr << endl;
  }
  cout << max(dp[n][m][0], -1ll) << endl;
}
