// Solution by Abhi Jain aka Lucifer aka abhijain565aj
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "0_debug.cpp"
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define test(tt)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define INF 1e18

#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define v(x) vector<x>

#define fo(i, n) for (decltype(n) i = 0; i < n; i++)
#define re(i, n) for (decltype(n) i = n - 1; i >= 0; i--)
#define fo1(i, a, b) for (decltype(b) i = a; i < b; i++)
#define re1(i, a, b) for (decltype(a) i = a; i >= b; i--)

#define YN(possible) cout << ((possible) ? "YES" : "NO") << endl;
#define all(x) (x).begin(), (x).end()
#define sortall(x) sort(all(x))
#define F first
#define S second
#define pb push_back
// a.resize(unique(all(a)) - a.begin());  -> unque element me convert karta hai

#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define read(a, n) \
  for (int i = 0; i < n; ++i) cin >> a[i];
#define print_space(a, n) \
  for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');
#define int long long
int N = 3e5 + 1;
vi fact(N);
ll MOD = 1000000007;

// Modular Arithmetic
ll mod(ll a, ll m = MOD) {
  return (a % m + m) % m;
}
ll add(ll a, ll b, ll m = MOD) {
  return mod(a + b, m);
}
ll sub(ll a, ll b, ll m = MOD) {
  return mod(a - b, m);
}
ll mul(ll a, ll b, ll m = MOD) {
  return mod(a * b, m);
}
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
ll inv(ll a, ll m = MOD) {
  return power(a, m - 2, m);
}
ll div(ll a, ll b, ll m = MOD) {
  return mul(a, inv(b, m), m);
}
void solve() {
  int n, m;
  cin >> n >> m;
  vvi adj(n);
  fo(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  debug(adj);
  // checking cycle
  vi vis(n, 0);
  bool cycle = false;
  int comp = 0;
  auto dfs = [&](auto&& dfs, int v, int parent) {
    if (vis[v]) {
      cycle = true;
      return;
    }
    vis[v] = comp;
    for (auto c : adj[v]) {
      if (c == parent) continue;
      dfs(dfs, c, v);
    }
  };
  fo(i, n) if (!vis[i]) {
    comp++;
    dfs(dfs, i, -1);
  }
  if (cycle) {
    cout << 0 << endl;
    return;
  }
  map<int, vector<int>> components;
  fo(i, n) components[vis[i]].pb(i);
  ll count = 1;
  auto fn = [&](int c) -> ll {
    auto& comp = components[c];
    debug(comp);
    // run dfs and find diameter ends;
    int start = comp[0];
    int farthest = start, max_dist = -1;
    map<int, int> dist;
    for (auto i : comp) dist[i] = -1;
    function<void(int, int)> dfs1 = [&](int u, int d) {
      dist[u] = d;
      if (d > max_dist) {
        max_dist = d;
        farthest = u;
      }
      for (int v : adj[u]) {
        if (dist[v] == -1) dfs1(v, d + 1);
      }
    };
    dfs1(start, 0);
    int u1 = farthest;
    debug(u1);
    for (auto i : comp) dist[i] = -1;
    map<int, int> parent;
    for (auto i : comp) parent[i] = -1;
    function<void(int, int)> dfs2 = [&](int u, int d) {
      debug2(u, d);
      dist[u] = d;
      if (d >= max_dist) {
        max_dist = d;
        farthest = u;
      }
      for (int v : adj[u]) {
        if (dist[v] == -1) {
          parent[v] = u;
          dfs2(v, d + 1);
        }
      }
    };
    dfs2(u1, 0);
    int u2 = farthest;
    debug(u2);
    vector<int> diameter;
    ll ans = 1;
    for (int v = u2; v != -1; v = parent[v]) diameter.push_back(v);
    debug(diameter);
    for (int i = 1; i < diameter.size() - 1; i++) {
      int cnt = 0;
      for (auto c : adj[diameter[i]]) {
        cnt += adj[c].size() > 1;
      }
      if (cnt > 2)
        return 0;
      else
        ans = mul(ans, fact[adj[diameter[i]].size() - cnt]);
    }
    debug(ans);
    if (diameter.size() > 3) ans = mul(ans, 2);
    return mul(ans, 2);
  };
  debug(components);
  ll ans = 1;
  fo1(i, 1, comp + 1) {
    ans = mul(ans, fn(i));
  }
  cout << ans << endl;
}

signed main() {
  fastio;
  fact[0] = fact[1] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  // Error_file("0_Error.txt");
  int testCases = 1;
  cin >> testCases;
  fo(tt, testCases) {
    test(tt + 1);
    solve();
  }
  test(0);
}
