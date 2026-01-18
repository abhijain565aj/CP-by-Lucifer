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
// Segment Tree
template <typename T>
struct SegmentTree {
  vector<T> tree;
  ll n;
  SegmentTree(ll n) {
    this->n = n;
    tree.resize(4 * n);
  }
  void build(vector<int>& a) {
    vector<T> A(n);
    fo(i, n) A[i].pb(a[i]);
    buildp(A, 1, 0, n - 1);
  }
  pii sum(ll l, ll r) {
    pii ans = {0, -INF};
    sump(ans, 1, 0, n - 1, l, r);
    return ans;
  }
  void update(ll pos, T new_val) {
    updatep(1, 0, n - 1, pos, new_val);
  }
  T operation(T l, T r) {
    auto temp = l;
    for (auto x : r) {
      if (x > *temp.rbegin())
        temp.pb(x);
    }
    return temp;
    // change this
  }
  void operation2(pii& ans, T& r) {
    int cnt = r.size() - (upper_bound(all(r), ans.S) - r.begin());
    debug(ans, r, cnt);
    ans.F += cnt;
    ans.S = max(ans.S, *r.rbegin());
    debug(ans);
  }

  void buildp(vector<T>& a, ll v, ll tl, ll tr) {
    if (tl == tr) {
      tree[v] = a[tl];
    } else {
      ll tm = (tl + tr) / 2;
      buildp(a, v * 2, tl, tm);
      buildp(a, v * 2 + 1, tm + 1, tr);
      tree[v] = operation(tree[v * 2], tree[v * 2 + 1]);
    }
  }

  void sump(pii& ans, ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) {
      return;
    }
    if (l == tl && r == tr) {
      operation2(ans, tree[v]);
      return;
    }
    ll tm = (tl + tr) / 2;
    sump(ans, v * 2, tl, tm, l, min(r, tm));
    sump(ans, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
  }
};

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int n, q;
  cin >> n >> q;
  vi a(n);
  read(a, n);
  SegmentTree<vi> st(n);
  st.build(a);

  while (q--) {
    int a, b;
    cin >> a >> b;
    debug(a, b);
    cout << st.sum(a - 1, b - 1).F << endl;
  }
}
