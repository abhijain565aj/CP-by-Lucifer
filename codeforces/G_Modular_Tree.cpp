// Solution by Abhi Jain for the problem https://codeforces.com/problemset/problem/2266/G
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#include "./Templates/DEBUG.cpp"
#define local true
#else
#define debug(...)
#define Test(tt)
#define Error_file(x)
#define local false
#endif

#define int long long

#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vvi vector<vi>
#define pii pair<int, int>
#define v(x) vector<x>

#define fo(i, n) for (int i = 0; i < n; i++)
#define re(i, n) for (int i = n - 1; i >= 0; i--)

#define YN(possible) cout << ((possible) ? "YES" : "NO") << endl;
#define all(x) (x).begin(), (x).end()
#define sortall(x) sort(all(x))
#define F first
#define S second
#define pb push_back

#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

#define read(a, n) \
  for (int i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) \
  for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');

void file(string s = "") {
  if (local) {
    // freopen("error.txt", "w", stderr);
    // freopen("output.txt", "w", stdout);
    // freopen(("input" + s + ".txt").c_str(), "r", stdin);
    return;
  }
}

constexpr int MOD = 1000000007;
constexpr int N = 1e5 + 1;
constexpr int INF = 1e18;

void solve();
void precompute();

signed main() {
  fastio;
  file();
  precompute();

  int testCases = 1;
  cin >> testCases;

  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}

void precompute() {
}

void solve() {
  int n;
  cin >> n;
  vi a(n), b(n);
  read(a, n);
  read(b, n);
  vvi adj(n);
  fo(i,n-1){
    int u,v;
    cin >> u >> v;
    u--,v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  v(pii) dp(n,{-1,-1}); // sum, best_gcd
  auto dfs = [&](auto&&dfs, int u, int p)->pii{
    if(dp[u].F!=-1) return dp[u];
    if(adj[u].size()==1 && adj[u][0]==p){
      return dp[u]={a[u],b[u]}; //leaf
    }
    int gd = b[u];
    int s = 0;
    for(auto c:adj[u]){
      if(c==p) continue;
      auto [v,g] = dfs(dfs,c,u);    
      if(g!=b[c]) gd = gcd(gd,g);
      s += a[c];
    }    
    gd = gcd(s,gd);
    dp[u].F = b[u] - gd + a[u]%gd;
    dp[u].S = gd;
    return dp[u];
  };
  dfs(dfs,0,-1);

  int ans = 0;
  fo(i,n) ans += dp[i].F;
  cout<<ans<<endl;
}
