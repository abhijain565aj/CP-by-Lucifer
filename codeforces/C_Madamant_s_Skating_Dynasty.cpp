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
constexpr int N = 2e5 + 100;
constexpr int INF = 1e18;

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

vi fac(N + 1, 1);
void precompute() {
  for (int i = 1; i <= N; i++) {
    fac[i] = mul(fac[i - 1], i);
  }
}

void solve() {
  int n;
  cin >> n;
  vi a(n);
  read(a, n);
  sortall(a);
  reverse(all(a));

  int total = fac[n - 1];
  int sum = a[0];
  int ans = 0;
  for (int i = 1; i < n; i++) {
    ans = add(ans, divide(mul(total, sub(sum, i * a[i])), i));
    sum = add(sum, a[i]);
  }
  cout << ans << endl;
}
