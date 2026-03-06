#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define MOD = 1000000007
int MOD = 1000000007;

// Modular Arithmetic
int mod(int a, int m = MOD) { return (a % m + m) % m; }
int add(int a, int b, int m = MOD) { return mod(a + b, m); }
int sub(int a, int b, int m = MOD) { return mod(a - b, m); }
int mul(int a, int b, int m = MOD) { return mod(a * b, m); }
int power(int a, int b, int m = MOD) {
  int res = 1;
  while (b) {
    if (b & 1)
      res = mul(res, a, m);
    a = mul(a, a, m);
    b >>= 1;
  }
  return res;
}
int inv(int a, int m = MOD) { return power(a, m - 2, m); }
int divide(int a, int b, int m = MOD) { return mul(a, inv(b, m), m); }
