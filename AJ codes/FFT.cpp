#include <bits/stdc++.h>
using namespace std;

struct FFT {
  typedef complex<double> cd;
  const double PI = acos(-1);
  void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    static vector<int> rev;
    static vector<cd> roots{0, 1};
    if ((int)rev.size() != n) {
      int k = __builtin_ctz(n);
      rev.assign(n, 0);
      for (int i = 0; i < n; i++)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
    }
    if ((int)roots.size() < n) {
      int k = __builtin_ctz(roots.size());
      roots.resize(n);
      while ((1 << k) < n) {
        double angle = 2 * PI / (1 << (k + 1));
        for (int i = 1 << (k - 1); i < (1 << k); i++) {
          roots[2 * i] = roots[i];
          double ang = angle * (2 * i + 1 - (1 << k));
          roots[2 * i + 1] = cd(cos(ang), sin(ang));
        }
        k++;
      }
    }
    for (int i = 0; i < n; i++)
      if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int len = 1; len < n; len <<= 1) {
      for (int i = 0; i < n; i += 2 * len) {
        for (int j = 0; j < len; j++) {
          cd u = a[i + j];
          cd v = a[i + j + len] * roots[len + j];
          a[i + j] = u + v;
          a[i + j + len] = u - v;
        }
      }
    }
    if (invert) {
      reverse(a.begin() + 1, a.end());
      for (cd& x : a) x /= n;
    }
  }
  vector<int> convolution(vector<int> A, vector<int> B) {
    int n = 1;
    while (n < (int)A.size() + (int)B.size()) n <<= 1;
    vector<cd> fa(A.begin(), A.end()), fb(B.begin(), B.end());
    fa.resize(n), fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);
    vector<int> res(n);
    for (int i = 0; i < n; i++) res[i] = llround(fa[i].real());
    return res;
  }
};
