// Solution by Abhi Jain for the problem https://codeforces.com/contest/2271/problem/E
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
  int n, k;
  cin>>n>>k;
  vi a(n);
  read(a,n);
  multiset<int> s;
  fo(i,n){
    s.insert(a[i]);
  }

  int ans = 0;
  for(;!s.empty();ans++, k++){
    if(*s.begin()<k){
      s.erase(s.begin());
      continue;
    }
    auto it1 = s.lower_bound(2*k);
    auto it2 = s.upper_bound(2*k+2);
    if(it1 == s.end()){
      int mx = *s.rbegin();
      s.erase(s.find(mx));
      s.insert((mx+1)/2);
      continue;
    }
    
    int x = *it;
    if()
  }
  
}
