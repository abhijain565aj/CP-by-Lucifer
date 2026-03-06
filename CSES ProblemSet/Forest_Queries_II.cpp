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
struct SegTree2D {
  int n, m;
  vector<vector<int>> a, t;
  SegTree2D(int n, int m) : n(n), m(m) {
    a.assign(n, vector<int>(m));
    t.assign(4 * n, vector<int>(4 * m));
  }
  SegTree2D(vector<vector<int>> a) {
    n = a.size(), m = a[0].size();
    this->a = a;
    t.assign(4 * n, vector<int>(4 * m));
  }
  void build() {
    build_x(1, 0, n - 1);
  }
  int query(int x1, int y1, int x2, int y2) {
    return qry_x(1, 0, n - 1, x1, x2, y1, y2);
  }
  void update(int x1, int y1) {
    a[x1][y1] ^= 1;
    upd_x(1, 0, n - 1, x1, y1, a[x1][y1]);
  }
  void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
      if (lx == rx)
        t[vx][vy] = a[lx][ly];
      else
        t[vx][vy] = t[vx << 1][vy] + t[vx << 1 | 1][vy];
    } else {
      int my = (ly + ry) >> 1;
      build_y(vx, lx, rx, vy << 1, ly, my);
      build_y(vx, lx, rx, vy << 1 | 1, my + 1, ry);
      t[vx][vy] = t[vx][vy << 1] + t[vx][vy << 1 | 1];
    }
  }
  void build_x(int vx, int lx, int rx) {
    if (lx != rx) {
      int mx = (lx + rx) >> 1;
      build_x(vx << 1, lx, mx);
      build_x(vx << 1 | 1, mx + 1, rx);
    }
    build_y(vx, lx, rx, 1, 0, m - 1);
  }
  int qry_y(int vx, int vy, int ly, int ry, int ql, int qr) {
    if (ql > qr) return 0;
    if (ql == ly && qr == ry) return t[vx][vy];
    int my = (ly + ry) >> 1;
    return qry_y(vx, vy << 1, ly, my, ql, min(qr, my)) + qry_y(vx, vy << 1 | 1, my + 1, ry, max(ql, my + 1), qr);
  }
  int qry_x(int vx, int lx, int rx, int x1, int x2, int y1, int y2) {
    if (x1 > x2) return 0;
    if (x1 == lx && x2 == rx) return qry_y(vx, 1, 0, m - 1, y1, y2);
    int mx = (lx + rx) >> 1;
    return qry_x(vx << 1, lx, mx, x1, min(x2, mx), y1, y2) + qry_x(vx << 1 | 1, mx + 1, rx, max(x1, mx + 1), x2, y1, y2);
  }
  void upd_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int v) {
    if (ly == ry) {
      if (lx == rx)
        t[vx][vy] = v;
      else
        t[vx][vy] = t[vx << 1][vy] + t[vx << 1 | 1][vy];
    } else {
      int my = (ly + ry) >> 1;
      if (y <= my)
        upd_y(vx, lx, rx, vy << 1, ly, my, x, y, v);
      else
        upd_y(vx, lx, rx, vy << 1 | 1, my + 1, ry, x, y, v);
      t[vx][vy] = t[vx][vy << 1] + t[vx][vy << 1 | 1];
    }
  }
  void upd_x(int vx, int lx, int rx, int x, int y, int v) {
    if (lx != rx) {
      int mx = (lx + rx) >> 1;
      if (x <= mx)
        upd_x(vx << 1, lx, mx, x, y, v);
      else
        upd_x(vx << 1 | 1, mx + 1, rx, x, y, v);
    }
    upd_y(vx, lx, rx, 1, 0, m - 1, x, y, v);
  }
};
signed main() {
  fastio;
  int n, q;
  cin >> n >> q;
  vs s(n);
  for (auto& x : s) cin >> x;
  vvi a(n, vi(n));
  fo(i, n) fo(j, n) a[i][j] = s[i][j] == '*';
  SegTree2D st(a);
  st.build();
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x1, y1;
      cin >> x1 >> y1;
      st.update(x1 - 1, y1 - 1);
    } else {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      x1--, x2--, y1--, y2--;
      cout << st.query(x1, y1, x2, y2) << "\n";
    }
  }
}
