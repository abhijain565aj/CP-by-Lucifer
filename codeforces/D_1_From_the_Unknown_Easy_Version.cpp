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
int Limit = 1;
int ask1(vi& v) {
  int c = 1;
  int l = 0;
  fo(i, v.size()) {
    if (v[i] + l > Limit) {
      l = v[i];
      c++;
    } else {
      l += v[i];
    }
    if (v[i] > Limit) return 0;
  }
  return c;
}
void solve() {
  auto ask = [&](vi& v) -> int {
    cout << "? " << v.size() << " ";
    for (auto& x : v) cout << x << " ";
    cout << endl;
    int res;
    cin >> res;
    return res;
  };
  auto ans = [&](int v) -> void {
    cout << "! " << v << endl;
    // if (v != Limit) {
    //   debug(Limit, v);
    // }
  };
  int n = 1e5;
  vi a(n);
  fo(i, n) a[i] = 1;
  map<int, vi> mp;
  fo1(i, 1, n + 1) {
    mp[(n + i - 1) / i].pb(i);
  }
  auto& v = mp[ask(a)];
  vi b;
  for (int i = 1; i <= v.size(); i++) {
    b.pb(v[0]);
    b.pb(i);
  }
  int res = ask(b) - v.size();
  ans(v[v.size() - res]);
}

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1e5;
  cin >> testCases;
  fo(tt, testCases) {
    // Test(tt + 1);
    solve();
    // Limit++;
  }
}
