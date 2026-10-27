// Solution by Abhi Jain for the problem https://codeforces.com/problemset/problem/2238/E
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
  string s;
  cin>>s;
  vi a;
  for(auto c:s) if(c=='T'){
    a.pb(1);
  }else if(c=='F'){
    a.pb(0);
  }else{
    a.pb(-1);
  }
  int ans = 0;
  for(int l=0;l<n;l++){
    for(int r=l;r<n;r++){
      auto b = a;
      for(int i=0;i<l;i++) if(b[i]==-1) b[i] = 0;
      for(int i=l;i<=r;i++) if(b[i]==-1) b[i] = 1;
      for(int i=r+1;i<n;i++) if(b[i]==-1) b[i] = 0;

      auto cnt = [&](vi &b)->int{
        debug(b);
        vi tc(n+1),fc(n+1);
        // tc -> pref fc -> suff
        for(int i=0;i<n;i++){
          tc[i+1] = b[i] + tc[i];
        }
        for(int i=n-1;i>=0;i--){
          fc[i] = 1 - b[i] + fc[i+1];
        }
        vi mx(n+1); // mx of tc[j]+fc[j+1] for j>=i-1
        mx[n] = tc[n] + fc[n];
        for(int i=n-1;i>=0;i--){
          mx[i] = min(mx[i+1],tc[i] + fc[i]);
        }
        debug(mx);
        int ans = 1e9;
        for(int i=0;i<=n;i++){
          ans = min(ans,mx[i]+i-2*tc[i]);
        }
        debug(ans);
        return ans;
      };
      ans = max(ans,cnt(b));
      debug(l,r,cnt(b));
    }
  }
  cout<<ans<<endl;
}