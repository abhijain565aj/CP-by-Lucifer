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
  int n, q;
  cin >> n >> q;
  vi a(n);
  read(a, n);
  for (auto& x : a) x--;
  vi vis(n);
  vi st;          // stack
  vi dis(n, -1);  // repeat distance
  vi comp(n, -1);
  vi cyc(n, 0);  // cycle
  int curr = 0;
  auto dfs = [&](auto&& dfs, int nd) -> void {
    debug(nd);
    if (vis[nd] == 1) {
      vi cycle = {nd};
      while (st.back() != nd) {
        cycle.pb(st.back());
        st.pop_back();
      }
      int i = 1;
      for (auto x : cycle) {
        dis[x] = cycle.size(), vis[x] = 2, cyc[x] = i++;
      }
      return;
    } else if (vis[nd] == 2) {
      return;
    }
    comp[nd] = curr;
    vis[nd] = 1;
    st.pb(nd);
    dfs(dfs, a[nd]);
    if (dis[nd] == -1) {
      dis[nd] = 1 + dis[a[nd]];
      st.pop_back();
      vis[nd] = 2;
    }
  };

  // Distances in powers of 2
  int MX = 20;
  vvi D(MX, vi(n));
  D[0] = a;
  for (int i = 1; i < MX; i++) {
    fo(j, n) D[i][j] = D[i - 1][D[i - 1][j]];
  }

  // calling dfs, var
  fo(i, n) if (!vis[i]) {
    dfs(dfs, i);
    curr++;
  }

  debug(dis, cyc, comp);
  // planet queries 1 - query
  auto DD = [&](int x, int k) -> int {
    for (ll i = MX - 1; i >= 0; i--) {
      if (k >= (1 << i)) {
        x = D[i][x];
        k -= 1 << i;
      }
    }
    return x;
  };

  // main query
  auto query = [&](int a, int b) -> int {
    if (dis[a] < dis[b]) return -1;
    int ans = dis[a] - dis[b];
    a = DD(a, dis[a] - dis[b]);
    if (comp[a] != comp[b] && DD(a, n + 1) != DD(b, n + 1)) return -1;
    debug(ans);
    debug(a, b);
    if (!cyc[a] && !cyc[b]) {
      if (a != b) return -1;
    } else {
      int len = cyc[a] - cyc[b];
      if (len < 0) len += dis[a];
      ans += len;
    }
    return ans;
  };

  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << query(a - 1, b - 1) << endl;
  }
}