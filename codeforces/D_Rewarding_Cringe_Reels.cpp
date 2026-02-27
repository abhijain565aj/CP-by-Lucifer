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
  int n, m;
  cin >> n >> m;
  vs a(n);
  for (auto& x : a) cin >> x;
  vvi comp(n, vi(m, 0));
  fo(i, n) fo(j, m) if (a[i][j] == '0') comp[i][j] = -1;
  int current = 1;
  auto fn = [&](auto&& fn, int i, int j) -> void {
    if (i < 0 || i >= n || j < 0 || j >= m) return;
    if (comp[i][j] != 0) return;
    comp[i][j] = current;
    fn(fn, i + 1, j);
    fn(fn, i - 1, j);
    fn(fn, i, j + 1);
    fn(fn, i, j - 1);
  };
  fo(i, n) fo(j, m) if (comp[i][j] == 0) {
    fn(fn, i, j);
    current++;
  }
  debug(comp);
  map<int, array<int, 5>> mp;
  for (int i = 1; i < current; i++) mp[i] = {INF, 0, INF, 0, 0};
  fo(i, n) fo(j, m) if (comp[i][j] != -1) {
    auto& y = mp[comp[i][j]];
    y[0] = min(y[0], i);
    y[1] = max(y[1], i);
    y[2] = min(y[2], j);
    y[3] = max(y[3], j);
    y[4]++;
  }
  for (auto [_, y] : mp) {
    if (y[4] != (y[3] - y[2] + 1) * (y[1] - y[0] + 1)) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  return;
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
