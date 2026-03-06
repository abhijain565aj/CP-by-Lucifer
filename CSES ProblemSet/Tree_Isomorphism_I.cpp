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
#include "./DEBUG.cpp"
#define local true
#else
#define debug(...)
#define Test(tt)
#define Error_file(x)
#define local false
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

#define fo(i, n) for (int i = 0; i < n; i++)
#define re(i, n) for (int i = n - 1; i >= 0; i--)
#define loop(i, a, b) for (int i = a; (a >= b) ? i >= b : i <= b; (a >= b) ? i-- : i++)

#define YN(possible) cout << ((possible) ? "YES" : "NO") << endl;
#define all(x) (x).begin(), (x).end()
#define sortall(x) sort(all(x))
#define F first
#define S second
#define pb push_back
// a.resize(unique(all(a)) - a.begin());

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

  int testCases = 1;
  cin >> testCases;

  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
// Modular Arithmetic
ll mod(ll a, ll m = MOD) { return (a % m + m) % m; }
ll add(ll a, ll b, ll m = MOD) { return mod(a + b, m); }
ll sub(ll a, ll b, ll m = MOD) { return mod(a - b, m); }
ll mul(ll a, ll b, ll m = MOD) { return mod(a * b, m); }
ll power(ll a, ll b, ll m = MOD) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res = mul(res, a, m);
    a = mul(a, a, m);
    b >>= 1;
  }
  return res;
}
ll inv(ll a, ll m = MOD) { return power(a, m - 2, m); }
ll divide(ll a, ll b, ll m = MOD) { return mul(a, inv(b, m), m); }

void solve() {
  int n;
  cin >> n;
  vvi adj1(n), adj2(n);
  fo(i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj1[u].pb(v);
    adj1[v].pb(u);
  }
  fo(i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj2[u].pb(v);
    adj2[v].pb(u);
  }
  auto dfs = [&](auto&& dfs, vvi& adj, int nd, int p) -> int {
    int hash = 1;
    for (auto x : adj[nd]) {
      if (x == p) continue;
      hash = mul(hash, power(3, dfs(dfs, adj, x, nd)));
    }
    return power(2, hash);
  };
  bool y = dfs(dfs, adj1, 0, -1) == dfs(dfs, adj2, 0, -1);
  YN(y);
}
