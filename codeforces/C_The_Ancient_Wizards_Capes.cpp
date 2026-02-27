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

constexpr int MOD = 676767677;
constexpr int N = 1e5 + 1;
constexpr int INF = 1e18;

void solve() {
  int n;
  cin >> n;
  vi a(n);
  vi b(n, -2);
  read(a, n);
  fo(i, n - 1) {
    if (a[i] == a[i + 1]) {
      if (b[i] == -2)
        b[i] = 0;
      else
        b[i + 1] = -b[i];
    } else if (a[i] == a[i + 1] + 1) {
      if (b[i] != -2 && b[i] != -1) {
        cout << 0 << endl;
        return;
      } else {
        b[i] = -1;
        b[i + 1] = -1;
      }
    } else if (a[i] + 1 == a[i + 1]) {
      if (b[i] != 1 && b[i] != -2) {
        cout << 0 << endl;
        return;
      } else {
        b[i] = 1;
        b[i + 1] = 1;
      }
    } else {
      cout << 0 << endl;
      return;
    }
  }
  auto check = [&](vi& arr) -> bool {
    debug(arr);
    vi pref(n, 0);
    pref[0] = arr[0] == 1;
    fo1(i, 1, n) pref[i] = pref[i - 1] + (arr[i] == 1);
    vi suff(n, 0);
    suff[n - 1] = arr[n - 1] == -1;
    re1(i, n - 2, 0) suff[i] = suff[i + 1] + (arr[i] == -1);
    fo(i, n) if (pref[i] + suff[i] != a[i]) return false;
    return true;
  };
  debug(b);
  int ans = 1;
  if (b[n - 1] == -2) {
    vi poss1 = b;
    poss1[n - 1] = 1;
    re(i, n - 1) if (poss1[i] == 0) poss1[i] = -poss1[i + 1];
    vi poss2 = b;
    poss2[n - 1] = -1;
    re(i, n - 1) if (poss2[i] == 0) poss2[i] = -poss2[i + 1];
    ans = check(poss1) + check(poss2);
  } else {
    re(i, n - 1) if (b[i] == 0) b[i] = -b[i + 1];
    ans = check(b);
  }
  cout << ans << endl;
  debug(b);
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
