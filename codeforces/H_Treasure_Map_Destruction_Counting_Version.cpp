// Solution by Abhi Jain for the problem https://codeforces.com/problemset/problem/2259/H
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

template <typename T>
struct LazySegmentTree {
  vector<T> tree;
  vector<T> lazy;
  int n;
  T default_value;
  function<T(T, T)> merge;
  LazySegmentTree(
      int n,
      T default_value = 0,
      function<T(T, T)> merge = [](T l, T r) { return l + r; }) {
    this->n = n;
    this->default_value = default_value;
    this->merge = merge;
    tree.resize(4 * n);
    lazy.resize(4 * n);
  }
  void build(vector<T>&& a) {
    buildp(a, 1, 0, n - 1);
  }
  T query(int l, int r) {
    return queryp(1, 0, n - 1, l, r);
  }
  void update(int l, int r, T val) {
    debug(l,r);
    if(l>r) return;
    updatep(1, 0, n - 1, l, r, val);
  }
  void update(int pos, T val) {
    updatep(1, 0, n - 1, pos, pos, val);
  }
  void buildp(vector<T>& a, int v, int tl, int tr) {
    if (tl == tr)
      tree[v] = a[tl];
    else {
      int tm = (tl + tr) / 2;
      buildp(a, v * 2, tl, tm);
      buildp(a, v * 2 + 1, tm + 1, tr);
      tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
  }
  void push(int v, int tl, int tr) {
    if (lazy[v]==0 || tl == tr) return;
    int tm = (tl + tr) / 2;
    tree[v * 2] = lazy[v] * (tm - tl + 1);
    lazy[v * 2] = lazy[v];
    tree[v * 2 + 1] = lazy[v] * (tr - tm);
    lazy[v * 2 + 1] = lazy[v];
    lazy[v] = 0;
  }
  T queryp(int v, int tl, int tr, int l, int r) {
    if (l > r) return default_value;
    if (l == tl && r == tr) return tree[v];
    int tm = (tl + tr) / 2;
    push(v, tl, tr);
    return merge(
        queryp(v * 2, tl, tm, l, min(r, tm)),
        queryp(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
  void updatep(int v, int tl, int tr, int l, int r, T val) {
    if (l > r) return;
    if (l == tl && r == tr) {
      tree[v] = val * (tr - tl + 1);
      lazy[v] = val;
    } else {
      int tm = (tl + tr) / 2;
      push(v, tl, tr);
      updatep(v * 2, tl, tm, l, min(r, tm), val);
      updatep(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
      tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
  }
};

void solve() {
  int n;
  cin>>n;
  vi a(n);
  read(a,n);
  LazySegmentTree<int> lst(n);
  lst.build(vector<int>(n,1));
  vi val(n);

  for(int i=0;i<n;i++)if(a[i]!=-1){
    lst.update(max(i-a[i]+1,0ll),min(i+a[i]-1,n-1),-1);
  }
  for(int i=0; i<n; i++){
    val[i] = lst.query(i,i) == 1;
  }
  debug(val);
  vvi adj(n); // only consider non-0 a[i];
  vvi dp(n,vi(2,-1)); // dp[i][j] treaseure -> bool j
  for(int i=0;i<n;i++)if(a[i]!=-1){
    auto get = [&](int i)->int{
      if(i<0) return 0;
      else if(i>=n) return 0;
      else return val[i];
    };
    int ls = i-a[i];
    int rs = i+a[i];
    int lv = get(ls), rv = get(rs);
    if(lv && rv){
      if(ls == rs){
        dp[ls][0] = 0;
      }else{
        adj[ls].pb(rs);
        adj[rs].pb(ls);
      }
    }else if(lv && !rv){
      dp[ls][0] = 0;
    }else if(!lv && rv){
      dp[rs][0] = 0;
    }else{
      cout<<0<<endl;
      return;      
    }
  }
  vvi vis(n,vi(2,-1));
  auto dfs = [&](auto&& dfs,int i, int tr)->int{
    if(dp[i][tr]!=-1) return dp[i][tr];
    int ret = 1;
    for(auto c:adj[i]){
      if(c==vis[i][tr]) continue;
      if(tr){
        vis[c][1] = vis[c][0] = i;
        ret = (ret * (dfs(dfs,c,1)+dfs(dfs,c,0))) % MOD;
      }else{
        vis[c][1] = i;
        ret = (ret * dfs(dfs,c,1)) % MOD;
      }
    }
    return dp[i][tr] = ret;
  };
  int ans = 1;
  for(int i=0;i<n;i++)if(val[i]!=0){
    if(vis[i][0]==-1){
      ans = (ans * (dfs(dfs,i,1)+dfs(dfs,i,0))) % MOD;
    }
  }
  // if all -1 then subtract -1
  int cnt = 0;
  for(auto &x : a) cnt += x==-1;
  if(cnt == n) ans = (ans - 1)%MOD;
  cout<<ans<<endl;

  
}
