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
constexpr int N = 1e7 + 1;
constexpr int INF = 1e18;
vi mex(N, 0);
vi pf(N, 0);
void solve() {
  int n;
  cin >> n;
  vi a(n);
  read(a, n);
  int nim_sum = 0;
  fo(i, n) nim_sum ^= mex[a[i]];
  cout << (nim_sum ? "Alice" : "Bob") << endl;
}

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  for (int i = 2; i < N; i++) {
    if (pf[i] == 0) {
      for (int j = 2 * i; j < N; j += i)
        if (pf[j] == 0) {
          pf[j] = i;
        }
    }
  }
  debug(pf);
  int prime_count = 0;
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) {
      mex[i] = 0;
    } else if (pf[i] == 0) {
      mex[i] = ++prime_count;
    } else {
      mex[i] = mex[pf[i]];
    }
  }
  debug(mex);
  int testCases = 1000;
  cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
