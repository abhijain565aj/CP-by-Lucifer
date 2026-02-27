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
constexpr int INF = 1e18;

void solve();

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1;
  cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}

template <typename T>
struct LazySegmentTree {
  vector<T> tree;
  vector<T> lazy;
  ll n;
  ll default_value;
  LazySegmentTree(ll n, ll default_value = 1e9) {
    this->n = n;
    this->default_value = default_value;
    tree.resize(4 * n);
    lazy.resize(4 * n);
  }
  void build(vector<T>& a) {
    buildp(a, 1, 0, n - 1);
  }
  ll query(ll l, ll r) {
    return queryp(1, 0, n - 1, l, r);
  }
  void update(ll l, ll r, T val) {
    updatep(1, 0, n - 1, l, r, val);
  }
  T operation(T l, T r) {
    return min(l, r);
  }

  void buildp(vector<T>& a, ll v, ll tl, ll tr) {
    if (tl == tr)
      tree[v] = a[tl];
    else {
      ll tm = (tl + tr) / 2;
      buildp(a, v * 2, tl, tm);
      buildp(a, v * 2 + 1, tm + 1, tr);
      tree[v] = operation(tree[v * 2], tree[v * 2 + 1]);
    }
  }
  void push(ll v) {
    tree[v * 2] += lazy[v];
    lazy[v * 2] += lazy[v];
    tree[v * 2 + 1] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
  }
  T queryp(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) return default_value;
    if (l == tl && r == tr) return tree[v];
    ll tm = (tl + tr) / 2;
    push(v);
    return operation(
        queryp(v * 2, tl, tm, l, min(r, tm)),
        queryp(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
  void updatep(ll v, ll tl, ll tr, ll l, ll r, T val) {
    if (l > r) return;
    if (l == tl && r == tr) {
      tree[v] += val;
      lazy[v] += val;
    } else {
      ll tm = (tl + tr) / 2;
      push(v);
      updatep(v * 2, tl, tm, l, min(r, tm), val);
      updatep(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
      tree[v] = operation(tree[v * 2], tree[v * 2 + 1]);
    }
  }
};

template <typename T>
struct LazySegmentTreeMax {
  vector<T> tree;
  vector<T> lazy;
  ll n;
  ll default_value;
  LazySegmentTreeMax(ll n, ll default_value = -1e9) {
    this->n = n;
    this->default_value = default_value;
    tree.resize(4 * n);
    lazy.resize(4 * n);
  }
  void build(vector<T>& a) {
    buildp(a, 1, 0, n - 1);
  }
  ll query(ll l, ll r) {
    return queryp(1, 0, n - 1, l, r);
  }
  void update(ll l, ll r, T val) {
    updatep(1, 0, n - 1, l, r, val);
  }
  T operation(T l, T r) {
    return max(l, r);
  }

  void buildp(vector<T>& a, ll v, ll tl, ll tr) {
    if (tl == tr)
      tree[v] = a[tl];
    else {
      ll tm = (tl + tr) / 2;
      buildp(a, v * 2, tl, tm);
      buildp(a, v * 2 + 1, tm + 1, tr);
      tree[v] = operation(tree[v * 2], tree[v * 2 + 1]);
    }
  }
  void push(ll v) {
    tree[v * 2] += lazy[v];
    lazy[v * 2] += lazy[v];
    tree[v * 2 + 1] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
  }
  T queryp(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) return default_value;
    if (l == tl && r == tr) return tree[v];
    ll tm = (tl + tr) / 2;
    push(v);
    return operation(
        queryp(v * 2, tl, tm, l, min(r, tm)),
        queryp(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
  void updatep(ll v, ll tl, ll tr, ll l, ll r, T val) {
    if (l > r) return;
    if (l == tl && r == tr) {
      tree[v] += val;
      lazy[v] += val;
    } else {
      ll tm = (tl + tr) / 2;
      push(v);
      updatep(v * 2, tl, tm, l, min(r, tm), val);
      updatep(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
      tree[v] = operation(tree[v * 2], tree[v * 2 + 1]);
    }
  }
};

void solve() {
  int n;
  string s;
  cin >> n >> s;
  LazySegmentTree<int> lst1(n), lst2(n);
  LazySegmentTreeMax<int> lst1_max(n), lst2_max(n);
  fo(i, n) {
    if (s[i] == '(' || s[i] == ')') {
      lst1.update(i, n - 1, (s[i] == '(') ? 1 : -1);
      lst1_max.update(i, n - 1, (s[i] == '(') ? 1 : -1);
    } else {
      lst2.update(i, n - 1, (s[i] == '[') ? 1 : -1);
      lst2_max.update(i, n - 1, (s[i] == '[') ? 1 : -1);
    }
  }
  int ans = 0;
  fo(i, n) {
    if (s[i] == '(' && lst1.query(i, n - 1) < 0){
      if(lst2.query(i,n-1)<0) 
    }
  }
}
