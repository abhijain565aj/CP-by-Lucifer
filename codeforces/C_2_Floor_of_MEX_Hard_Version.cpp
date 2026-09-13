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

template <typename T>
struct LazySegmentTree {
  vector<T> tree;
  vector<T> lazy;
  int n;
  T default_value;
  function<T(T, T)> merge;
  LazySegmentTree(
      int n,
      T default_value = 0,
      function<T(T, T)> merge = [](T l, T r) { return l + r; }) {
    this->n = n;
    this->default_value = default_value;
    this->merge = merge;
    tree.resize(4 * n);
    lazy.resize(4 * n);
  }
  void build(vector<T>& a) {
    buildp(a, 1, 0, n - 1);
  }
  T query(int l, int r) {
    return queryp(1, 0, n - 1, l, r);
  }
  void update(int l, int r, T val) {
    updatep(1, 0, n - 1, l, r, val);
  }
  void update(int pos, T val) {
    updatep(1, 0, n - 1, pos, pos, val);
  }
  void buildp(vector<T>& a, int v, int tl, int tr) {
    if (tl == tr)
      tree[v] = a[tl];
    else {
      int tm = (tl + tr) / 2;
      buildp(a, v * 2, tl, tm);
      buildp(a, v * 2 + 1, tm + 1, tr);
      tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
  }
  void push(int v, int tl, int tr) {
    if (lazy[v] == 0 || tl == tr) return;
    int tm = (tl + tr) / 2;
    tree[v * 2] += lazy[v] * (tm - tl + 1);
    lazy[v * 2] += lazy[v];
    tree[v * 2 + 1] += lazy[v] * (tr - tm);
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
  }
  T queryp(int v, int tl, int tr, int l, int r) {
    if (l > r) return default_value;
    if (l == tl && r == tr) return tree[v];
    int tm = (tl + tr) / 2;
    push(v, tl, tr);
    return merge(
        queryp(v * 2, tl, tm, l, min(r, tm)),
        queryp(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
  void updatep(int v, int tl, int tr, int l, int r, T val) {
    if (l > r) return;
    if (l == tl && r == tr) {
      tree[v] += val * (tr - tl + 1);
      lazy[v] += val;
    } else {
      int tm = (tl + tr) / 2;
      push(v, tl, tr);
      updatep(v * 2, tl, tm, l, min(r, tm), val);
      updatep(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
      tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
  }
};

void solve() {
  int n;
  cin >> n;
  vi a(n);
  read(a, n);
  LazySegmentTree<int> lst(3 * n);
  for (int i = 0; i < n; i++) {
    lst.update(a[i] * (i + 1), a[i] * (i + 1) + i, 1);
  }
  vb ans(n + 1);
  for (int i = 0; i < n; i++) {
    ans[i] = lst.query(i, i) == 0;
  }
  ans[n] = false;

  // all intervals = sum n/k = n logn
  // store at R the max of L atleast needed
  vi maxL(n + 1, -1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < a[i]; j++) {
      int L = j * (i + 1);
      int R = j * (i + 1) + i + 1;
      // [ L , R )
      if (R < n) {
        maxL[R] = max(maxL[R], L);
      } else {
        maxL[n] = max(maxL[n], L);
      }
    }
  }

  debug(maxL);

  int total = 1;
  vi dp(n + 1);  // number of ways so that last selected position is i
  int lp = -1;
  int curr_maxL = -1;

  for (int i = 0; i <= n; i++) {
    curr_maxL = max(curr_maxL, maxL[i]);
    while (lp < curr_maxL) {
      if (lp == -1)
        total--;
      else
        total -= dp[lp];
      total = (total + MOD) % MOD;
      lp++;
    }
    debug(i, total, curr_maxL);
    if (ans[i]) dp[i] = total;
    total = (total + dp[i]) % MOD;
  }
  debug(dp);
  cout << total << endl;
}
