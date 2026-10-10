// Solution by Abhi Jain for the problem https://codeforces.com/problemset/problem/2239/C
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
  v(pii) s;
  s.pb({-1,0});
  vi perm(n);
  for(int i=0;i<n;i++){
    char c;
    int x;
    cin>>c>>x;
    if(c=='p'){
      perm[i] = x;
    }else{
      s.pb({i,x});
    }
  }
  debug(perm);
  debug(s);

  ordered_set<int> os;
  for(int i=1;i<=n;i++) os.insert(i);
  
  auto no_inversions = [&](vector<int>& perm)->int{
    int ans = 0;
    for(int i = (int)perm.size()-1; i>=0; i--){
      auto& x = perm[i];
      os.erase(x);
      ans += os.size() - os.order_of_key(x);
    }
    return ans;
  };

  int pt = s.size();
  vi curr;
  for(int i=n-1;i>=-1;i--){
    if(i>=0 && perm[i]!=0){
      curr.push_back(perm[i]);
    }else{
      pt--;
      reverse(all(curr));
      // process here
      int ni = no_inversions(curr);
      ordered_set<int> os_p;
      for(auto x:curr) os_p.insert(x);
      if(pt < (int)s.size()-1){
        int delta = s[pt+1].S - s[pt].S - ni;
        // make this delta reach 0 by moving some x in os to s[pt+1].F
        // w.r.t. perm and the remanining in os
        // binary search in os
        debug(delta);
        debug(curr);
        int l = 0;
        int r = os.size()-1;
        while(l<=r){
          int mid = (l+r)/2;
          int x = *os.find_by_order(mid);
          int ndelta = delta;
          ndelta -= os.size() - 1 - os.order_of_key(x);
          ndelta += os_p.order_of_key(x);
          ndelta -= os_p.size() - os_p.order_of_key(x);
          debug(x, ndelta);
          if(ndelta == 0){
            perm[s[pt+1].F] = x;
            os.erase(x);
            break;
          }else if (ndelta < 0){
            l = mid + 1;
          }else if (ndelta > 0){
            r = mid - 1;
          }
        }
      }
      curr.clear();
    }
  }
  print(perm,n);
}
