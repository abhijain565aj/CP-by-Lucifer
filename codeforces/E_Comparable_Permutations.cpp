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

vi perm = {2, 3, 5, 7, 1, 4, 6};
vi fac = {1, 1, 2, 6, 24, 120, 720, 5040};
vi brute() {
  int n = perm.size();
  auto revPerm = perm;
  reverse(all(revPerm));
  vi a(n);
  fo(i, n) a[i] = i + 1;
  for (int i = 0; i < fac[n]; i++) {
    auto b = a;
    reverse(all(b));
    if (a > perm && b > revPerm) {
      return a;
    }
    next_permutation(all(a));
  }
  return {};
}
vi brute1() {
  int n = perm.size();
  // int n;
  // cin >> n;
  // vi perm(n);
  // read(perm, n);
  re(i, n) {
    set<int> rt;
    set<int> lt;
    for (int j = i + 1; j < n; j++) {
      lt.insert(perm[j]);
    }
    set<pii> cand;
    for (int j = n - 1; j > i; j--) {
      lt.erase(perm[j]);
      if (perm[j] > perm[i]) {
        if (lt.size() && *lt.rbegin() > perm[j]) {
          cand.insert({perm[j], j});
        } else if (rt.size() && *rt.begin() < perm[i]) {
          cand.insert({perm[j], j});
        }
      }
      rt.insert(perm[j]);
    }
    auto cp = perm;
    if (cand.size()) {
      auto [val, idx] = *cand.begin();
      swap(cp[i], cp[idx]);
      sort(cp.begin() + i + 1, cp.end());
      return cp;
    }
  }
  return {};
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void check() {
  int tc = 100;
  fo(t, tc) {
    debug(t);
    auto res1 = brute();
    auto res2 = brute1();
    shuffle(all(perm), rng);
    if (res1 != res2) {
      debug(perm, res1, res2);
      cout << "Mismatch\n";
      return;
    }
  }
}
vi ind(vi perm1, vi perm2) {
  int n = perm1.size();
  vi pos(n + 1);
  fo(i, n) pos[perm1[i]] = i;
  vi res(n);
  fo(i, n) res[i] = pos[perm2[i]] + 1;
  return res;
}
void check2(int n) {
  perm.resize(n);
  fo(i, n) perm[i] = i + 1;
  shuffle(all(perm), rng);
  auto res = brute1();
  auto index = ind(perm, res);
  debug(index);
  fo(i, n) if (index[i] != i + 1) {
    cout << i << endl;
    return;
  }
}
void solve() {
}
signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1000;
  cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    // solve();
    solve();
    check2(10);
  }
  // check();
}
