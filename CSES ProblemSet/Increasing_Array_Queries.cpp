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
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
    freopen(("input" + s + ".txt").c_str(), "r", stdin);
  }
}

constexpr int MOD = 1000000007;
constexpr int N = 1e5 + 1;
constexpr int INF = 1e18;

template <typename T>
struct SegmentTree {
  vector<T> tree;
  int n;
  int default_value = 0;
  vi nxt;
  function<T(T, T)> merge = [](T l, T r) { return l + r; };
  SegmentTree(
      int n,
      vi& nxt) {
    this->n = n;
    swap(this->nxt, nxt);
    tree.resize(4 * n);
  }

  void build(vector<T>& a) {
    buildp(a, 1, 0, n - 1);
  }

  int query(int l, int r) {
    vi ind;
    queryp(1, 0, n - 1, l, r, ind);
    int ans = tree[ind[0]].getAns();
    auto [mx, mxi] = tree[ind[0]].getMax();
    for (int i = 1; i < (int)ind.size(); i++) {
      auto& nd = tree[ind[i]];
      ans += nd.getAns();
      ans += nd.fn(mx, nxt[mxi]);
      auto v = nd.getMax();
      // mx = max(nd.getMax(), mx);
      if (v.F >= mx) {
        mx = v.F;
        mxi = v.S;
      }
    }
    return ans;
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
  void queryp(int v, int tl, int tr, int l, int r, vi& ind) {
    if (l > r) {
      return;
    }
    if (l == tl && r == tr) {
      ind.pb(v);
      return;
    }
    int tm = (tl + tr) / 2;
    queryp(v * 2, tl, tm, l, min(r, tm), ind);
    queryp(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, ind);
    return;
  }
};
struct Node {
  vector<int> mx;
  vector<int> mxp;
  int mxi;
  int l, r;
  int ans;
  Node() {}
  Node(int j, int i) : mxi(i), l(i), r(i), ans(0) {
    mx = mxp = {j};
  }
  Node(vector<int>& nmx, vector<int>& nmxp, int nmxi, int nans, int l, int r) : mxi(nmxi), l(l), r(r), ans(nans) {
    swap(nmx, mx);
    swap(nmxp, mxp);
  }
  Node operator+(const Node& o) {
    vi nmx = mx;
    vi nmxp = mxp;
    int nans = ans + o.ans;
    for (auto x : o.mx) {
      nmx.pb(std::max(nmx.back(), x));
      nans += nmx.back() - x;
      nmxp.pb(nmxp.back() + nmx.back());
    }
    // debug(mx, o.mx, nmx, nans);
    int nmxi = mxi;
    if (nmx.back() == o.mx.back()) nmxi = o.mxi;
    return Node(nmx, nmxp, nmxi, nans, l, o.r);
  }
  inline int getAns() {
    return ans;
  }
  inline pii getMax() {
    return {mx.back(), mxi};
  }
  int fn(int m, int ind) {
    int i = min(ind - l, (int)mx.size());
    // int i = lower_bound(all(mx), m) - mx.begin();
    if (i == 0)
      return 0;
    return m * i - mxp[i - 1];
  }
};
signed main() {
  fastio;
  int n, q;
  cin >> n >> q;
  vi arr(n);
  vector<Node> a(n);
  fo(i, n) {
    cin >> arr[i];
    a[i] = Node(arr[i], i);
  }
  vi nxt(n);
  stack<pii> st;
  st.push({INF, n});
  re(i, n) {
    while (st.top().F <= arr[i]) st.pop();
    nxt[i] = st.top().S;
    st.push({arr[i], i});
  }
  SegmentTree<Node> segmentTree(n, nxt);
  segmentTree.build(a);
  while (q--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    cout << segmentTree.query(a, b) << endl;
  }
}