#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
int MOD = 998244353;

long long modpow(long long a, long long b) {
  long long res = 1;
  a %= MOD;
  while (b > 0) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
long long modinv(long long q) { return modpow(q, MOD - 2); }

int mod(int x) {
  return (x % MOD + MOD) % MOD;
}

double sum(double x) {
  return (x * (x + 1)) / 2;
}

signed main() {
  int n;
  cin >> n;
  vector<double> a(n);
  for (auto& x : a) cin >> x;

  vector<double> rev(n);
  rev[n - 1] = sum(a[n - 1])/a[n-1];

  for (int i = n - 2; i >= 0; i--) {
    double dv = floor(rev[i + 1]);
    if (dv >= a[i]) {
      rev[i] = rev[i + 1];
      continue;
    }
    rev[i] = (dv / a[i]) * rev[i + 1];
    rev[i] += (1 / a[i]) * (sum(a[i]) - sum(dv));
  }
  cout.precision(10);
  cout << rev[0] << endl;
}