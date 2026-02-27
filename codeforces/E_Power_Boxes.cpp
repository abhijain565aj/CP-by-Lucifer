// B87678
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
int n;
vi a(n);
int throw_output(int x) {
  x--;
  int cnt = 1;
  while (x < n && x + a[x] < n) {
    x = x + a[x];
    cnt++;
  }
  debug(cnt);
  return cnt;
}
void swap_output(int x) {
  swap(a[x], a[x - 1]);
}
void solve() {
  cin >> n;
  // a.resize(n);
  // read(a, n);
  vi jumps(n + 1, -1);
  vi initial(n, -1);
  fo(i, n) initial[i] = i;
  vi power(n, -1);
  jumps[n] = 0;
  power[n - 1] = jumps[n - 1] = 1;
  auto thr = [&](int x) -> int {
    cout << "throw " << x + 1 << endl;
    int js;
    cin >> js;
    // js = throw_output(x + 1);
    return js;
  };

  auto swp = [&](int x) {
    cout << "swap " << x + 1 << endl;
    swap(power[x], power[x + 1]);
    swap(initial[x], initial[x + 1]);
    // swap_output(x + 1);
  };

  for (int i = n - 2; i >= 0;) {
    debug(power, jumps);
    jumps[i] = thr(i);
    if (power[i + 1] == 1) {
      power[i] = (jumps[i] == jumps[i + 1]) ? 2 : 1;
    } else if (power[i + 2] == 2) {
      power[i] = (jumps[i] == jumps[i + 2] + 1) ? 2 : 1;
    }
    i -= max(power[i], 1ll);
  }
  for (int i = n - 3; i >= 0; i--) {
    jumps[i] = 1 + jumps[power[i] + i];
    if (power[i] == -1) {
      debug(power, jumps);
      if (jumps[i + 1] == jumps[i + 2]) {
        swp(i);
        jumps[i + 1] = thr(i + 1);
        power[i + 1] = (jumps[i + 1] == 1 + jumps[i + 2]) ? 1 : 2;
        jumps[i] = 1 + jumps[i + power[i]];
      } else {
        jumps[i] = thr(i);
        power[i] = (jumps[i] == 1 + jumps[i + 1]) ? 1 : 2;
      }
    }
  }
  swp(n - 2);
  power[n - 2] = 3 - thr(n - 2);
  map<int, int> mp;
  fo(i, n) mp[initial[i]] = power[i];
  cout << "! ";
  fo(i, n) cout << mp[i] << " ";
  cout << endl;
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
