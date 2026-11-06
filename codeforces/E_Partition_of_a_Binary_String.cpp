// Solution by Abhi Jain for the problem https://codeforces.com/contest/2283/problem/E
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

constexpr int MOD = 998244353;
constexpr int N = 5010;
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

vvi dp(N, vi(N, 0)); // dp[i][j] = nw parttition i elements into j groups
vi dp2(N,0); // nuumber of ways to express i as sum of 2 and 3
void precompute() {
  dp[0][0] = 1;
  for(int i=1;i<N;i++){
    for(int j=1;j<=i;j++){
      dp[i][j] = add(dp[i-1][j-1], mul(j, dp[i-1][j]));
    }
  }

  dp2[0] = dp2[1] = 0;
  dp2[2] = 1;
  dp2[3] = 1;
  for(int i=4;i<N;i++){
    dp2[i] = add(dp2[i-2],dp2[i-3]);
  }
}

void solve() {
  int n;
  cin>>n;
  string s;
  cin>>s;
  int ans = 1;
  int cost = 0;
  vvi arr;
  arr.pb({s[0]-'0'});
  for(int i=1;i<n;i++){
    if(s[i]!=s[i-1]){
      arr.back().pb(s[i]-'0');
    }else{
      arr.pb({s[i]-'0'});
    }
  }
  int zc = 0 , oc = 0;
  for(auto &v:arr){
    set<int> st(all(v));
    if(sz(st)==1){
      if(v[0]==0) zc++;
      else oc++;
    }else{
      cost += 2*sz(v);
      // if(v[0]==v.back()){
      //   ans = mul(ans,sz(v)-2);
      // }
      ans = mul(ans,dp2[sz(v)]);
    }
  }
  debug(ans);
  for(auto x:{zc,oc}){
    if(x==0) continue;
    cost += x;
    int curr = 0;
    for(int i=1;i<=x;i++){
      curr = add(curr, dp[x][i]);
    }
    ans = mul(ans,curr);
  }
  cout<<cost<<" "<<ans<<endl;
}