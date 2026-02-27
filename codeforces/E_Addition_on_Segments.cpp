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

// constexpr int MOD = 1000000007;
int MOD = 1000000007;
constexpr int N = 10000;
constexpr int INF = 1e18;

mt19937 rnd(time(0));

signed main() {
  fastio;
  auto prime = [&](int x) -> bool {
    for (int i = 2; i * i <= x; i++) {
      if (x % i == 0) return false;
    }
    return true;
  };
  MOD = 5e8 + (rand() % (int)5e8);
  while (!prime(MOD)) {
    MOD--;
  }
  int n, q;
  cin >> n >> q;
  vector<array<int, 3>> a;
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;
    a.pb({l, -1, x});
    a.pb({r, +1, x});
  }
  sortall(a);
  vi dp(n + 1, 0);
  vb pos(n + 1, false);
  dp[0] = 1, pos[0] = true;
  auto add = [&](int x) -> void {
    re(i, n + 1) if (i >= x) {
      dp[i] += dp[i - x];
      dp[i] %= MOD;
    }
    fo(i, n + 1) pos[i] = pos[i] || (dp[i] > 0);
  };
  auto del = [&](int x) -> void {
    fo(i, n) if (i + x <= n) {
      dp[i + x] -= dp[i];
      dp[i + x] %= MOD;
      if (dp[i + x] < 0) dp[i + x] += MOD;
    }
  };
  for (auto [_, t, x] : a) {
    if (t == -1)
      add(x);
    else if (t == 1)
      del(x);
  }
  vi ans;
  fo(i, n) if (pos[i + 1]) ans.pb(i + 1);
  cout << ans.size() << endl;
  print_space(ans, (int)ans.size());
}