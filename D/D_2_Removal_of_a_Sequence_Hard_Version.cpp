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

double power(double rem, int x) {
  double res = 1.0;
  while (x) {
    if (x & 1) res *= rem;
    rem *= rem;
    x >>= 1;
  }
  return res;
}

void solve() {
  int x, y, k;
  cin >> x >> y >> k;

  auto check = [&](double v) {
    for (int i = 0; i < x;) {
      int cv = v / y;
      if (cv == 0) break;
      int cv_change = 
      v -= v / y;
    }
    return v >= k;
  };
  int left = k, right = 1e12;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (check(mid)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  if (!check(left)) left = -1;
  cout << left << "\n";
}

void brute(int x, int y, int n){
  vi a;
  for (int i = 1; i <= n; i++) a.pb(i);
  fo(i,x){
    vi na;
    fo(j, (int)a.size()) if (j % y != y - 1) na.pb(a[j]);
    swap(na, a);
  }
  // debug(a);
  vi diff;
  fo(i,a.size()-1){
    diff.pb(a[i + 1] - a[i]);
  }
  debug(diff);
}
// pattern in diff repeats with period = (y-1)^x
signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1000;
  cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
    // brute(2, 4, 500);
    // brute(3, 4, 500);
    // brute(4, 4, 500);
  }
}
