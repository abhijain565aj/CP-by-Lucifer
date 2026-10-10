// Solution by Abhi Jain for the problem https://codeforces.com/contest/2271/problem/C
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

int cnt(vi a){
  int ans = a.size();
  int n = a.size();
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      int x = 0;
      for(int k=i;k<=j;k++){
        x^=a[k];
      }
      if(x==0){
        ans--;
      }
    }
  }
  return ans;
}
vi xor_basis(int n){
  // xor basis of 1 to n
  vi basis;
  for(int i=1;i<=n;i++){
    int x = i;
    for(auto b:basis){
      x = min(x,x^b);
    }
    if(x!=0){
      basis.pb(x);
    }
  }
  return basis;
}

// void solve() {
//   int n;
//   cin>>n;
//   vi a = xor_basis(n);
//   for(int i=a.size()-1;i>=1;i--){
//     a.pb(a[i-1]);
//   }
//   vi ans;
//   ans.pb(0);
//   for(auto x:a){
//     ans.pb(x);
//     ans.pb(0);
//   }
//   cout<<ans.size()<<endl;
//   print(ans,(int)ans.size());
//   debug(cnt(ans));
// }

void solve() {
    int n;
    cin >> n;
    int m = (1 << ((int)log2(n) + 1)) - 1;
    vi ans;
    int pv = 0;
    for (int i = 1; i <= m; i++) {
        int new_pv = i ^ (i >> 1);
        ans.pb(new_pv ^ pv);
        pv = new_pv;
    }
    ans.pb(pv);
    int sz = ans.size();
    for (int i = 0; i < sz - 1; i++) {
        ans.pb(ans[i]);
    }
    cout << ans.size() << '\n';
    print(ans, (int)ans.size());
}