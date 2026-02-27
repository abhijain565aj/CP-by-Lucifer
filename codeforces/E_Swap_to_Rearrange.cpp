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
constexpr int INF = 1e9;

void solve();

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1;
  cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
using tup = array<int, 3>;
void solve() {
  int n;
  cin >> n;
  vi a(n), b(n);
  read(a, n);
  read(b, n);

  // even check
  vi freq(n + 1);
  fo(i, n) freq[a[i]]++;
  fo(i, n) freq[b[i]]++;
  fo(i, n + 1) if (freq[i] % 2) {
    cout << -1 << endl;
    return;
  }

  // new adj list
  v(tup) arr;
  fo(i, n) if (a[i] != b[i]) arr.pb({a[i], b[i], i});
  v(set<tup>) adj(n + 1);
  for (auto t : arr) adj[t[0]].insert(t), adj[t[1]].insert(t);

  vi swaps;
  vi vis(n);
  vector<tup> st;
  auto remove = [&](v(tup) p) {
    for (auto t : p) {
      vis[t[2]] = 2;
      adj[t[0]].erase(t);
      adj[t[1]].erase(t);
    }
    tup last = {p[0][1], p[0][0], p[0][2]};
    for (auto t : p) {
      if (t[0] == last[0] || t[1] == last[1]) {
        swaps.pb(t[2]);
        last = {t[1], t[0], t[2]};
      } else {
        last = t;
      }
    }
  };
  
  auto dfs = [&](auto&& dfs, tup node, int inp) -> void {
    if (vis[node[2]] == 2)
      return;
    if (vis[node[2]]) {
      v(tup) cycle;
      while (st.back() != node) {
        cycle.pb(st.back());
        st.pop_back();
      }
      cycle.pb(st.back());
      st.pop_back();
      remove(cycle);
      return;
    }
    vis[node[2]] = 1;
    st.push_back(node);
    auto rec = [&](auto&& rec, int t) -> void {
      adj[t].erase(node);
      while (!adj[t].empty()) {
        auto it = *adj[t].begin();
        dfs(dfs, it, t);
        if (st.empty()) return;
        if (st.back() != node) return;
      }
      return;
    };
    if (node[0] != inp) {
      rec(rec, node[0]);
    } else {
      rec(rec, node[1]);
    }
  };
  for (auto& p : arr) {
    if (!vis[p[2]]) {
      dfs(dfs, p, -1);
    }
  }
  cout << swaps.size() << endl;
  for (auto i : swaps) {
    cout << i + 1 << " ";
    //  swap(a[i], b[i]);
  }
  cout << endl;
  // sortall(a);
  // sortall(b);
  // assert(a == b);
}