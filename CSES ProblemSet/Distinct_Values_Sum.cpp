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

signed main() {
  fastio;
  int n;
  cin >> n;
  vi a(n);
  read(a, n);

  map<int, vi> mp;
  re(i, n) mp[a[i]].pb(i);

  LazySegmentTree<int> st(n);
  for (auto& [_, v] : mp) {
    st.update(v.back(), n - 1, 1);
  }

  int sum = 0;
  fo(i, n) {
    sum += st.query(0, n - 1);
    st.update(mp[a[i]].back(), n - 1, -1);
    mp[a[i]].pop_back();
    if (mp[a[i]].size())
      st.update(mp[a[i]].back(), n - 1, 1);
  }
  cout << sum << endl;
}
