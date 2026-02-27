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
    return max(l, r);
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
      return {-1, -1};
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

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vi a(m);
  read(a, m);
  sortall(a);
  v(pii) b(n);
  fo(i, n) {
    int x, y, z;
    cin >> x >> y >> z;
    k -= y;
    z -= y;
    b[i] = {x, z};
  }
  sortall(b);
  v(pii) s(n);
  fo(i, n) s[i] = {b[i].S, i};
  SegmentTree<pii> st(n);
  st.build(s);
  debug(a, b);
  fo(i, m) {
    int ind = upper_bound(all(b), make_pair(a[i], INF)) - b.begin();
    debug(ind);
    if (ind == 0)
      continue;
    else
      ind--;
    auto [v, j] = st.sum(0, ind);
    debug(v, j);
    if (v == -1)
      continue;
    else {
      s[j] = {-1, j};
      st.update(j, s[j]);
    }
  }
  debug(s);
  int ans = 0;
  vi rem;
  fo(i, n) if (s[i].F == -1) ans++;
  else rem.pb(s[i].F);
  sortall(rem);
  for (auto& x : rem) {
    if (k >= x) k -= x, ans++;
  }
  cout << ans << endl;
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
