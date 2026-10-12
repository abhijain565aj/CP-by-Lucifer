// Solution by Abhi Jain for the problem https://codeforces.com/contest/2273/problem/A
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
  auto check = [&](int x)->pair<bool,vector<int>>{
    vi ans;
    for(int i=n, bs=0;i>=1 && (int)ans.size()<=n;i--){
      for(int j=0;j<x/i && (int)ans.size()+i<=n;j++,bs++){
        for (int k = 0; k < i; k++){
          ans.pb(bs+1);
        }
      }
    }
    if((int)ans.size()==n) return {true,ans};
    else return {false,vector<int>()};
  };
  int l = 1, r = n;
  while(l<r){
    int mid = l + (r-l)/2;
    if(check(mid).F) r = mid;
    else l = mid + 1;
  }
  cout<<l<<endl;
  auto ans = check(l).S;
  print(ans,n);
}