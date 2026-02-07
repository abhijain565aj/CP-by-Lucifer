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
constexpr int N = 2e5 + 1;
constexpr int INF = 1e18;

vvi pf(N);
void solve() {
  int n;
  cin >> n;
  v(pii) a(n);
  fo(i, n) cin >> a[i].S;
  fo(i, n) cin >> a[i].F;
  sortall(a);
  map<int, int> fcount;
  auto remove = [&](int x) -> void {
    for (auto p : pf[x]) {
      fcount[p]--;
    }
  };
  auto insert = [&](int x) -> bool {
    bool yes = false;
    for (auto p : pf[x]) {
      fcount[p]++;
      if (fcount[p] > 1) {
        yes = true;
      }
    }
    return yes;
  };
  int ans = a[0].F + a[1].F;
  fo(i, n) if (insert(a[i].S)) {
    cout << 0 << endl;
    return;
  }

  // first element inc by i;
  remove(a[0].S);
  for (auto [p, c] : fcount)
    if (c) {
      ans = min(ans, a[0].F * (p - a[0].S % p));
    }
  insert(a[0].S);
  fo(i, n) if (a[i].F < ans) {
    remove(a[i].S);
    if (insert(a[i].S + 1)) {
      ans = a[i].F;
    }
    remove(a[i].S + 1);
    insert(a[i].S);
  }
  cout << ans << endl;
}

signed main() {
  fastio;
  for (int i = 2; i < N; i++) {
    if (pf[i].empty()) {
      for (int j = i; j < N; j += i) {
        pf[j].pb(i);
      }
    }
  }
  //   Error_file("0_Error.txt");
  int testCases = 1000;
  cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
