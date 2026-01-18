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
  int r, c;
  cin >> r >> c;
  vs a(r);
  read(a, r);
  vi rt(r, 0), ct(c, 0);
  fo(i, r) fo(j, c) if (a[i][j] == '.') rt[i]++, ct[j]++;
  int ans = 0;
  fo(j, c) {
    int sum = 0;
    int down = 0;
    re(i, r) if (a[i][j] == '.') {
      auto self = rt[i] + ct[j] - 3;
      ans += sum * self;
      ans += max(down * (rt[i] - 1) * (ct[j] - 2), 0LL);
      ans += max(down * (ct[j] - 2) * (ct[j] - 3), 0LL);
      sum += rt[i] - 1;
      down++;
      debug(ans);
    }
  }
  fo(i, r) {
    int sum = 0;
    int right = 0;
    re(j, c) if (a[i][j] == '.') {
      auto self = ct[j] + rt[i] - 3;
      ans += sum * self;
      ans += max(right * (ct[j] - 1) * (rt[i] - 2), 0LL);
      ans += max(right * (rt[i] - 2) * (rt[i] - 3), 0LL);
      sum += ct[j] - 1;
      right++;
    }
  }
  ans *= 2;
  cout << ans << "\n";
}

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1;
  //   cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
