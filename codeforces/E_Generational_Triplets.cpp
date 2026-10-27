// Solution by Abhi Jain for the problem https://codeforces.com/problemset/problem/2252/E
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

// b1 = 011 101
// b2 = 000
// b3 = 110 101
int MAX_B = 64;
vi dp(MAX_B); // b1*(b1|b2|b3)* -> exact j bits
vi dp2(MAX_B); // (b1|b2|b3)* -> upto j bits
vi pref(MAX_B);
void precompute() {
  dp2[0] = 1;
  dp2[1] = 1;
  dp[0] = dp[1] = 0;
  for(int i=2;i<MAX_B;i++){
    dp2[i] = dp2[i-1] + 2*dp2[i-2];
    dp[i] = dp2[i-2];
    dp2[i] %= MOD;
    pref[i] = mod(dp[i]+pref[i-1]);
  }
}

int cnt(int n){
  int res = 0;
  for(int i=1;i<=n;i++)for(int j=i+2;j<=n;j+=2){
    int k = (i+j)/2;
    if((i^j^k)==0) res++;
  }
  return res;
}

void solve() {
  int n;
  cin>>n;
  int n1 = n;
  vi bits;
  while(n1) bits.pb(n1%2), n1>>=1;
  debug(bits);
  int sz = bits.size();
  int ans = pref[sz-1];
  debug(ans);
  if(bits[sz-1]&&bits[sz-2]){
    vi mydp(sz,-1);
    auto fn = [&](auto&& fn,int c)->int{
      // from cth bit doing normally
      if(c<=0) return 1;
      if(mydp[c]!=-1) return mydp[c];
      int res = 0;
      if(bits[c]==0){
        res += fn(fn,c-1);
        if(bits[c-1]==1){
          res += fn(fn,c-2);
        }
      }else{
        res += dp2[c];  // all for (c-1)+1 bits
        res += dp[c+1]; // b3 + anything
        if(bits[c-1]==1){
          res += fn(fn,c-2);
        }
      }
      return mydp[c] = mod(res);
    };
    ans += fn(fn,sz-3);
    ans = mod(ans);
  }
  // if(cnt(n)!=ans){
  //   cout<<"Error "<<n<<endl;
  //   debug(cnt(n),ans);
  // }
  cout<<ans<<endl;
}