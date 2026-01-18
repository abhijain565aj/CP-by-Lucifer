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

struct node {
  int min1;
  int min2;
  int max1;
  int max2;
  int ans1;
  int ans2;
  node() {
    min1 = min2 = INF;
    max1 = max2 = -INF;
    ans1 = ans2 = 0;
  }
  node(int ind, int val) {
    min1 = max1 = val - ind;
    min2 = max2 = val + ind;
    ans1 = ans2 = 0;
  }
};
node op(node& l, node& r) {
  node n;
  n.min1 = min(l.min1, r.min1);
  n.min2 = min(l.min2, r.min2);
  n.max1 = max(l.max1, r.max1);
  n.max2 = max(l.max2, r.max2);
  n.ans1 = max({l.ans1, r.ans1, r.max1 - l.min1});
  n.ans2 = max({l.ans2, r.ans2, l.max2 - r.min2});
  return n;
}
template <typename T>
struct SegmentTree {
  vector<T> tree;  // segment tree
  int n;           // size of the array
  SegmentTree(int n) {
    this->n = n;
    tree.resize(4 * n);  // size of the segment tree is 4 times the size of the array
  }
  void build(vector<T>& a) {
    buildp(a, 1, 0, n - 1);
  }
  T sum(int l, int r) {
    return sump(1, 0, n - 1, l, r);
  }
  void update(int pos, T new_val) {
    updatep(1, 0, n - 1, pos, new_val);
  }
  T operation(T l, T r) {
    return op(l, r);
    // sum, // max, // min, // gcd, // lcm, // xor, // or, // and, // product,
    // change the operation according to the query
  }

  void buildp(vector<T>& a, int v, int tl, int tr) {
    // a is the array, v is the index of the node, tl and tr are the range of the node

    if (tl == tr)  // if the node is a leaf node
    {
      tree[v] = a[tl];  // store the value of the array in the node
    } else {
      int tm = (tl + tr) / 2;                             // find the middle of the range
      buildp(a, v * 2, tl, tm);                           // build the left subtree
      buildp(a, v * 2 + 1, tm + 1, tr);                   // build the right subtree
      tree[v] = operation(tree[v * 2], tree[v * 2 + 1]);  // merge the left and right subtree
    }
  }
  T sump(int v, int tl, int tr, int l, int r) {
    // v is the index of the node, tl and tr are the range of the node, l and r are the range of the query
    if (l > r) {
      return node();
    }
    if (l == tl && r == tr) {
      return tree[v];
    }
    int tm = (tl + tr) / 2;
    return operation(sump(v * 2, tl, tm, l, min(r, tm)), sump(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));  // merge the left and right subtree
  }
  void updatep(int v, int tl, int tr, int pos, T new_val) {
    if (tl == tr) {
      tree[v] = new_val;
    } else {
      int tm = (tl + tr) / 2;
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
  vi a(n);
  read(a, n);
  v(node) A(n);
  fo(i, n) A[i] = node(i, a[i]);
  SegmentTree<node> st(n);
  st.build(A);

  auto query = [&]() -> void {
    auto ans = st.sum(0, n - 1);
    cout << max(ans.ans1, ans.ans2) << endl;
  };

  query();
  while (q--) {
    int p, x;
    cin >> p >> x;
    A[p - 1] = node(p - 1, x);
    st.update(p - 1, A[p - 1]);
    query();
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
