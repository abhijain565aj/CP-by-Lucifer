// Solution by Abhi Jain for the problem https://codeforces.com/contest/2283/problem/C
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

void precompute() {
}

int MAX_BIT = 20;

void solve() {
  int n;
  cin>>n;

  vector<int> bit(MAX_BIT,0);

  auto max_bit = [&](int x)->int{
    int mx = 0;
    for(int j=0;j<MAX_BIT;j++){
      if(x & (1<<j)){
        mx = j;
      }
    }
    return mx;
  };

  auto rem = [&](int x){
    for(int j=0;j<MAX_BIT;j++){
      if(x & (1<<j)){
        bit[j]--;
      }
    }
  };
  auto add = [&](int x){
    for(int j=0;j<MAX_BIT;j++){
      if(x & (1<<j)){
        bit[j]++;
      }
    }
  };

  for(int i=1;i<=n;i++){
    add(i);
  }

  vector<bool> a(n+1, false);
  a[n] = true;
  rem(n);
  add(2*n);
  
  int mb = max_bit(2*n)-1;
  debug(mb);
  for(int i=n-1;i>=0;i--){
    while(bit[mb]%2==1 && mb>=0){
      mb--;
    }
    if(max_bit(i) + 1 == mb){
      a[i] = true;
      rem(i);
      add(2*i);
      mb --;
    }
  }
  debug(bit);
  for(int i=1;i<=n;i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
}