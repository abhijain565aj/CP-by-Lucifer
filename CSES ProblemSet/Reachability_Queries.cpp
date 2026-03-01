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

constexpr int MOD = 1000000007;
constexpr int N = 5e4 + 1;
constexpr int INF = 1e18;

void solve();
void precompute();
bitset<N> b[N];
signed main() {
  fastio;
  int n, m, q;
  cin >> n >> m >> q;
  vvi adj(n), radj(n);
  fo(i, m) {
    int u, v;
    cin >> u >> v;
    adj[u - 1].pb(v - 1);
    radj[v - 1].pb(u - 1);
  }
  vi st;
  vi vis(n);
  auto dfs1 = [&](auto&& dfs1, int i) -> void {
    vis[i] = true;
    for (auto x : adj[i]) {
      if (!vis[x]) dfs1(dfs1, x);
    }
    st.pb(i);
  };
  fo(i, n) if (!vis[i]) dfs1(dfs1, i);
  fo(i, n) vis[i] = -1;
  int comp = 0;
  auto dfs2 = [&](auto&& dfs2, int i) -> void {
    vis[i] = comp;
    for (auto x : radj[i])
      if (vis[x] == -1) dfs2(dfs2, x);
  };
  reverse(all(st));
  for (auto x : st)
    if (vis[x] == -1) dfs2(dfs2, x), comp++;
  debug(vis);

  vvi nadj(comp);
  vi cvis(comp);
  fo(i, comp) b[i].set(i);
  fo(i, n) for (auto x : adj[i]) {
    nadj[vis[i]].pb(vis[x]);
  }
  for (auto& v : nadj) {
    sortall(v);
    v.resize(unique(all(v)) - v.begin());
  }
  debug(nadj);
  auto dfs3 = [&](auto&& dfs3, int i) -> void {
    cvis[i] = true;
    for (auto x : nadj[i]) {
      if (!cvis[x]) dfs3(dfs3, x);
      b[i] |= b[x];
    }
  };
  fo(i, comp) if (!cvis[i]) dfs3(dfs3, i);
  while (q--) {
    int u, v;
    cin >> u >> v;
    YN(b[vis[u - 1]][vis[v - 1]]);
  }
}
