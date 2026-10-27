// Solution by Abhi Jain for the problem https://codeforces.com/contest/2277/problem/D1
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

constexpr int MOD = 998244253;
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

// add 2^k - 1 (k>=1) or -1 
int MX = 1024;
vi fn(MX,INF);
void precompute() {
  fn[0] = 0;
  for(int i=0;i<MX;i++){
    for(int j=0;(1<<j)<=MX;j++){
      int pw = (1<<j)-2;
      if(i+pw < MX)
        fn[i+pw] = min(fn[i]+j+1,fn[i+pw]);
    }
  }
  for(int i=MX-1;i>=0;i--){
    for(int j=1;(1<<j)<=MX;j++){
      int pw = (1<<j)-1;
      if(i+pw < MX)
        fn[i+pw] = min(fn[i]+j,fn[i+pw]);
    }
  }
  debug(fn);
}

void solve() {
  int l, r;
  cin>>l>>r;
  auto sv = [&](auto&& sv, int x)->int{
    if(x<MX) return fn[x];
    else{
      int i = 63 - __builtin_clzll(x);
      debug(x,i);
      return i+1 + sv(sv, x - (1ll<<i) + 2);
    }
  };
  int ans = 0;
  for(int i=l;i<=r;i++){
    ans = (ans + sv(sv,i))%MOD;
  }
  debug(ans);
  cout<<ans<<endl;
}