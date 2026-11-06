// Solution by Abhi Jain for the problem https://codeforces.com/contest/2283/problem/D
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
  int n;
  cin>>n;
  vvi adj(n+1);
  for(int i=0; i<n-1; i++){
    int u, v;
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  if(n%2 == 0){
    cout << n+1 << endl;
    return;
  }

  // possible answers is n or n+1 or n+2
  v(pii) pos = {{n, n}, {n+1, (n+1)/2}, {n+2, 1}}; // first = ans, sec = gray node
  // need to check gray or not
  for(auto &[ans, gray]: pos){
    DSU dsu(n+1);
    for(int i=1; i<=n; i++){
      if(i == gray) continue;
      for(auto &j: adj[i]){
        if(j == gray) continue;
        dsu.unite(i, j);
      }
    }
    for(int i=1;i<=n;i++){
      if(i==gray || ans-i==gray) continue;
      if(!dsu.same(i,ans-i)){
        cout << ans << endl;
        return;
      }
    }
  }
  cout<<n<<endl;
}