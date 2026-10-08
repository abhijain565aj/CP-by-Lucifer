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

struct DSU {
  vector<int> parent, size;
  int components;
  DSU(int n) {
    parent.resize(n);
    size.resize(n, 1);
    components = n;
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }
  int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
  }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      if (size[x] < size[y])
        swap(x, y);
      parent[y] = x;
      size[x] += size[y];
      components--;
    }
  }
  inline bool same(int x, int y) {
    return find(x) == find(y);
  }
  inline int getSize(int x) {
    return size[find(x)];
  }
  inline int getComponents() {
    return components;
  }
};

struct soulsold {};

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<array<int, 3>> edges(m);
  int total = 0;
  for (auto& [w, u, v] : edges) {
    cin >> u >> v >> w;
    --u, --v;
    total += w;
  }
  sort(all(edges));

  DSU dsu(n);
  vi weights;
  for (auto [w, u, v] : edges) {
    if (!dsu.same(u, v)) {
      dsu.unite(u, v);
      weights.pb(w);
    }
  }

  int must_add = dsu.getComponents() - 1;
  sortall(weights);
  int sum = 0;
  for (auto w : weights)
    sum += w;
  int profit = total - sum;  // must use
  int L = weights.size();

  vi suffix(L + 1, 0);
  for (int i = L - 1; i >= 0; i--) {
    suffix[i] = suffix[i + 1] + weights[i];
  }

  while (q--) {
    int x;
    cin >> x;

    auto check = [&](int s) -> bool {
      if (s == 0) return true;

      int w = weights[L - s];
      int new_r = must_add + s;

      return w >= new_r * x;
    };

    int l = 0, r = L;

    while (l < r) {
      int mid = (l + r + 1) / 2;

      if (check(mid))
        l = mid;
      else
        r = mid - 1;
    }

    int new_profit = suffix[L - l];

    int new_r = must_add + l;
    int cost = x * new_r * (new_r + 1) / 2;

    cout << profit + new_profit - cost << " ";
  }

  cout << '\n';
}