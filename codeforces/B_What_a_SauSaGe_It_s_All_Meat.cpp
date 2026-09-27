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

// #define int long long
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
// constexpr int INF = 1e18;

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

set<int> pos_xors;  // 0 3 5 6 9 10 12 15
void precompute() {
  vi arr = {3, 6, 9, 12, 15};
  for (int i = 0; i < 32; i++) {
    int sum = 0;
    for (int j = 0; j < 5; j++) {
      if (i & (1 << j)) {
        sum ^= arr[j];
      }
    }
    pos_xors.insert(sum);
  }

  // for (auto x : pos_xors) {
  //   {
  //     cout << x << ": ";
  //     for (int j = 0; j < 16; j++) {
  //       if ((x ^ j) % 3 == 0) {
  //         cout << j << " ";
  //       }
  //     }
  //     cout << endl;
  //   }
  // }
}
array<int, 8> xors = {0, 3, 6, 9, 12, 15, 10, 5};
class Node {
 public:
  array<array<int, 8>, 8> v = {0};
  Node() {
  };
  Node(int x) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        v[i][j] = xors[i] ^ xors[j] ^ x;
        v[i][j] = (v[i][j] % 3 == 0) ? 1 : 0;
      }
    }
  }
};

Node merge(Node a, Node b) {
  Node res;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      for (int k = 0; k < 8; k++) {
        res.v[i][j] = max(res.v[i][j], a.v[i][k] + b.v[k][j]);
      }
    }
  }
  return res;
}

template <typename T>
struct SegmentTree {
  vector<T> tree;
  int n;
  T default_value;
  SegmentTree(int n) {
    this->n = n;
    this->default_value = default_value;
    tree.resize(4 * n);
  }
  void build(vector<T>& a) {
    buildp(a, 1, 0, n - 1);
  }
  T query(int l, int r) {
    return queryp(1, 0, n - 1, l, r);
  }
  void update(int pos, T new_val) {
    updatep(1, 0, n - 1, pos, new_val);
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
      return Node();
    }
    if (l == tl && r == tr) {
      return tree[v];
    }
    int tm = (tl + tr) / 2;
    return merge(queryp(v * 2, tl, tm, l, min(r, tm)), queryp(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
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
      tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
  }
};

void solve() {
  int n, q;
  cin >> n >> q;
  vi a(n);
  read(a, n);

  // int ans = 0;
  // for (auto x : a) {
  //   ans += pos_xors.count(x);
  // }
  // cout << ans << " ";
  // while (q--) {
  //   int i, x;
  //   cin >> i >> x;
  //   ans -= pos_xors.count(a[i - 1]);
  //   ans += pos_xors.count(x);
  //   cout << ans << " ";
  // }
  // cout << endl;
  SegmentTree<Node> st(n);
  vector<Node> nodes(n);
  for (int i = 0; i < n; i++) {
    nodes[i] = Node(a[i]);
  }
  st.build(nodes);
  cout << st.query(0, n - 1).v[0][0] << " ";
  while (q--) {
    int i, x;
    cin >> i >> x;
    st.update(i - 1, Node(x));
    Node res = st.query(0, n - 1);
    cout << res.v[0][0] << " ";
  }
  cout << endl;
}
