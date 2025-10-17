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
  auto ask = [&](string s, int k) -> int {
    cout << "? " << s << " " << k << endl;
    int v;
    cin >> v;
    return v;
  };
  int n;
  cin >> n;
  v(pii) V(n);
  fo(i, n) cin >> V[i].F >> V[i].S;
  pii A1 = V[0], A2 = V[0];
  fo(i, n) if (V[i].F + V[i].S > A1.F + A1.S) A1 = V[i];
  fo(i, n) if (V[i].F - V[i].S > A2.F - A2.S) A2 = V[i];
  auto [a, b] = A1;
  auto [c, d] = A2;
  int mx = 1e9;
  ask("R", mx);
  ask("R", mx);
  ask("U", mx);
  int v1 = ask("U", mx);
  ask("D", mx);
  ask("D", mx);
  ask("D", mx);
  int v2 = ask("D", mx);

  int z1 = v1 + a + b - 4 * mx;
  int z2 = v2 + c - d - 4 * mx;
  cout << "! " << (z1 + z2) / 2 << " " << (z1 - z2) / 2 << endl;
}

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
