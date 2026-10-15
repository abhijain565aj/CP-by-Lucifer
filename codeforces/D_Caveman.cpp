// Solution by Abhi Jain for the problem https://codeforces.com/contest/2276/problem/D
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
  int n,m;
  cin>>n>>m;
  vvi adj(n);
  for(int i=0;i<m;i++){
    int u,v; cin>>u>>v; u--, v--;
    adj[u].pb(v), adj[v].pb(u);
  }
  vi vis(n,-1);
  vi col(n);
  int curr_comp = 0, curr_col = 0;
  bool many = false;
  map<int,int> mp, nl;
  auto dfs = [&](auto&&dfs, int u)->void{
    if(vis[u]!=-1) return;
    vis[u] = curr_comp;
    mp[curr_comp]++;
    if(adj[u].size()>1) nl[curr_comp]++;
    col[u] = curr_col;
    curr_col^=1;
    for(auto v:adj[u]) {
      dfs(dfs,v);
      if(col[u] == col[v]) many = true;
    }
    curr_col^=1;
  };
  for(int i=0;i<n;i++) if(vis[i]==-1){
    dfs(dfs,i);
    if(mp[curr_comp] == 1){
      cout<<"Brain Melt"<<endl;
      return;
    };
    if(nl[curr_comp] > 1) many = true;
    curr_comp++;
  }
  debug(mp);
if(many || curr_comp > 1){
    cout<<"Many"<<endl;
  }else{
    cout<<2<<endl;
  }
}