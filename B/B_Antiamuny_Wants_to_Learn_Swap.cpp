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
// Segment Tree
struct SegmentTree {
  vector<ll> tree;  // segment tree
  ll n;             // size of the array
  SegmentTree(ll n) {
    this->n = n;
    tree.resize(4 * n);  // size of the segment tree is 4 times the size of the array
  }
  void build(vector<ll> &a) {
    buildp(a, 1, 0, n - 1);
  }
  ll sum(ll l, ll r) {
    return sump(1, 0, n - 1, l, r);
  }
  void update(ll pos, ll new_val) {
    updatep(1, 0, n - 1, pos, new_val);
  }
  ll operation(ll l, ll r) {
    return max(l, r);
    // sum, // max, // min, // gcd, // lcm, // xor, // or, // and, // product,
    // change the operation according to the query
  }

  void buildp(vector<ll> &a, ll v, ll tl, ll tr) {
    // a is the array, v is the index of the node, tl and tr are the range of the node

    if (tl == tr)  // if the node is a leaf node
    {
      tree[v] = a[tl];  // store the value of the array in the node
    } else {
      ll tm = (tl + tr) / 2;                              // find the middle of the range
      buildp(a, v * 2, tl, tm);                           // build the left subtree
      buildp(a, v * 2 + 1, tm + 1, tr);                   // build the right subtree
      tree[v] = operation(tree[v * 2], tree[v * 2 + 1]);  // merge the left and right subtree
    }
  }
  ll sump(ll v, ll tl, ll tr, ll l, ll r) {
    // v is the index of the node, tl and tr are the range of the node, l and r are the range of the query
    if (l > r) {
      return -1;
    }
    if (l == tl && r == tr) {
      return tree[v];
    }
    ll tm = (tl + tr) / 2;
    return operation(sump(v * 2, tl, tm, l, min(r, tm)), sump(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));  // merge the left and right subtree
  }
  void updatep(ll v, ll tl, ll tr, ll pos, ll new_val) {
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
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  fo(i, n) cin >> a[i];
  vi left(n);
  stack<pair<int, int>> s;
  for (int i = 0; i < n; ++i) {
    while (!s.empty() && s.top().first < a[i]) {
      s.pop();
    }
    if (s.empty()) {
      left[i] = -1;
    } else {
      left[i] = s.top().second;
    }
    s.push({a[i], i});
  }
  SegmentTree st(n + 1);
  vi b(n + 1, -1);
  st.build(b);
  vi len2(n);
  fo(i, n) {
    len2[i] = st.sum(a[i], n);
    st.update(a[i], left[i]);
  }
  debug(len2);
  SegmentTree st2(n);
  st2.build(len2);
  fo(i, q) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    debug(l, r);
    if (st2.sum(l, r) < l) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
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
