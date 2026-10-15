// Solution by Abhi Jain for the problem https://codeforces.com/problemset/problem/2266/F
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

void solve() {
  int n;
  cin>>n;
  v(pii) a(n);
  for(auto &[x,y]:a) cin>>x>>y;
  sort(all(a));
  auto bs = [&](int x)->bool{
    if(a.back().F>=x) return true;
    int cnt = 1;
    int ind = a.size()-1;
    int xtra = 0;
    for(int j=x-1;j>=1;j--){
      if(a[ind].F==j){
        cnt = cnt + max(cnt - a[ind].S,0ll);
        xtra += max(a[ind].S - cnt, 0ll);
        ind--;
      }else{
        cnt = cnt + cnt;
      }
      if(cnt >= 1e15) return false;
    }
    if(a[0].F==0) xtra+=a[0].S;
    return xtra >=cnt;
  };
  int l = a.back().F, r = 1e9;
  while(l<r){
    int mid = (l+r+1)/2;
    if(bs(mid)){
      l=mid;
    }else{
      r=mid-1;
    }
  }
  cout<<l<<endl;
}