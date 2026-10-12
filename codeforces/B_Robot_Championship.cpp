// Solution by Abhi Jain for the problem https://codeforces.com/contest/2273/problem/B
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
bool check(int n, vector<int> ans) {
    int m = 2 * n;
    v(bool) cur(m + 1, true);
    for (int v : ans) {
        cur[v] = false;
        v(bool) nxt(m + 1, false);
        for (int d = 2; d <= m; d++) {
            if (!cur[d]) continue;
            if (d < m) nxt[d + 1] = true;
            if (d >= 4) nxt[d - 2] = true;
        }
        cur = nxt;
    }
    for (int d = 2; d <= m; d++)
        if (cur[d]) return false;
    return true;
}

void solve() {
  int n;
  cin>>n;
  vi ans;
  auto even = [&]()->void{
    for(int i=2*n-2;i>=4;i-=2){
      ans.pb(i);
    }
  };
  auto odd = [&]()->void{
    for(int i=2*n-1;i>=3;i-=2){
      ans.pb(i);
    }
  };
  bool possible = false;
  for(int i=0;i<8;i++){
    ans.clear();
    for(int j=0;j<3;j++){
      if(i&(1<<j)) even();
      else odd();
    }
    if(check(n, ans)){
      possible = true;
      break;
    }
  }
  debug(possible);

  cout<<ans.size()<<endl;
  print(ans,(int)ans.size());
}