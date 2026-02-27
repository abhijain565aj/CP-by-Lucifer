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

void solve() {
  int n;
  cin >> n;
  vi a(n);
  read(a, n);
  fo(i, n) a[i]--;
  vvi adj(n);
  fo(i, n) {
    adj[a[i]].pb(i);
  }
  vi visited(n, false);
  vi stack;
  vi dis(n, 0);
  vi dis2(n, 1);
  auto dfs = [&](auto& dfs, int node) -> void {
    visited[node] = 1;
    stack.pb(node);
    for (auto& child : adj[node]) {
      if (visited[child] == 1) {
        re(i, (int)stack.size()) if (stack[i] == child) break;
        else dis[stack[i]] = -1;
        dis[child] = -1;
      } else if (visited[child] == 0) {
        dfs(dfs, child);
      }
    }
    stack.pop_back();
    visited[node] = 2;
  };
  fo(i, n) {
    if (visited[i] == 0) {
      dfs(dfs, i);
    }
  }
  queue<int> leaves;
  vi deg(n, 0);
  fo(i, n) deg[i] = adj[i].size();
  fo(i, n) if (!deg[i]) leaves.push(i);

  while (!leaves.empty()) {
    int nd = leaves.front();
    leaves.pop();
    deg[a[nd]]--;
    if (!deg[a[nd]]) leaves.push(a[nd]);
    if (dis[a[nd]] == -1) continue;
    dis2[a[nd]] = max(dis2[a[nd]], dis2[nd] + 1);
    dis2[nd] = 0;
    // debug(nd, a[nd], dis2[a[nd]]);
  }
  debug(dis, dis2);
  fo(i, n) if (dis[i] == -1) dis2[i] = 0;
  int mx = *max_element(all(dis2));
  // if (mx) mx++;
  cout << mx + 2 << endl;
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
