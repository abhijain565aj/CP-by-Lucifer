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
  int n, k;
  cin >> n >> k;
  string s, t;
  cin >> s >> t;
  map<int, int> mp;
  auto check = [&](int v) -> bool {
    deque<pair<int, char>> dq;
    fo(i, n) dq.push_back({i, s[i]});
    for (int i = 0; i < n; i++) {
      if (dq.size() == 0) return false;
      if (i - dq.front().F > v) {
        dq.pop_front();
      }
      while (dq.size() && t[i] != dq.front().S) {
        dq.pop_front();
      }
      if (dq.size() == 0) return false;
      if (dq.front().F > i) return false;
      mp[i] = dq.front().F;
    }
    return true;
  };
  int l = 0, r = k;
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (!check(l)) {
    cout << -1 << endl;
    return;
  }
  debug(mp);
  for (auto& [i, j] : mp) {
    j = i - j;
  }
  cout << l << endl;
  vs a;
  fo(i, l) {
    string x = s;
    fo(i, n) if (mp[i] > 0) x[i] = s[i - 1], mp[i]--;
    a.pb(x);
    s = x;
  }
  fo(i, l) {
    cout << a[i] << endl;
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
