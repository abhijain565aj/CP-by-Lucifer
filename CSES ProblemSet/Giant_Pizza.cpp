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
  int n, m;
  cin >> m >> n;
  vvi adj(n * 2), radj(2 * n);
  fo(i, m) {
    char c1, c2;
    int x1, x2;
    cin >> c1 >> x1 >> c2 >> x2;
    x1--, x2--;
    int x1c = x1 + n, x2c = x2 + n;
    if (c1 == '-') swap(x1, x1c);
    if (c2 == '-') swap(x2, x2c);
    adj[x1c].pb(x2);
    adj[x2c].pb(x1);
    radj[x2].pb(x1c);
    radj[x1].pb(x2c);
  }

  vi vis(2 * n);
  stack<int> st;
  auto dfs1 = [&](auto&& dfs1, int nd) -> void {
    vis[nd] = 1;
    for (auto x : adj[nd]) {
      if (!vis[x]) dfs1(dfs1, x);
    }
    st.push(nd);
  };
  fo(i, 2 * n) if (!vis[i]) {
    dfs1(dfs1, i);
  }
  vi comp(2 * n, -1);
  int curr = 0;
  auto dfs2 = [&](auto&& dfs2, int nd) -> void {
    comp[nd] = curr;
    for (auto x : radj[nd]) {
      if (comp[x] == -1) dfs2(dfs2, x);
    }
  };
  while (!st.empty()) {
    auto t = st.top();
    st.pop();
    if (comp[t] != -1) continue;
    dfs2(dfs2, t);
    curr++;
  }
  fo(i, n) if (comp[i] == comp[i + n]) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  fo(i, n) {
    cout << (comp[i] > comp[i + n] ? "+" : "-") << " ";
  }
}
