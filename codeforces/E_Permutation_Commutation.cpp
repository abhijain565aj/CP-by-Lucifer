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

void solve() {
  int n;
  cin >> n;

  vi a(n), b(n);
  read(a, n);
  read(b, n);

  fo(i, n) {
    a[i]--;
    if (b[i] != -1) b[i]--;
  }

  set<int> s;
  fo(i, n) if (b[i] != -1) s.insert(i);

  while (!s.empty()) {
    auto i = *s.begin();
    s.erase(i);
    if (b[a[i]] == -1) b[a[i]] = a[b[i]], s.insert(a[i]);
    if (b[a[i]] != a[b[i]]) {
      cout << "NO" << endl;
      return;
    }
  }

  debug(b);

  vi vis(n, 0);
  int curr = 1;

  auto dfs = [&](auto&& dfs, int nxt) -> void {
    vis[nxt] = curr;
    if (vis[a[nxt]] == 0) dfs(dfs, a[nxt]);
  };

  fo(i, n) if (vis[i] == 0) {
    dfs(dfs, i);
    curr++;
  }

  map<int, vi> mp;  // grp -> indices
  fo(i, n) mp[vis[i]].pb(i);

  set<int> bcr(all(b));  // already existing cycle indices
  map<int, vi> mp2;

  // insert for the same size of cycles in mp2
  for (auto& [_, v] : mp) {
    if (bcr.find(v[0]) != bcr.end()) continue;
    for (auto& j : v) mp2[v.size()].pb(j);
  }

  for (auto& [_, v] : mp2) reverse(all(v));

  debug(mp2);
  debug(mp);

  fo(i, n) if (b[i] == -1) {
    auto& cyc = mp[vis[i]];
    int sz = cyc.size();
    for (auto& j : cyc) {
      b[j] = mp2[sz].back();
      mp2[sz].pop_back();
    }
  }

  set<int> check(all(b));
  if ((int)check.size() != n) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  for (auto& x : b) cout << x + 1 << " ";
  cout << endl;
}
