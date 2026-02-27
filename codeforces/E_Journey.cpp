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
  vi odd_size;
  vector<map<int, int>> mp;
  DSU(int n, vi odd_size) {
    parent.resize(n);
    size.resize(n, 1);
    this->odd_size = odd_size;
    mp.resize(n);
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
  void unite(int x, int y, int w) {
    x = find(x);  // find the parent of x
    y = find(y);  // find the parent of y
    if (x != y)   // if x and y are not in the same component
    {
      if (size[x] < size[y]) {
        swap(x, y);
      }
      parent[y] = x;
      size[x] += size[y];
      if (odd_size[x] % 2 && odd_size[y] % 2) mp[x][w] += 1;
      odd_size[x] += odd_size[y];
      for (auto [a, b] : mp[y]) mp[x][a] += b;
      mp[y].clear();
      components--;
    }
    map<int, int> mpn;
    for (auto [it, c] : mp[x]) {
      if (it < w)
        mpn[it] = c;
      else
        mpn[w] += c;
    }
    swap(mpn, mp[x]);
    debug(mp[x]);
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
  int getAns() {
    int root = find(0);
    int ans = 0;
    for (auto [it, c] : mp[root]) {
      ans += it * c;
    }
    return ans;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> e;
  vi degree(n);
  int wsum = 0;
  fo(i, m) {
    int u, v, w;
    cin >> u >> v >> w;
    e.pb({u - 1, v - 1, w});
    degree[u - 1]++, degree[v - 1]++;
    wsum += w;
  }
  fo(i, n) degree[i] %= 2;
  if (m == 0) {
    cout << 0 << endl;
    return;
  }
  debug(degree);
  DSU dsu(n, degree);
  fo(i, m) {
    dsu.unite(e[i][0], e[i][1], e[i][2]);
  }
  cout << wsum + dsu.getAns() << endl;
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
