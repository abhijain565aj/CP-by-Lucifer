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
  vi a(n), b(n);
  read(a, n);
  read(b, n);
  auto value = [&](int threshold) -> pair<bool, int> {
    int ops = k;
    int sum = 0;
    auto A = a;
    fo(i, n) {
      // while (A[i] > threshold) {
      //   sum += A[i];
      //   ops--;
      //   A[i] -= b[i];
      // }

      // replacing while loop for optimised solution

      int cnt = (A[i] - threshold + b[i] - 1) / b[i];
      cnt = max(cnt, 0LL);
      ops -= cnt;
      sum -= (cnt * (cnt - 1)) / 2 * b[i];
      sum += A[i] * cnt;
      A[i] -= cnt * b[i];
    }
    fo(i, n) if (A[i] == threshold && ops > 0) {
      sum += A[i];
      ops--;
    }
    return {ops >= 0, sum};
  };
  int l = 0, r = *max_element(all(a));
  while (l < r) {
    int m = (l + r) / 2;
    if (value(m).first) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  debug(l);
  cout << value(l).second << endl;
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
