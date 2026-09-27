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
#include "./DEBUG.cpp"
#define local true
#else
#define debug(...)
#define Test(tt)
#define Error_file(x)
#define local false
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

#define fo(i, n) for (int i = 0; i < n; i++)
#define re(i, n) for (int i = n - 1; i >= 0; i--)
#define loop(i, a, b) for (int i = a; (a >= b) ? i >= b : i <= b; (a >= b) ? i-- : i++)

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
#define print(a, n) \
  for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');

void file(string s = "") {
  if (local) {
    // freopen("error.txt", "w", stderr);
    // freopen("output.txt", "w", stdout);
    // freopen(("input" + s + ".txt").c_str(), "r", stdin);
    return;
  }
}

constexpr int MOD = 1000000007;
constexpr int N = 1e5 + 1;
constexpr int INF = 1e18;

void solve();
void precompute();

signed main() {
  fastio;
  file();
  precompute();

  int testCases = 1;
  cin >> testCases;

  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}

void precompute() {
}

// void solve1() {
//   int n;
//   cin >> n;
//   vi a(n);
//   read(a, n);
//   vi even, odd;
//   fo(i, n) {
//     if (a[i] % 2 == 0)
//       even.pb(a[i]);
//     else
//       odd.pb(a[i]);
//   }
//   sortall(even);
//   sortall(odd);

//   int lmx, rmx;
//   bool l_e_turn = true, r_e_turn = true;
//   lmx = rmx = max(even.back(), odd.back());
//   if (lmx = even.back())
//     even.pop_back(), l_e_turn = false, r_e_turn = false;
//   else
//     odd.pop_back();

//   while (!even.empty() && !odd.empty()) {
//     // int& cmx = (lmx > rmx) ? lmx : rmx;
//     // int& cmin = (lmx > rmx) ? rmx : lmx;
//     // auto& lvec = (l_e_turn) ? even : odd;
//     // auto& rvec = (r_e_turn) ? even : odd;
//     // if (l_e_turn) {
//   }
// }

// }

void solve() {
  int n;
  cin >> n;
  vi a(n);
  read(a, n);

  vi pos(n + 1);
  fo(i, n) pos[a[i]] = i;

  int kp = pos[n] & 1;

  bool dp[2] = {true, false};

  for (int x = n - 1; x >= 1; x--) {
    int used = n - 1 - x;
    bool ndp[2] = {false, false};

    fo(l, 2) {
      if (!dp[l])
        continue;
      int r = used - l;

      int leftPos = kp - 1 - l;
      if ((leftPos & 1) == (pos[x] & 1))
        ndp[l ^ 1] = true;
      int rightPos = kp + 1 + r;
      if ((rightPos & 1) == (pos[x] & 1))
        ndp[l] = true;
    }

    dp[0] = ndp[0], dp[1] = ndp[1];
  }

  YN(dp[kp]);
}