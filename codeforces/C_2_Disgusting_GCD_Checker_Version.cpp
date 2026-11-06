// Solution by Abhi Jain for the problem https://codeforces.com/contest/2284/problem/C2
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
constexpr int N = 2e5 + 1;
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

vi prime(N,true);
vi primes;

void precompute() {
  prime[0] = prime[1] = false;
  for(int i=2;i<N;i++){
    if(prime[i]){
      for(int j=i*i;j<N;j+=i){
        prime[j] = false;
      }
    }
  }
  for(int i=2;i<N;i++){
    if(prime[i]) primes.pb(i);
  }
}

void solve() {
  int a,b;
  cin>>a>>b;
  if(a==b){
    cout<<0<<endl;
    return;
  }
  if(gcd(a,b-a)==1){
    cout<<1<<endl;
    cout<<b-a<<endl;
    return;
  }
  int idx = upper_bound(all(primes), a) - primes.begin();
  for(int i=idx;i<sz(primes) && primes[i] < b;i++){
    if(gcd(a, primes[i]) == 1 && gcd(b, primes[i]) == 1){
      cout<<2<<endl;
      cout<<primes[i]-a<<" "<<b-primes[i]<<endl;
      return;
    }
  }
  for(int i=a+1;i<=b-1;i++){
    if(gcd(a,i) == 1 && gcd(b,i) == 1){
      cout<<2<<endl;
      cout<<i-a<<" "<<b-i<<endl;
      return;
    }
  }
  map<int,pii> dp;
  dp[b] = {0,b};
  auto fn = [&](auto&&fn, int a)->int{
    if(dp.count(a)) return dp[a].F;
    dp[a] = {INF,INF};
    for(int x = b;x>=a+1;x--){
      if(gcd(a,x) == 1){
        int val = 1 + fn(fn,x);
        if(dp[a].F > val){
          dp[a] = {val,x};
        }
        return dp[a].F;
      }
    }
    return dp[a].F;
  };
  // for(int x = b-1;x>=a+1;x--){
  //   for(int y = x+1;y<=b;y++){

  //   }
  //   if(gcd(a,x) == 1){
  //     dp[a] = {1,x};
  //     break;
  //   }
  // }
  fn(fn,a);
  cout<<dp[a].F<<endl;
  int curr = a;
  while(curr != b){
    cout<<dp[curr].S-curr<<" ";
    curr = dp[curr].S;
  }
  cout<<endl;
}