// Solution by Abhi Jain for the problem https://codeforces.com/problemset/problem/2260/E
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
  // cin >> _testCases;

  for(int _t=0; _t<_testCases; _t++) {
    Test(_t + 1);
    solve();
  }
}

void precompute() {
}

array<int,4> operator+(const array<int,4>& l, const array<int,4>& r){
  array<int,4> res;
  for(int i=0;i<4;i++){
    res[i] = l.at(i) + r.at(i);
  }
  return res;
}
array<int,4> operator-(const array<int,4>& l, const array<int,4>& r){
  array<int,4> res;
  for(int i=0;i<4;i++){
    res[i] = l.at(i) - r.at(i);
  }
  return res;
}

void solve() {
  // 101010 (1) -> cyclic hence always same number of 10 and 01
  // no of 10 = x then 01 = x
  // total = n
  // 00 and 11 = (n - 2x)/2
  // if x>=n/4 op = 4x - n
  // can binary search on final size of the n
  // depending on count of 11 00 and etc
  int n,q;
  cin>>n>>q;
  string s;
  cin>>s;
  vector<array<int,4>> a(n,{0,0,0,0});
  auto fn = [&](char i, char j)->array<int,4>{
    string s;
    s.pb(i), s.pb(j);
    array<int,4> res = {0};
    if(s=="00") res[0]++;
    else if(s=="01") res[1]++;
    else if(s=="10") res[2]++;
    else if(s=="11") res[3]++;
    return res;
  };
  for(int i=1;i<n;i++){
    a[i] = a[i-1] + fn(s[i-1],s[i]);
  }
  // debug(a);
  auto check = [&](array<int,4> ct, int l)->bool{
    // l is length by 4
    static int a00 = 0, a01 = 1, a10 = 2, a11 = 3;
    if(ct[a10]!=ct[a01]) return false;
    if(l<ct[a01]) return false;
    int xtra = 4*l - accumulate(all(ct),0);
    xtra -= max(l-ct[a00],0ll);
    xtra -= max(l-ct[a11],0ll);
    ct[a00] = max(ct[a00],l);
    ct[a11] = max(ct[a11],l);
    xtra -= (ct[a00]+ct[a11] - 2*l);
    return xtra>=0;
  };
  while(q--){
    int l,r;
    cin>>l>>r;
    l--,r--;
    auto ct = a[r] - a[l];
    ct = ct + fn(s[r],s[l]);
    debug(ct);
    int lo = 0, hi = n;
    while(lo<hi){
      int mid = (lo+hi)/2;
      if(check(ct,mid)){
        hi = mid;
      }else{
        lo = mid+1;
      }
    }
    cout<<4*lo - (r-l+1)<<endl;
  }
  debug(check({2,0,0,0},1));
}