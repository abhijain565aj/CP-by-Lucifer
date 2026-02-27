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
  vi a(n);
  read(a, n);
  if (m > n / 2) {
    cout << -1 << endl;
    return;
  }

  vector<array<int, 3>> arr;
  fo(i, n) arr.pb({a[i], a[i], i});
  sortall(arr);

  int alive = n;
  v(pii) ans;
  array<int, 3> last = arr.back();
  arr.pop_back();
  if (m == 0) {
    int i = 0;
    for (i = 0; i < n - 1; i++) {
      if (last[0] - arr[i][1] > 0) {
        last[0] -= arr[i][1];
        ans.pb({arr[i][2], last[2]});
      } else {
        break;
      }
    }
    arr.erase(arr.begin(), arr.begin() + i);
    if (arr.size() == 0) {
      cout << -1 << endl;
      return;
    }
  } else {
    alive--;
    last[0] -= arr[0][1];
    ans.pb({arr[0][2], last[2]});
    arr.erase(arr.begin());
  }
  debug(last, arr);
  while (alive > m + 1 && arr.size() >= 2) {
    debug(arr);
    int sz = arr.size();
    int odd = sz % 2;
    fo(i, sz / 2) if (alive > m + 1) {
      arr[i][0] -= arr[sz - 1 - i - odd][1];
      arr[sz - 1 - i - odd][0] -= arr[i][1];
      ans.pb({arr[i][2], arr[sz - 1 - i - odd][2]});
      if (arr[sz - 1 - i - odd][0] <= 0) alive--;
      if (arr[i][0] <= 0) alive--;
    }
    vector<array<int, 3>> narr;
    fo(i, arr.size()) if (arr[i][0] > 0) narr.pb(arr[i]);
    sortall(narr);
    swap(arr, narr);
  }
  set<int> l;
  if (m == 0) {
    ans.pb({arr[0][2], last[2]});
    arr.clear();
  } else if (alive != m) {
    ans.pb({last[2], arr[0][2]});
    arr.erase(arr.begin());
  } else {
    l.insert(last[2]);
  }
  for (auto x : arr) l.insert(x[2]);
  for (auto& [x, y] : ans) {
    if (l.find(y) != l.end()) {
      swap(x, y);
      l.erase(y);
    }
  }
  debug(arr);
  debug(ans);
  cout << ans.size() << endl;
  for (auto [x, y] : ans) cout << x + 1 << " " << y + 1 << "\n";
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
