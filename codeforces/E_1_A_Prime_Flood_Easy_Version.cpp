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

constexpr int MOD = 998244353;
constexpr int N = 3000 + 100;
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

int mod(int a, int m = MOD) { return (a % m + m) % m; }
int add(int a, int b, int m = MOD) { return mod(a + b, m); }
int sub(int a, int b, int m = MOD) { return mod(a - b, m); }
int mul(int a, int b, int m = MOD) { return mod(a * b, m); }
int power(int a, int b, int m = MOD) {
  int res = 1;
  while (b) {
    if (b & 1)
      res = mul(res, a, m);
    a = mul(a, a, m);
    b >>= 1;
  }
  return res;
}
int inv(int a, int m = MOD) { return power(a, m - 2, m); }
int divide(int a, int b, int m = MOD) { return mul(a, inv(b, m), m); }

vi pw2(N);
vi red(N, 1);

void precompute() {
  pw2[0] = 1;
  for (int i = 1; i < N; i++) {
    pw2[i] = add(pw2[i - 1], pw2[i - 1]);
  }

  for (int i = 1; i < N; i++) {
    if (red[i] == 1) {
      for (int j = i; j < N; j += i) {
        red[j] *= i;
      }
    }
  }
}

void solve() {
  int n;
  cin >> n;
  vi a(n);
  read(a, n);

  // any sequence with min * 2 > max can be brought to min while in the other case it is always 1

  // for each element take all elements > than it but less than 2 * it

  // when min is x
  // (2^cnt[x]-1)*(2^cnt[x+1:2x-1])*x -> conv to x
  // (2^cnt[x]-1)*(2^cnt[x+1:2x-1])*(2^cnt[2x:n]-1) -> conv to 1

  // mistake max also matters
  // when min is x and max is y
  // (2^cnt[x]-1)*(2^cnt[y]-1)*(2^middle) -> dp[x][y]

  vi cnt(n + 1);
  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
  }
  vi pref(n + 1);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + cnt[i];
  }

  // int ans = 0;
  // for (int i = 1; i <= n; i++) {
  //   ans = add(ans, mul(mul(power(2, cnt[i]) - 1, power(2, pref[min(n, 2 * i - 1)] - pref[i])), i));
  //   ans = add(ans, mul(mul(power(2, cnt[i]) - 1, power(2, pref[n] - pref[min(n, 2 * i - 1)]) - 1), 1));
  // }
  // cout << ans << endl;

  vvi dp(n + 1, vi(n + 1));
  for (int i = 1; i <= n; i++) {
    dp[i][i] = i;
    for (int j = i + 1; j <= n; j++) {
      if (red[i] % red[j] == 0) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = dp[i][j - 1];
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int self = sub(pw2[cnt[i]], 1);
    ans = add(ans, mul(self, i));
    for (int j = i + 1; j <= n; j++) {
      int middle = pref[j - 1] - pref[i];
      int temp = mul(mul(sub(pw2[cnt[i]], 1), sub(pw2[cnt[j]], 1)), pw2[middle]);
      ans = add(ans, mul(temp, dp[i][j]));
    }
  }
  cout << ans << '\n';
}
