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
  ll n, k, s, q;
  cin >> n >> k >> s >> q;
  vector<set<int>> colors(n);
  vvi adj(n);
  fo(i, n - 1) {
    ll u, v;
    cin >> u >> v;
    adj[u - 1].pb(v - 1);
    adj[v - 1].pb(u - 1);
  }
  fo(i, s) {
    int v, x;
    cin >> v >> x;
    colors[v - 1].insert(x);
  }
  vvi parents(n, vi(20, -1));
  v(v(set<int>)) color_parents(n, vector<set<int>>(20, set<int>()));
  vi powers;
  fo(i, 20) powers.pb(1 << i);
  debug(powers);
  vi call_stack;
  v(set<int>) color_stack;
  set<int> current_set;
  fo(i, k) current_set.insert(i + 1);
  vi distance(n);
  auto dfs = [&](auto&& dfs, int current) -> void {
    int sz = call_stack.size();
    fo(i, 20) {
      int ind = sz - (1 << i);
      if (ind >= 0) {
        parents[current][i] = call_stack[ind];
        color_parents[current][i] = color_stack[ind];
      } else
        break;
    }
    call_stack.pb(current);
    set<int> temp;
    set_intersection(all(colors[current]), all(current_set), inserter(temp, temp.begin()));
    current_set = temp;
    color_stack.pb(current_set);
    for (auto c : adj[current]) {
      if (c == parents[current][0]) continue;
      distance[c] = distance[current] + 1;
      dfs(dfs, c);
    }
    call_stack.pop_back();
    color_stack.pop_back();
    current_set = color_stack.empty() ? set<int>() : color_stack.back();
  };
  dfs(dfs, 0);
  debug(parents);
  debug(distance);
  auto ancestor = [&](int n, int k) -> pair<int, set<int>> {
    vi bin;
    fo(i, 20) {
      if (k & (1 << i)) bin.pb(i);
    };
    vector<set<int>> colors;
    for (auto x : bin) {
      n = parents[n][x];
      colors.pb(color_parents[n][x]);
      if (n == -2) break;
    }
    set<int> ans;
    for (auto& c : colors) {
      if (ans.empty())
        ans = c;
      else {
        set<int> temp;
        set_intersection(all(ans), all(c), inserter(temp, temp.begin()));
        ans = temp;
      }
    }
    return {n, ans};
  };
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    if (distance[u] > distance[v]) swap(u, v);
    auto [anc, color] = ancestor(v, distance[v] - distance[u]);
    v = anc;
    while (u != v) {
      re(i, 20) {
        if (parents[u][i] != parents[v][i]) {
          u = parents[u][i];
          v = parents[v][i];
          auto set1 = color_parents[u][i];
          auto set2 = color_parents[v][i];
          // intersect color with set1 and set2
          set<int> temp;
          set_intersection(all(color), all(set1), inserter(temp, temp.begin()));
          color = temp;
          temp.clear();
          set_intersection(all(color), all(set2), inserter(temp, temp.begin()));
          color = temp;
          break;
        }
      }
      if (parents[u][0] == parents[v][0]) {
        u = v = parents[u][0];
        break;
      }
    }
    cout << color.size() << " ";
    // cout << ans - 2 * distance[u] << "\n";
  }
  cout << "\n";
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
