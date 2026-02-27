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
  vector<T> tree, lazy;
  vector<bool> has_lazy;
  ll n;
  T default_value;

  LazySegmentTree(ll n, T default_value = 0) {
    this->n = n;
    this->default_value = default_value;
    tree.assign(4 * n, default_value);
    lazy.assign(4 * n, default_value);
    has_lazy.assign(4 * n, false);
  }

  T operation(T a, T b) {
    return max(a, b);
  }

  void build(vector<T>& a) {
    buildp(1, 0, n - 1, a);
  }

  void buildp(ll v, ll tl, ll tr, vector<T>& a) {
    if (tl == tr) {
      tree[v] = a[tl];
    } else {
      ll tm = (tl + tr) / 2;
      buildp(v * 2, tl, tm, a);
      buildp(v * 2 + 1, tm + 1, tr, a);
      tree[v] = operation(tree[v * 2], tree[v * 2 + 1]);
    }
  }

  void apply(ll v, T val) {
    tree[v] = val;
    lazy[v] = val;
    has_lazy[v] = true;
  }

  void push(ll v) {
    if (!has_lazy[v]) return;
    apply(v * 2, lazy[v]);
    apply(v * 2 + 1, lazy[v]);
    has_lazy[v] = false;
  }

  void update(ll l, ll r, T val) {
    updatep(1, 0, n - 1, l, r, val);
  }

  void update(ll pos, T val) {
    updatep(1, 0, n - 1, pos, pos, val);
  }

  void updatep(ll v, ll tl, ll tr, ll l, ll r, T val) {
    if (l > r) return;
    if (l == tl && r == tr) {
      apply(v, val);
      return;
    }
    push(v);
    ll tm = (tl + tr) / 2;
    updatep(v * 2, tl, tm, l, min(r, tm), val);
    updatep(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    tree[v] = operation(tree[v * 2], tree[v * 2 + 1]);
  }

  T query(ll l, ll r) {
    return queryp(1, 0, n - 1, l, r);
  }

  T queryp(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) return default_value;
    if (l == tl && r == tr) return tree[v];
    push(v);
    ll tm = (tl + tr) / 2;
    return operation(
        queryp(v * 2, tl, tm, l, min(r, tm)),
        queryp(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
};
void solve() {
  int n;
  cin >> n;
  vi a(n);
  read(a, n);

  LazySegmentTree<int> dp1(n + 2), dp2(n + 2);
  int mx = 0;

  vi mdp1(n + 2), mdp2(n + 2);
  fo(i, n) {
    int v = dp1.query(a[i] + 1, n + 1);
    dp1.update(a[i], v + 1);
    mdp1[a[i]] = v + 1;
    dp1.update(0, a[i] - 1, 0);
  }
  re(i, n) {
    int v = dp2.query(a[i] + 1, n + 1);
    dp2.update(a[i], v + 1);
    mdp2[a[i]] = v + 1;
    dp2.update(0, a[i] - 1, 0);
  }
  int ans = 0;
  fo(i, n) {
    int v1 = mdp1[a[i]];
    int v2 = mdp2[a[i]];
    ans = max(ans, v1 + v2 - 1);
  }
  cout << n - ans << endl;
}
