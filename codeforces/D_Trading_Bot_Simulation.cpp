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

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = mod(n * n);
    ans = mod(ans * (3 * n + 1));
    cout << ans << endl;
  }
}