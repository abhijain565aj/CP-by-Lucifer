// Solution by Abhi Jain for the problem https://codeforces.com/problemset/problem/2254/G
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
  cin>>n;
  vi a(n);
  read(a,n);

  vvi adj(n);
  for(int i=1;i<n;i++){
    int p; cin>>p; p--;
    adj[p].pb(i);
  }

  multiset<int> ms;
  vi val = a;
  auto dfs = [&](auto&& dfs, int i)->multiset<int>{
    if(adj[i].empty()) return {a[i]};
    multiset<int> s;
    auto merge = [&](multiset<int> r){
      if(s.size()<r.size()) swap(s,r);
      s.insert(r.begin(),r.end());
    };
    for(auto c:adj[i]){
      merge(dfs(dfs,c));
    }
    if(*s.begin()<a[i]) {
      ms.insert(*s.begin());
      s.erase(s.begin());
      s.insert(a[i]);
    }else{
      ms.insert(a[i]);
    }
    return s;
  };
  auto ret = dfs(dfs,0);
  int sum = accumulate(all(ret),0ll);
  int nl = 0;
  for(int i=0;i<n;i++) if(adj[i].size()==0) nl++;
  vi ans(n,-1);
  for(int i=nl-1;i<n;i++){
    ans[i] = sum;
    if(ms.empty()) continue;
    sum += *ms.rbegin();
    ms.erase(ms.find(*ms.rbegin()));
  }
  print(ans,n);
}
