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
  int n;
  cin >> n;
  vi a(n);
  read(a, n);
  auto b = a;
  map<int, int> pos, pos2;
  fo(i, n) pos[a[i]] = i, pos2[a[i]] = i;
  fo(i, n) {
    while (a[i] > 2 && pos[a[i] - 1] > i && pos[a[i] - 2] > i) {
      int j = pos[a[i] - 2];
      int k = pos[a[i] - 1];
      a[i] -= 2;
      a[j] += 1;
      a[k] += 1;
      pos[a[i]] = i;
      pos[a[j]] = j;
      pos[a[k]] = k;
    }
  }
  swap(a, b);
  fo(i, n) pos[a[i]] = i;
  re(i, n) {
    while (a[i] != n) {
      int j1 = (a[i] != 1) ? pos[a[i] - 1] : -1;
      int j2 = (a[i] != n - 1) ? pos[a[i] + 2] : INF;
      int j3 = pos[a[i] + 1];
      if (j2 < j3 && j3 < i) {
        a[j2] -= 2;
        a[j3] += 1;
        a[i] += 1;
        pos[a[i]] = i;
        pos[a[j2]] = j2;
        pos[a[j3]] = j3;
      } else if (j1 < i && j3 < j1) {
        a[i] += 1;
        a[j1] += 1;
        a[j3] -= 2;
        pos[a[i]] = i;
        pos[a[j1]] = j1;
        pos[a[j3]] = j3;
      } else {
        break;
      }
    }
  }
  if (b < a) swap(a, b);
  print_space(b, n);
  print_space(a, n);
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
