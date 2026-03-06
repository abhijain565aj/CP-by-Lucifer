#include <bits/stdc++.h>
using namespace std;

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