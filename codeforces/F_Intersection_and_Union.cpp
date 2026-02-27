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
#define fo1(i, a, b) for (int i = a; i < b; i++)
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

constexpr int MOD = 998244353;
constexpr int N = 3e5 + 5;
constexpr int INF = 1e18;
template <typename T>
struct LazySegmentTree {
  vector<T> tree;
  vector<T> lazy;
  ll n;
  T default_value;
  LazySegmentTree(ll n, ll default_value = 0) {
    this->n = n;
    this->default_value = default_value;
    tree.resize(4 * n);
    lazy.resize(4 * n);
  }
  void build(vector<T>& a) {
    buildp(a, 1, 0, n - 1);
  }
  T query(ll l, ll r) {
    return queryp(1, 0, n - 1, l, r);
  }
  void update(ll l, ll r, T val) {
    updatep(1, 0, n - 1, l, r, val);
  }
  T operation(T l, T r) {
    return l + r;
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
  void push(ll v, ll tl, ll tr) {
    if (lazy[v] == 0 || tl == tr) return;
    ll tm = (tl + tr) / 2;  // ADD

    tree[v * 2] = lazy[v] * (tm - tl + 1);  // CHANGE
    lazy[v * 2] = lazy[v];                  // CHANGE

    tree[v * 2 + 1] = lazy[v] * (tr - tm);  // CHANGE
    lazy[v * 2 + 1] = lazy[v];              // CHANGE

    lazy[v] = 0;
  }
  T queryp(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) return default_value;
    if (l == tl && r == tr) return tree[v];
    ll tm = (tl + tr) / 2;
    push(v, tl, tr);
    return operation(
        queryp(v * 2, tl, tm, l, min(r, tm)),
        queryp(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
  void updatep(ll v, ll tl, ll tr, ll l, ll r, T val) {
    if (l > r) return;
    if (l == tl && r == tr) {
      tree[v] = val * (tr - tl + 1);
      lazy[v] = val;
    } else {
      ll tm = (tl + tr) / 2;
      push(v, tl, tr);
      updatep(v * 2, tl, tm, l, min(r, tm), val);
      updatep(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
      tree[v] = operation(tree[v * 2], tree[v * 2 + 1]);
    }
  }
};

ll mod(ll a, ll m = MOD) { return (a % m + m) % m; }
ll add(ll a, ll b, ll m = MOD) { return mod(a + b, m); }
ll sub(ll a, ll b, ll m = MOD) { return mod(a - b, m); }
ll mul(ll a, ll b, ll m = MOD) { return mod(a * b, m); }
ll power(ll a, ll b, ll m = MOD) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res = mul(res, a, m);
    a = mul(a, a, m);
    b >>= 1;
  }
  return res;
}
ll inv(ll a, ll m = MOD) { return power(a, m - 2, m); }
ll divide(ll a, ll b, ll m = MOD) { return mul(a, inv(b, m), m); }

signed main() {
  fastio;
  int n;
  cin >> n;
  v(pii) a(n);
  fo(i, n) cin >> a[i].F >> a[i].S;
  /*
    1 2 3 4 5 6 7 8 9
    2 2 2 2 2 2 2 2 2 (3)
    4 4 4 6 6 6 6 6 4 (9)
    8 18

  */
  LazySegmentTree<int> seg(N);
  fo(i, n) {
    seg.update(a[i].F, a[i].S, i + 1);
  }
  int ans = 0;
  fo1(i, 0, N) {
    int ind = seg.query(i, i);
    if (ind == 0) continue;
    ans = add(ans, mul(power(3, max(ind - 2, 0ll)), power(2, n - ind + (ind != 1))));
    debug(i, ind, ans);
  }
  cout << ans << endl;
}