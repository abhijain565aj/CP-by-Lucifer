// Solution by Abhi Jain for the problem https://codeforces.com/contest/2277/problem/C
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

struct DSU {
  vector<int> parent, size;
  int components;
  DSU(int n) {
    parent.resize(n);
    size.resize(n, 1);
    components = n;
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }
  int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
  }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      if (size[x] < size[y])
        swap(x, y);
      parent[y] = x;
      size[x] += size[y];
      components--;
    }
  }
  inline bool same(int x, int y) {
    return find(x) == find(y);
  }
  inline int getSize(int x) {
    return size[find(x)];
  }
  inline int getComponents() {
    return components;
  }
};

void solve() {
  int n, m;
  cin>> n >> m;
  vvi adj(n);
  DSU dsu(n);
  for(int i=0; i<n-1;i++){
    int u, v;
    cin>> u >> v;
    u--, v--;
    adj[u].pb(v);
    adj[v].pb(u);
    if(u!=0 && v!=0) dsu.unite(u,v);
  }
  // vi dis_1(n, 0);
  // auto dfs = [&](auto self, int u, int p) -> void {
  //   for(int v: adj[u]) {
  //     if(v==p) continue;
  //     dis_1[v] = dis_1[u]+1;
  //     self(self, v, u);
  //   }
  // };
  // dfs(dfs, 0, -1);
  vi dis_n(n,0);
  auto dfsn = [&](auto self, int u, int p) -> void {
    for(int v: adj[u]) {
      if(v==p) continue;
      dis_n[v] = dis_n[u]+1;
      self(self, v, u);
    }
  };
  dfsn(dfsn,n-1,-1);
  // debug(dis_1,dis_n);
  debug(dsu.parent);
  int ans = dis_n[0];
  for(int i=0; i<m;i++){
    int x;
    cin>>x;
    x--;
    if(dsu.same(x,n-1)){
      ans = max(ans,1+dis_n[x]);
    }
  }
  cout<<ans<<endl;
}