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
#define print_space(a, n) \
  for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');

constexpr int MOD = 1000000007;
constexpr int N = 1e5 + 1;
constexpr int INF = 1e18;

struct DSU {
  vector<int> parent, size;  // parent of each node and size of each component
  int components;            // number of connected components
  DSU(int n) {
    parent.resize(n);
    size.resize(n, 1);
    components = n;
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }
  int find(int x) {
    if (parent[x] == x) {
      return x;
    }
    return parent[x] = find(parent[x]);  // path compression
  }
  void unite(int x, int y) {
    x = find(x);  // find the parent of x
    y = find(y);  // find the parent of y
    if (x != y)   // if x and y are not in the same component
    {
      if (size[x] < size[y]) {
        swap(x, y);
      }
      parent[y] = x;
      size[x] += size[y];
      components--;
    }
  }
  bool same(int x, int y)  // check if x and y are in the same component
  {
    return find(x) == find(y);
  }
  int getSize(int x)  // get the size of the component of x
  {
    return size[find(x)];
  }
  int getComponents()  // get the number of connected components
  {
    return components;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<map<int, int>> g(n);
  map<pii, int> ei;
  fo(i, m) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u][v] = w;
    g[v][u] = w;
    ei[{u, v}] = i + 1;
    ei[{v, u}] = i + 1;
  }
  int start;
  cin >> start;
  start--;
  debug(g);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, start});
  vector<int> dist(n, INF);
  vector<int> parent(n, -1);
  dist[start] = 0;
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dist[u]) continue;
    for (auto& [v, w] : g[u]) {
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        parent[v] = u;
        pq.push({dist[v], v});
      }
      if (dist[u] + w == dist[v] && g[u][v] < g[parent[v]][v]) {
        parent[v] = u;
      }
    }
  }
  int sum = 0;
  v(pii) edges;
  for(int i = 0; i < n; i++) {
    if (parent[i] != -1) {
      edges.pb({parent[i], i});
      sum += g[parent[i]][i];
    }
  }
  cout << sum << endl;
  for (auto& [u, v] : edges) {
    cout << ei[{u, v}] << " ";
  }
}

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1;
  // cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
