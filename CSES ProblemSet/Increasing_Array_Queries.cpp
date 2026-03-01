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

constexpr int MOD = 1000000007;
constexpr int N = 1e5 + 1;
constexpr int INF = 1e18;

void solve();
void precompute();

template <typename T>
struct SegmentTree {
  vector<T> tree;
  int n;
  int default_value;
  SegmentTree(
      int n,
      int default_value = 0) {
    this->n = n;
    this->default_value = default_value;
    tree.resize(4 * n);
  }

  void build(vector<T>& a) {
    buildp(a, 1, 0, n - 1);
  }

  int query(int l, int r) {
    int ans = 0, mx = 0;
    vector<array<int, 3>> st;
    st.pb({1, 0, n - 1});
    while (!st.empty()) {
      auto [v, tl, tr] = st.back();
      st.pop_back();

      if (l > tr || r < tl) continue;
      if (l <= tl && tr <= r) {
        auto& nd = tree[v];
        ans += nd.getAns();
        ans += nd.fn(mx);
        mx = max(mx, nd.getMax());
        continue;
      }

      int tm = (tl + tr) >> 1;
      st.pb({v * 2 + 1, tm + 1, tr});
      st.pb({v * 2, tl, tm});
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
      tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
  }
};

struct Node {
  vector<int> mx;
  vector<int> mxp;
  int ans;
  Node() {}
  Node(int j) {
    mx = mxp = {j};
    ans = 0;
  }
  Node(vector<int>& nmx, vector<int>& nmxp, int nans) {
    swap(nmx, mx);
    swap(nmxp, mxp);
    ans = nans;
  }
  Node operator+(const Node& o) {
    vi nmx, nmxp;
    nmx.reserve(mx.size() + o.mx.size());
    nmxp.reserve(mx.size() + o.mx.size());
    for (auto x : mx) nmx.pb(x);
    for (auto x : mxp) nmxp.pb(x);
    int nans = ans + o.ans;
    for (auto x : o.mx) {
      nmx.pb(std::max(nmx.back(), x));
      nans += nmx.back() - x;
      nmxp.pb(nmxp.back() + nmx.back());
    }
    // debug(mx, o.mx, nmx, nans);
    return Node(nmx, nmxp, nans);
  }
  inline int getAns() const {
    return ans;
  }
  inline int getMax() const {
    return mx.back();
  }
  inline int fn(int m) const {
    int i = lower_bound(all(mx), m) - mx.begin();
    if (i == 0)
      return 0;
    return m * i - mxp[i - 1];
  }
};

signed main() {
  fastio;
  int n, q;
  cin >> n >> q;
  vector<Node> a(n);
  fo(i, n) {
    int x;
    cin >> x;
    a[i] = Node(x);
  }
  SegmentTree<Node> st(n);
  st.build(a);
  while (q--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    cout << st.query(a, b) << endl;
  }
}
