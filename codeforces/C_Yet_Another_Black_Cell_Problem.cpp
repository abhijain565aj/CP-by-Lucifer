// Solution by Abhi Jain for the problem https://codeforces.com/contest/2272/problem/C
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
  int n, x;
  cin >> n >> x;
  vi a(n);
  read(a, n);
  auto fn = [&](int val)->bool{
    auto b = a;
    int cnt = 0;
    for(int i=0; i<n; i++){
      int v1 = (i==0?INF:b[i]-b[i-1]);
      int v2 = (i==n-1?INF:b[i+1]-b[i]);
      if(min(v1,v2)<=val){
        continue;
      }else{
        cnt++;
        b[i] = b[i]+val;
      }
    }
    return cnt <= x;
  };
  int l = 1, r = 1e9;
  while(l<r){
    int m = (l+r)/2;
    if(fn(m)) r = m;
    else l = m+1;
  }
  cout<<l<<endl;
}