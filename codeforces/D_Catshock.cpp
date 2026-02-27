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

// #define int long long
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
// constexpr int INF = 1e18;

void solve() {
  int n;
  cin >> n;
  vector<set<int>> adj(n);
  fo(i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  vi distance(n);
  vi parent(n, -1);
  auto dfs = [&](auto&& dfs, int u) -> void {
    for (auto v : adj[u]) {
      if (v != parent[u]) {
        parent[v] = u;
        distance[v] = distance[u] + 1;
        dfs(dfs, v);
      }
    }
  };
  dfs(dfs, 0);
  fo(i, n) adj[i].erase(parent[i]);
  // path 0 to n-1
  vi path;
  int curr = n - 1;
  while (curr != -1) {
    path.pb(curr);
    curr = parent[curr];
  }
  set<int> path_set(all(path));
  vi odd, even;
  auto insert = [&](int i) {
    if (path_set.find(i) == path_set.end() && adj[i].empty()) {
      if (distance[i] & 1)
        odd.pb(i);
      else
        even.pb(i);
    }
  };
  fo(i, n) insert(i);
  v(pii) ans;
  int current = 0;
  while (true) {
    if (current == 0 && !odd.empty()) {
      auto l = odd.back();
      ans.pb({2, l});
      adj[parent[l]].erase(l);
      odd.pop_back();
      insert(parent[l]);
    } else if (current == 1 && !even.empty()) {
      auto l = even.back();
      ans.pb({2, l});
      adj[parent[l]].erase(l);
      even.pop_back();
      insert(parent[l]);
    } else if (even.empty() && odd.empty()) {
      auto b = path.back();
      if ((distance[b] & 1) != current) {
        if (b == n - 1) break;
        ans.pb({2, b});
        path.pop_back();
      }
    }
    ans.pb({1, -1});
    current = (current + 1) % 2;
  }
  cout << ans.size() << "\n";
  for (auto p : ans) {
    cout << p.F;
    if (p.S != -1) cout << " " << p.S + 1;
    cout << "\n";
  }
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
