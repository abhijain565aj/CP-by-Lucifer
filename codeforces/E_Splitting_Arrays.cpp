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
#include "./DEBUG.cpp"
#define local true
#else
#define debug(...)
#define Test(tt)
#define Error_file(x)
#define local false
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

#define fo(i, n) for (int i = 0; i < n; i++)
#define re(i, n) for (int i = n - 1; i >= 0; i--)
#define loop(i, a, b) for (int i = a; (a >= b) ? i >= b : i <= b; (a >= b) ? i-- : i++)

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
#define print(a, n) \
  for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');

void file(string s = "") {
  if (local) {
    // freopen("error.txt", "w", stderr);
    // freopen("output.txt", "w", stdout);
    // freopen(("input" + s + ".txt").c_str(), "r", stdin);
    return;
  }
}

constexpr int MOD = 1000000007;
constexpr int N = 1e5 + 1;
constexpr int INF = 1e18;

void solve();
void precompute();

signed main() {
  fastio;
  file();
  precompute();

  int testCases = 1;
  cin >> testCases;

  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}

void precompute() {
}

template <typename T>
struct SegmentTree {
  vector<T> tree;
  int n;
  T default_value;
  function<T(T, T)> merge;
  SegmentTree(
      int n,
      T default_value = 0,
      function<T(T, T)> merge = [](T l, T r) { return l + r; }) {
    this->n = n;
    this->default_value = default_value;
    this->merge = merge;
    tree.resize(4 * n);
  }
  void build(vector<T>& a) {
    buildp(a, 1, 0, n - 1);
  }
  T query(int l, int r) {
    return queryp(1, 0, n - 1, l, r);
  }
  void buildp(vector<T>& a, int v, int tl, int tr) {
    if (tl == tr) {
      tree[v] = a[tl];
    } else {
      int tm = (tl + tr) / 2;
      buildp(a, v * 2, tl, tm);
      buildp(a, v * 2 + 1, tm + 1, tr);
      tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
  }
  T queryp(int v, int tl, int tr, int l, int r) {
    if (l > r) {
      return default_value;
    }
    if (l == tl && r == tr) {
      return tree[v];
    }
    int tm = (tl + tr) / 2;
    return merge(queryp(v * 2, tl, tm, l, min(r, tm)), queryp(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
};
struct Node {
  int lsum_max = 0, rsum_max = 0;
  int rsum_min = 0, lsum_min = 0;
  int sum = 0;
  int max_ans = 0;
  int min_ans = 0;
  // vi presum;
  Node() {
  }
  Node(int v) {
    // presum.pb(v);
    lsum_min = min(lsum_min, v);
    lsum_max = max(lsum_max, v);
    rsum_min = min(rsum_min, v);
    rsum_max = max(rsum_max, v);
    sum = v;
    max_ans = max(max_ans, v);
    min_ans = min(min_ans, v);
  }
  Node operator+(const Node& rhs) {
    Node temp;
    temp.sum = sum + rhs.sum;
    temp.lsum_max = max(lsum_max, sum + rhs.lsum_max);
    temp.lsum_min = min(lsum_min, sum + rhs.lsum_min);
    temp.rsum_max = max(rhs.rsum_max, rhs.sum + rsum_max);
    temp.rsum_min = min(rhs.rsum_min, rhs.sum + rsum_min);
    temp.max_ans = max({max_ans, rhs.max_ans, rsum_max + rhs.lsum_max});
    temp.min_ans = min({min_ans, rhs.min_ans, rsum_min + rhs.lsum_min});
    return temp;
  }

  int ans() {
    debug(lsum_max, lsum_min, rsum_max, rsum_min, sum);
    int ans = abs(sum);                                   // all 0 or all 1
    // ans = max(ans, abs(lsum_min) + abs(sum - lsum_min));  // 0 1 1
    // ans = max(ans, abs(sum - rsum_max) + abs(rsum_max));  // 0 0 1
    // ans = max(ans, abs(lsum_max) + abs(sum - lsum_max));  // 1 0 0
    // ans = max(ans, abs(sum - rsum_min) + abs(rsum_min));  // 1 1 0
    ans = max(ans, abs(sum - max_ans) + abs(max_ans));    // 0 1 0
    ans = max(ans, abs(sum - min_ans) + abs(min_ans));    // 1 0 1
    // ans = max(ans, abs(lsum_min) + abs(rsum_min) + abs(sum - rsum_min - lsum_min));  // 0 1 0
    // ans = max(ans, abs(lsum_max) + abs(rsum_max) + abs(sum - lsum_max - rsum_max));  // 1 0 1
    return ans;
  }
};
void solve() {
  int n, q;
  cin >> n >> q;
  vi a(n);
  read(a, n);
  fo(i, n) if (a[i] == 0) a[i] = -1;
  vector<Node> nodes(n);
  fo(i, n) nodes[i] = Node(a[i]);
  SegmentTree<Node> seg(n);
  seg.build(nodes);
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    auto node = seg.query(l, r);
    cout << node.ans() << endl;
  }
}
