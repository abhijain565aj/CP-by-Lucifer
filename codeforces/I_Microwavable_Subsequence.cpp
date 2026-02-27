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
  SegmentTree(ll n) {
    this->n = n;
    tree.resize(4 * n);
  }
  void build(vector<T>& a) {
    buildp(a, 1, 0, n - 1);
  }
  T sum(ll l, ll r) {
    return sump(1, 0, n - 1, l, r);
  }
  void update(ll pos, T new_val) {
    updatep(1, 0, n - 1, pos, new_val);
  }
  T operation(T l, T r) {
    return l + r;
    // change this
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
  T sump(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) {
      return 0;
    }
    if (l == tl && r == tr) {
      return tree[v];
    }
    ll tm = (tl + tr) / 2;
    return operation(sump(v * 2, tl, tm, l, min(r, tm)), sump(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
  void updatep(ll v, ll tl, ll tr, ll pos, T new_val) {
    if (tl == tr) {
      tree[v] = new_val;
    } else {
      ll tm = (tl + tr) / 2;
      if (pos <= tm) {
        updatep(v * 2, tl, tm, pos, new_val);
      } else {
        updatep(v * 2 + 1, tm + 1, tr, pos, new_val);
      }
      tree[v] = operation(tree[v * 2], tree[v * 2 + 1]);
    }
  }
};

signed main() {
  fastio;
  int n, m;
  cin >> n >> m;
  vi a(n);
  read(a, n);
  map<int, int> last_r;
  fo(i, n) last_r[a[i]] = n;
  vi b(n);
  re(i, n) {
    b[i] = last_r[a[i]];
    last_r[a[i]] = i;
  }
  // 1 2 -> 3
  // 1 3 -> 3
  // 2 3 -> 4
  vi c(n);
  fo(i, n) if (last_r[a[i]] == i) c[i] = 1;
  SegmentTree<int> seg(n);
  seg.build(c);
  int ans = (m - last_r.size()) * last_r.size();
  for (auto [_, r] : last_r) {
    ans += seg.sum(0, r - 1);
  }
  fo(i, n) {
    int cnt = seg.sum(i, b[i] - 1);
    ans += (cnt - 1);
    if (b[i] < n) {
      seg.update(b[i], 1);
    }
    debug(ans);
  }
  cout << ans << endl;
}
