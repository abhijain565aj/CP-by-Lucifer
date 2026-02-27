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
void solve() {
  int n;
  cin >> n;
  vector<set<int>> adj(n + 1);
  vector<bool> found(n);
  found[0] = true;
  vi last_res;
  int qc = 0;
  auto ask = [&](int i) -> vi {
    qc++;
    cout << "? " << i << endl;
    int sz;
    cin >> sz;
    if (sz == 0) return {};
    vi res(sz);
    read(res, sz);
    fo(i, sz - 1) adj[res[i] - 1].insert(res[i + 1] - 1);
    fo(i, sz) found[res[i] - 1] = true;
    return res;
  };
  int cnt = 1;
  int delta = 1;
  while (true) {
    auto res = ask(cnt + 1);
    if (res.empty()) break;
    delta = res[0];
    vi toposort;
    vi vis(n);
    auto dfs = [&](int u, auto&& dfs) -> void {
      if (vis[u]) return;
      vis[u] = true;
      for (int v : adj[u]) {
        dfs(v, dfs);
      }
      toposort.pb(u);
    };
    fo(i, n) if (found[i] && !vis[i]) dfs(i, dfs);
    cnt = 0;
    map<int, int> mp;
    for (int i : toposort) {
      mp[i] = 1;
      for (auto j : adj[i]) mp[i] += mp[j];
    }
    for (int i = 1; i <= delta; i++) cnt += mp[i - 1];
  }
  int m = 0;
  for (auto& s : adj) m += s.size();
  debug(qc);
  cout << "! " << m << endl;
  fo(i, n) for (int j : adj[i]) cout << i + 1 << ' ' << j + 1 << "\n";
  cout.flush();
}
