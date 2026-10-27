// Solution by Abhi Jain for the problem https://codeforces.com/contest/2272/problem/D
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
  int k;
  cin>>k;
  v(pii) mx, mn;
  vi ones;
  for(int i=0;i<k;i++){
    int n;
    cin>>n;
    if(n==1){
      ones.pb(i+1);
      continue;
    }
    vvi adj(n);
    for(int j=0;j<n-1;j++){
      int u,v;
      cin>>u>>v;
      u--;v--;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    vi inc(n), ninc(n);
    auto dfs = [&](int u, int p, auto&& dfs)->void{
      inc[u] = 1;
      for(int v:adj[u]){
        if(v==p) continue;
        dfs(v,u,dfs);
        inc[u] += ninc[v];
        ninc[u] += max(inc[v],ninc[v]);
      }
    };
    dfs(0,-1,dfs);
    if(inc[0]>=ninc[0]){
      mx.pb({i+1,1});
      mn.pb({i+1,adj[0][0]+1});
    }else{
      mn.pb({i+1,1});
      for(int j=0;j<(int)adj[0].size();j++){
        if(ninc[adj[0][j]]<=inc[adj[0][j]]){
          mx.pb({i+1,adj[0][j]+1});
          break;
        }
      }
    }
  }
  debug(mx,mn,ones);
  for(int i=0;i<(int)mx.size()-1;i++){
    cout<<mx[i].F<<" "<<mx[i].S<<" "<<mn[i+1].F<<" "<<mn[i+1].S<<endl;
  }
  if(mx.size()!=0){
    for(int i=0;i<(int)ones.size();i++){
      cout<<ones[i]<<" 1 "<<mn[0].F<<" "<<mn[0].S<<endl;
    }
  }else{
    for(int i=1;i<(int)ones.size();i++){
      cout<<ones[0]<<" 1 "<<ones[i]<<" 1"<<endl;
    }
  }
}