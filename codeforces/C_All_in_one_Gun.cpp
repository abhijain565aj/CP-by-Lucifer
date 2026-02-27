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
  LazySegmentTree(ll n, ll default_value = 0) {
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
  int n, h, k;
  cin >> n >> h >> k;
  vi a(n);
  read(a, n);
  int ans = 0;
  int sum = accumulate(all(a), 0LL);
  ans = (h / sum) * (k + n);
  if (h % sum == 0) {
    cout << ans - k << endl;
    return;
  }
  h -= (h / sum) * sum;
  vi prefix(n);
  prefix[0] = a[0];
  fo1(i, 1, n) prefix[i] = prefix[i - 1] + a[i];
  vi prefmin(n), suffmax(n);
  prefmin[0] = a[0];
  fo1(i, 1, n) prefmin[i] = min(prefmin[i - 1], a[i]);
  suffmax[n - 1] = a[n - 1];
  re(i, n - 1) suffmax[i] = max(suffmax[i + 1], a[i]);
  debug(prefix, prefmin, suffmax);
  int rem = n;
  fo(i, n - 1) {
    int val = max(prefix[i] + suffmax[i + 1] - prefmin[i],prefix[i]);
    if (val >= h) {
      rem = i + 1;
      break;
    }
  }
  cout << ans + rem << endl;
}
