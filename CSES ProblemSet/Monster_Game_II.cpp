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
constexpr int N = 1e6 + 1;
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
// LiChaoTree
struct LiChaoTree {
  int n;
  vector<int> tree;
  vector<pii> line;
  LiChaoTree(int n) {
    this->n = n;
    tree.resize(4 * n, 0);
  }
  pii bestLine(int x) {
    return line[queryp(1, 0, n - 1, x)];
  }
  void addLine(pii nline) {
    line.pb(nline);
    updatep(1, 0, n - 1, line.size() - 1);
  }
  int best(int l1, int l2, int x) {
    auto [c1, m1] = line[l1];
    auto [c2, m2] = line[l2];
    int y1 = c1 + m1 * x;
    int y2 = c2 + m2 * x;
    return (y1 < y2) ? l1 : l2;
  }
  int queryp(int v, int tl, int tr, int pos) {
    if (pos == tl && pos == tr) {
      return tree[v];
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
      return best(tree[v], queryp(v * 2, tl, tm, pos), pos);
    } else {
      return best(tree[v], queryp(v * 2 + 1, tm + 1, tr, pos), pos);
    }
  }
  void updatep(int v, int tl, int tr, int new_line) {
    int tm = (tl + tr) / 2;
    if (tl > tr)
      return;
    else if (tl == tr) {
      tree[v] = best(tree[v], new_line, tm);
      return;
    }
    int mid = best(tree[v], new_line, tm);
    int left = best(tree[v], new_line, tl);
    if (mid == new_line)
      swap(tree[v], new_line);
    if (left != mid)
      updatep(v * 2, tl, tm, new_line);
    else
      updatep(v * 2 + 1, tm + 1, tr, new_line);
  }
};

void solve() {
  int n, x;
  cin >> n >> x;
  vi dp(n + 1, INF);
  vi s(n + 1), f(n + 1);
  loop(i, 1, n) cin >> s[i];
  loop(i, 1, n) cin >> f[i];
  f[0] = x;
  dp[0] = 0;
  LiChaoTree st(N);
  st.line.pb({0, x});
  for (int i = 1; i <= n; i++) {
    auto [c, m] = st.bestLine(s[i]);
    dp[i] = c + m * s[i];
    st.addLine({dp[i], f[i]});
    // for (int j = 0; j < i; j++) {
    //   dp[i] = min(dp[j] + f[j] * s[i], dp[i]);
    // }
    // dp[i], f[i]
  }
  cout << dp.back() << endl;
}
