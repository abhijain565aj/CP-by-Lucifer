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
  int n;
  cin >> n;
  auto ask = [&](int i, int j) -> int {
    cout << "? " << i << " " << j << endl;
    int dis;
    cin >> dis;
    return dis;
  };
  int mxd = 0, c1 = 1;
  // n^2 queries for corner1
  for (int j = 2; j <= n * n; j++) {
    int v = ask(1, j);
    if (v > mxd) c1 = j, mxd = v;
  }
  // distances w.r.t corner 1;
  vi D1(n * n + 1), D2(n * n + 1);
  for (int j = 1; j <= n * n; j++) {
    D1[j] = ask(c1, j);
  }

  vi ctr;
  for (int j = 1; j <= n * n; j++)
    if (D1[j] == n - 1) ctr.pb(j);

  int c2 = ctr[0];
  mxd = 0;
  for (auto x : ctr) {
    int v = ask(ctr[0], x);
    if (v > mxd) mxd = v, c2 = x;
  }

  for (int j = 1; j <= n * n; j++) {
    D2[j] = ask(c2, j);
  }

  vvi a(n, vi(n));
  for (int i = 1; i <= n * n; i++) {
    int i1 = (D1[i] - D2[i] + n - 1) / 2;
    int j1 = (D1[i] + D2[i] - n + 1) / 2;
    a[i1][j1] = i;
  }
  cout << "!" << endl;
  fo(i, n) {
    fo(j, n) cout << a[i][j] << " ";
    cout << endl;
  }
}
