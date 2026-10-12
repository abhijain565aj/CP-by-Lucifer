// Solution by Abhi Jain for the problem https://codeforces.com/contest/2273/problem/C
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "./Templates/DEBUG.cpp"
#define local true
#else
#define debug(...)
#define Test(tt)
#define local false
#endif

#define int long long

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define v(x) vector<x>

#define YN(possible) cout << ((possible) ? "YES" : "NO") << endl;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back

#define read(a, n) \
  for (int i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) \
  for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');

constexpr int MOD = 1000000007;
constexpr int N = 1e5 + 1;
constexpr int INF = 1e18;

void solve();
void precompute();

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  precompute();

  int _testCases = 1;
  cin >> _testCases;

  for(int _t=0; _t<_testCases; _t++) {
    Test(_t + 1);
    solve();
  }
}

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

void precompute() {
  
}

void solve() {
  int n,q;
  cin>>n>>q;
  vvi a(n,vi(n));
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
    int x;
    cin>>x;
    a[i][j] -= x;
  }

  vvi c(n - 1, vi(n - 1, 0));
  vvi alive(n - 1, vi(n - 1, 0));

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
        c[i][j] = a[i][j] + a[i + 1][j + 1] - a[i][j + 1] - a[i + 1][j];
        alive[i][j] = (c[i][j] != 0);
    }
  }

  SegTree2D st(alive);
  st.build();

  auto fn = [&](int i, int j, int delta) {
    if (i < 0 || i >= n - 1 || j < 0 || j >= n - 1)
        return;
    bool oldAlive = (c[i][j] != 0);
    c[i][j] += delta;
    bool newAlive = (c[i][j] != 0);
    if (oldAlive != newAlive)
        st.update(i, j);
  };

  while (q--) {
    char type;
    int r1, c1, r2, c2;
    cin >> type >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;
    if (type == 'U') {
      int x;
      cin >> x;
      fn(r1-1,c1-1,+x);
      fn(r1-1,c2,-x);
      fn(r2,c1-1,-x);
      fn(r2,c2,+x);
    } else {
      int cnt = 0;
      if (r1 < r2 && c1 < c2)
          cnt = st.query(r1, c1, r2 - 1, c2 - 1);
      YN(cnt == 0);
    }
  }
}