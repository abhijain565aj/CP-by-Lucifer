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
  int n;
  vector<T> tree, lazy;

  LazySegmentTree(int n) : n(n) {
    tree.assign(4 * n, 0);
    lazy.assign(4 * n, 0);
  }

  // Build from array
  void build(const vector<T>& a) {
    build(1, 0, n - 1, a);
  }

  // Range sum query
  T sum(int l, int r) {
    return query(1, 0, n - 1, l, r);
  }

  // Range add update
  void update(int l, int r, T val) {
    update(1, 0, n - 1, l, r, val);
  }

 private:
  void build(int v, int tl, int tr, const vector<T>& a) {
    if (tl == tr) {
      tree[v] = a[tl];
    } else {
      int tm = (tl + tr) / 2;
      build(v * 2, tl, tm, a);
      build(v * 2 + 1, tm + 1, tr, a);
      tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
  }

  void push(int v, int tl, int tr) {
    if (lazy[v] != 0 && tl != tr) {
      int tm = (tl + tr) / 2;

      // left child
      tree[v * 2] += lazy[v] * (tm - tl + 1);
      lazy[v * 2] += lazy[v];

      // right child
      tree[v * 2 + 1] += lazy[v] * (tr - tm);
      lazy[v * 2 + 1] += lazy[v];
    }
    lazy[v] = 0;
  }

  void update(int v, int tl, int tr, int l, int r, T val) {
    if (l > r) return;

    if (l == tl && r == tr) {
      tree[v] += val * (tr - tl + 1);
      lazy[v] += val;
    } else {
      push(v, tl, tr);
      int tm = (tl + tr) / 2;
      update(v * 2, tl, tm, l, min(r, tm), val);
      update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
      tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
  }

  T query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;

    if (l == tl && r == tr) {
      return tree[v];
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
  }
};

void solve() {
  int n;
  cin >> n;
  vi a(n);
  read(a, n);
  v(pii) s;
  s.pb({a[0], 0});
  vi par(n);
  par[0] = -1;
  fo1(i, 1, n) {
    while (!s.empty() && a[i] != s.back().first + 1) {
      s.pop_back();
    }
    if (s.empty()) {
      par[i] = -1;
    } else {
      par[i] = s.back().second;
    }
    s.pb({a[i], i});
  }
  LazySegmentTree<int> seg(n);
  vi b(n);
  b[0] = 1;
  fo1(i, 1, n) {
    if (par[i] == -1) {
      b[i] = b[i - 1] + 1;
    } else {
      b[i] = b[i - 1];
    }
  }
  seg.build(b);

  vvi adj(n);
  fo(i, n) {
    if (par[i] != -1) {
      adj[par[i]].pb(i);
    }
  }
  int ans = 0;
  fo(i, n) {
    // vi temp;
    // fo(j, n) {
    //   temp.pb(seg.sum(j, j));
    // }
    ans += seg.sum(i, n - 1);
    seg.update(i, n - 1, -1);
    for (int child : adj[i]) {
      seg.update(child, n - 1, 1);
    }
  }
  cout << ans << endl;
}
