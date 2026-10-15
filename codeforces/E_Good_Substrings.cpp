// Solution by Abhi Jain for the problem https://codeforces.com/contest/2276/problem/E
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
pair<int,int> operator+(pii l, pii r){
  return {l.F+r.F,l.S+r.S};
}
void operator+=(pii& l, pii r){
  l = l+r;
}
pair<int,int> operator*(pii l, int r){
  return {l.F*r,l.S*r};
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
  void build(vector<T>& a) {
    buildp(a, 1, 0, n - 1);
  }
  T query(int l, int r) {
    return queryp(1, 0, n - 1, l, r);
  }
  void update(int l, int r, T val) {
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
    if (lazy[v] == default_value || tl == tr) return;
    int tm = (tl + tr) / 2;
    tree[v * 2] += lazy[v] * (tm - tl + 1);
    lazy[v * 2] += lazy[v];
    tree[v * 2 + 1] += lazy[v] * (tr - tm);
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = default_value;
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
      tree[v] += val * (tr - tl + 1);
      lazy[v] += val;
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
  string s;
  cin>>s;
  vi a(n);
  for(int i=0;i<n;i++) a[i] = s[i] - '0';
  vector<int> ind5, ind6;
  for(int i=0;i<n;i++){
    if(a[i]==5) ind5.pb(i);
    else if(a[i]==6) ind6.pb(i);
  }
  ind5.pb(n);
  ind6.pb(n);
  vector<array<int,3>> dp(n+1,{n,n,n}); // occ of 2 02 202 min ind
  for(int i=n-1;i>=0;i--){
    dp[i] = dp[i+1];
    if(a[i]==2){
      dp[i][0] = i;
      dp[i][2] = dp[i+1][1];
    }else if(a[i]==0){
      dp[i][1] = dp[i+1][0];
    }
  }
  LazySegmentTree<pair<int,int>> lst(n,{0,0}); //line
  LazySegmentTree<int> lst1(n); //same
  for(int i=0;i<n;i++){
    auto f = dp[i][2];
    int i6 = *lower_bound(all(ind6),f);
    int i5 = *lower_bound(all(ind5),f); // first occ of 5
    if(i5>i6) continue;
    debug(f,i5,i6);
    // bad array starting with i
    // for every j (i to i5-1) add i6-i5
    lst1.update(i,i5-1,i6-i5);
    // for every j (i5 to i6-j)
    lst.update(i5,i6-1,{i6,1});
  }
  for(int i=0;i<n;i++){
    int total = (i+1)*(n-i);
    auto q = lst.query(i,i);
    cout << total - lst1.query(i,i) - (q.F - q.S*i)<<" ";
  }
  cout<<endl;

}