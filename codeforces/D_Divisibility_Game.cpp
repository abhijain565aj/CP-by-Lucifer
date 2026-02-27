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
constexpr int N = 1e6;
constexpr int INF = 1e18;

void solve();
// v(v(pii)) pf(N + 1);
// vvi fac(N + 1);
signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  // for (int i = 2; i <= N; ++i) {
  //   if (pf[i].empty()) {
  //     for (int j = i; j <= N; j += i) {
  //       int cnt = 0, x = j;
  //       while (x % i == 0) {
  //         x /= i;
  //         cnt++;
  //       }
  //       pf[j].emplace_back(i, cnt);
  //     }
  //   }
  // }

  // for (int i = 1; i <= N; ++i) {
  //   for (int j = i; j <= N; j += i) {
  //     fac[j].push_back(i);
  //   }
  // }

  int testCases = 1;
  cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
// void solve() {
//   int n, m;
//   cin >> n >> m;
//   map<int, int> pc;
//   vi a(n), b(m);
//   read(a, n);
//   read(b, m);
//   sortall(a);
//   a.resize(unique(all(a)) - a.begin());
//   for (int x : a) {
//     for (auto& p : pf[x]) {
//       pc[p.F] = max(pc[p.F], p.S);
//     }
//   }
//   int val = 1;
//   for (auto& p : pc) {
//     for (int i = 0; i < p.S; ++i) {
//       if (val >= 1e9) break;
//       val *= p.F;
//     }
//   }

//   int all = 0;
//   for (int x : b) {
//     if (x == val) all++;
//   }

//   int none = 0;
//   for (int x : b) {
//     bool possible = true;
//     for (auto& p : fac[x]) {
//       if (lower_bound(all(b), p) != b.end()) {
//         possible = false;
//         break;
//       }
//     }
//     if (possible) none++;
//   }
//   debug(all, none);
//   if (all > none) {
//     cout << "Alice\n";
//   } else {
//     cout << "Bob\n";
//   }
// }

void solve() {
  int n, m;
  cin >> n >> m;

  vi a(n), b(m);
  read(a, n);
  read(b, m);

  int L = 1;
  for (int x : a) {
    int g = __gcd(L, (long long)x);
    if (L / g > 1e9) {
      L = 1e9;
      break;
    }
    L = (L / g) * x;
  }

  int max_b = *max_element(all(b));
  vi c(max_b + 1, false);
  sort(a.begin(), a.end());
  a.resize(unique(all(a)) - a.begin());

  for (int x : a) {
    if (x > max_b) break;
    if (c[x]) continue;

    for (int j = x; j <= max_b; j += x) {
      c[j] = true;
    }
  }

  int div = 0;
  int all = 0;

  for (int y : b) {
    if (c[y]) div++;
    if (L <= max_b && y % L == 0) all++;
  }

  int c_AB = div - all;
  int none = m - div;

  if (all - none + (c_AB % 2) > 0) {
    cout << "Alice\n";
  } else {
    cout << "Bob\n";
  }
}
