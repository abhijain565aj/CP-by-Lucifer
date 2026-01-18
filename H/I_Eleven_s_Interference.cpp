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

signed main() {
  fastio;
  int n;
  cin >> n;
  vi A(n);
  vi W(n);
  fo(i, n) cin >> A[i];
  fo(i, n) cin >> W[i];

  int maxA = *max_element(A.begin(), A.end());
  int B = 0;
  while ((1LL << B) <= maxA) B++;
  if (B < 1) B = 1;
  if (B > 20) B = 20;
  int M = 1 << B;
  int FULL = M - 1;

  vi cnt(M, 0), sumW(M, 0);
  fo(i, n) {
    cnt[A[i]]++;
    sumW[A[i]] += W[i];
  }

  vvi byHB(B);
  for (int mask = 1; mask < M; ++mask) {
    if (cnt[mask] == 0) continue;
    int hb = 31 - __builtin_clz(mask);
    if (hb >= B) hb = B - 1;
    byHB[hb].push_back(mask);
  }

  vi Fcnt(M, 0), Fsum(M, 0), Zcnt(M, 0), Zsum(M, 0);
  ll ans = 0;

  for (int k = 0; k < B; ++k) {
    Zcnt = Fcnt;
    Zsum = Fsum;

    for (int bit = 0; bit < B; ++bit) {
      int shift = 1 << bit;
      for (int mask = 0; mask < M; ++mask) {
        if (mask & shift) {
          Zcnt[mask] += Zcnt[mask ^ shift];
          Zsum[mask] += Zsum[mask ^ shift];
        }
      }
    }

    for (int vmask : byHB[k]) {
      int comp = (~vmask) & FULL;
      ll totalCnt = Zcnt[comp];
      ll totalSum = Zsum[comp];
      ans += totalCnt * sumW[vmask] - cnt[vmask] * totalSum;
    }

    for (int m : byHB[k]) {
      Fcnt[m] += cnt[m];
      Fsum[m] += sumW[m];
    }
  }

  cout << ans << "\n";
  return 0;
}