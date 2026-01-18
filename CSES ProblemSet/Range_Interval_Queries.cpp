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
  int n, base;
  vector<T> tree;
  int c, d;

  SegmentTree(int _n) {
    n = _n;
    base = 1;
    while (base < n) base <<= 1;
    tree.resize(2 * base);
  }

  // Iterative build
  void build(const vector<int>& a) {
    // leaves
    for (int i = 0; i < n; i++)
      tree[base + i].push_back(a[i]);

    // internal nodes
    for (int i = base - 1; i >= 1; i--) {
      auto& L = tree[i << 1];
      auto& R = tree[i << 1 | 1];
      tree[i].resize(L.size() + R.size());
      merge(L.begin(), L.end(), R.begin(), R.end(), tree[i].begin());
    }
  }

  inline int count_in_node(const T& v) const {
    return upper_bound(v.begin(), v.end(), d) -
           lower_bound(v.begin(), v.end(), c);
  }

  // Iterative query
  int sum(int l, int r, int c1, int d1) {
    c = c1;
    d = d1;

    l += base;
    r += base;

    int res = 0;
    while (l <= r) {
      if (l & 1) res += count_in_node(tree[l++]);
      if (!(r & 1)) res += count_in_node(tree[r--]);
      l >>= 1;
      r >>= 1;
    }
    return res;
  }
};

void solve1() {
  int n, q;
  cin >> n >> q;
  vi a(n);
  read(a, n);
  SegmentTree<vi> st(n);
  st.build(a);

  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << st.sum(a - 1, b - 1, c, d) << endl;
  }
}

struct WaveletTree {
  int lo, hi;
  WaveletTree *l, *r;
  vector<int> pref;

  WaveletTree(vector<int>& arr, int L, int R) : lo(L), hi(R), l(nullptr), r(nullptr) {
    if (arr.empty() || lo == hi) return;

    int mid = (lo + hi) >> 1;

    vector<int> left, right;
    left.reserve(arr.size());
    right.reserve(arr.size());

    pref.reserve(arr.size() + 1);
    pref.push_back(0);

    for (int x : arr) {
      if (x <= mid) {
        left.push_back(x);
        pref.push_back(pref.back() + 1);
      } else {
        right.push_back(x);
        pref.push_back(pref.back());
      }
    }

    if (!left.empty()) l = new WaveletTree(left, lo, mid);
    if (!right.empty()) r = new WaveletTree(right, mid + 1, hi);
  }

  inline int query(int lq, int rq, int k1, int k2) const {
    if (lq > rq || k2 < lo || hi < k1) return 0;
    if (k1 <= lo && hi <= k2) return rq - lq + 1;

    int lb = pref[lq - 1];
    int rb = pref[rq];

    int res = 0;
    if (l) res += l->query(lb + 1, rb, k1, k2);
    if (r) res += r->query(lq - lb, rq - rb, k1, k2);
    return res;
  }
};

void solve2() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (int& x : a) cin >> x;

  vector<int> comp = a;
  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());

  for (int& x : a)
    x = lower_bound(comp.begin(), comp.end(), x) - comp.begin();

  int sigma = (int)comp.size() - 1;

  WaveletTree wt(a, 0, sigma);

  while (q--) {
    int l, r, c, d;
    cin >> l >> r >> c >> d;

    int lc = lower_bound(comp.begin(), comp.end(), c) - comp.begin();
    int rc = upper_bound(comp.begin(), comp.end(), d) - comp.begin() - 1;

    if (lc > rc) {
      cout << 0 << '\n';
    } else {
      cout << wt.query(l, r, lc, rc) << '\n';
    }
  }
}

signed main() {
  fastio;
  solve1();
}
