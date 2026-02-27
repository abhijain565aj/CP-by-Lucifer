// Solution by Abhi Jain aka Lucifer aka abhijain565aj
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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "./0_debug.cpp"
#else
#define debug(...)
#define Test(tt)
#define Error_file(x)
#endif

#define int long long
typedef long long ll;
typedef long double ld;

#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vvi vector<vi>
#define pii pair<int, int>
#define v(x) vector<x>

#define fo(i, n) for (decltype(n) i = 0; i < n; i++)
#define re(i, n) for (decltype(n) i = n - 1; i >= 0; i--)
#define fo1(i, a, b) for (decltype(b) i = a; i < b; i++)
#define re1(i, a, b) for (decltype(a) i = a; i >= b; i--)

#define YN(possible) cout << ((possible) ? "YES" : "NO") << endl;
#define all(x) (x).begin(), (x).end()
#define sortall(x) sort(all(x))
// #define F first
// #define S second
#define pb push_back
// a.resize(unique(all(a)) - a.begin());

#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

#define read(a, n) \
  for (int i = 0; i < n; ++i) cin >> a[i];
#define print_space(a, n) \
  for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');

constexpr int MOD = 1000000007;
constexpr int N = 1e5 + 1;
constexpr int INF = 1e18;

#define C1 0
#define P1 1
#define S1 2

void solve() {
  int n;
  cin >> n;
  vi parent(n - 1);
  read(parent, n - 1);
  for (auto& x : parent) x--;
  vvi adj(n);
  fo(i, n - 1) {
    adj[parent[i]].pb(i + 1);
  }
  string s;
  cin >> s;
  vvi dp(n, vi(3, -1));
  auto help = [&](int nd) -> int {
    int out = 0;
    if (s[nd] == 'C')
      out = C1;
    else if (s[nd] == 'P')
      out = P1;
    else
      out = S1;
    return out;
  };
  auto fn = [&](auto&& fn, int nd, int in) -> int {
    if (dp[nd][in] != -1) return dp[nd][in];
    debug(nd, in);
    int out = help(nd);
    if (in == P1) {
      if (out == P1 || out == S1) {
        int ans = (out == S1);
        for (auto c : adj[nd]) ans += fn(fn, c, out);
        return dp[nd][in] = ans;
      }

      int ans1 = 1;
      for (auto c : adj[nd]) ans1 += fn(fn, c, S1);
      int ans2 = 0;
      for (auto c : adj[nd]) ans2 += fn(fn, c, P1);

      return dp[nd][in] = min(ans1, ans2);
    } else if (in == S1) {
      if (out == P1 || out == S1) {
        int ans = (out == P1);
        for (auto c : adj[nd]) ans += fn(fn, c, out);
        return dp[nd][in] = ans;
      }

      int ans1 = 1;
      for (auto c : adj[nd]) ans1 += fn(fn, c, P1);
      int ans2 = 0;
      for (auto c : adj[nd]) ans2 += fn(fn, c, S1);

      return dp[nd][in] = min(ans1, ans2);
    }
    return INF;
  };
  cout << min(fn(fn, 0, P1), fn(fn, 0, S1)) << endl;
}

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1000;
  cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
