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

template <typename T>
struct SegmentTree {
  vector<T> tree;
  ll n;
  unordered_map<int, vi> mp;
  SegmentTree(ll n) {
    this->n = n;
    tree.resize(4 * n);
  }
  void build(vector<int>& a) {
    v(vi) b(n, vi(2));
    fo(i, n) b[i] = {a[i]};
    fo(i, n) mp[a[i]].pb(i);
    buildp(b, 1, 0, n - 1);
  }
  int count(int x, int l, int r) {
    int res = upper_bound(all(mp[x]), r) - lower_bound(all(mp[x]), l);
    return res;
  }
  vi sum(ll l, ll r) {
    auto ans = sump(1, 0, n - 1, l, r);
    int v = (r - l + 1) / 3;
    vi res;
    for (auto x : ans) {
      if (count(x, l, r) > v) res.pb(x);
    }
    sortall(res);
    return res;
  }
  T operation(T l, T r, int tl, int tr) {
    set<int> s;
    for (auto x : l) s.insert(x);
    for (auto x : r) s.insert(x);
    vi res;
    for (auto x : s) {
      auto r = count(x, tl, tr);
      if (r > (tr - tl + 1) / 3) res.pb(x);
    }
    return res;
  }

  void buildp(vector<T>& a, ll v, ll tl, ll tr) {
    if (tl == tr) {
      tree[v] = a[tl];
    } else {
      ll tm = (tl + tr) / 2;
      buildp(a, v * 2, tl, tm);
      buildp(a, v * 2 + 1, tm + 1, tr);
      tree[v] = operation(tree[v * 2], tree[v * 2 + 1], tl, tr);
    }
  }
  T sump(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) {
      return {-1, -1};
    }
    if (l == tl && r == tr) {
      return tree[v];
    }
    ll tm = (tl + tr) / 2;
    return operation(sump(v * 2, tl, tm, l, min(r, tm)), sump(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r), l, r);
  }
};

void solve() {
  int n, q;
  cin >> n >> q;
  vi a(n);
  read(a, n);
  SegmentTree<vi> seg(n);
  seg.build(a);
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    vi res = seg.sum(l, r);
    if (res.size() == 0) {
      cout << -1 << endl;
      continue;
    }
    for (auto x : res) {
      cout << x << " ";
    }
    cout << endl;
  }
}

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1000;
  cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
