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
  int n, m, k;
  cin >> n >> m >> k;
  using A = array<int, 3>;
  vector<map<int, A>> a(n);
  fo(i, m) {
    int u, v, r, c;
    cin >> u >> v >> r >> c;
    u--, v--;
    a[u][i] = {v, r, c};
  }
  int ans = 0;
  while (k--) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vi dis(n, INF);
    v(pii) par(n, {-1, -1});
    pq.push({0, 0});
    dis[0] = 0;
    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      if (d != dis[u]) continue;
      for (auto& [eid, t] : a[u]) {
        auto [v, r, c] = t;
        if (r) {
          int nd = d + c;
          if (nd < dis[v]) {
            dis[v] = nd;
            par[v] = {u, eid};
            pq.push({nd, v});
          }
        }
      }
    }
    debug(a);
    debug(dis);
    if (dis[n - 1] == INF) {
      ans = -1;
      break;
    }
    ans += dis[n - 1];
    debug(dis);
    int curr = n - 1;
    while (curr != -1) {
      auto [p, eid] = par[curr];
      if (eid != -1) a[p][eid][1]--;
      curr = p;
    }
  }
  cout << ans << endl;
}
