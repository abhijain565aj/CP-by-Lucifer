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

constexpr int MOD = 998244353;
constexpr int N = 200000 + 5;
constexpr int INF = (int)1e18;

vvi pf(N);

ll mod(ll a, ll m = MOD) {
  a %= m;
  if (a < 0) a += m;
  return a;
}
ll add(ll a, ll b, ll m = MOD) {
  return mod(a + b, m);
}
ll sub(ll a, ll b, ll m = MOD) {
  return mod(a - b, m);
}
ll mul(ll a, ll b, ll m = MOD) {
  return mod(a * b, m);
}
ll power(ll a, ll b, ll m = MOD) {
  ll res = 1 % m;
  ll x = mod(a, m);
  while (b) {
    if (b & 1) res = mul(res, x, m);
    x = mul(x, x, m);
    b >>= 1;
  }
  return res;
}
ll inv(ll a, ll m = MOD) {
  return power(a, m - 2, m);
}
ll divide(ll a, ll b, ll m = MOD) {
  return mul(a, inv(b, m), m);
}
int pfmax = 7;
// 2*3*5*7*11*13*17

void solve() {
  int n, k;
  cin >> n >> k;
  vi a(n);
  fo(i, n) {
    cin >> a[i];
  }
  vvi freq(n + 1, vi(pfmax));  // [div by d][count of pf]

  vi total_prev_by_omega(pfmax);

  int answer = 0;

  for (auto A : a) {
    auto& P = pf[A];
    int sz = (int)P.size();

    int Msub = 1 << sz;
    vi d_of_mask(Msub, 1);
    for (int mask = 1; mask < Msub; ++mask) {
      int lsb = __builtin_ctz((unsigned)mask);
      int prev = mask ^ (1 << lsb);
      d_of_mask[mask] = d_of_mask[prev] * P[lsb];
    }

    // cnt_div[mask][w] = how many previous numbers divisible by d_of_mask[mask] with omega = w
    vvi cnt_div(Msub, vi(pfmax)), cnt_exact(Msub, vi(pfmax));
    for (int mask = 0; mask < Msub; ++mask) {
      int d = d_of_mask[mask];
      for (int w = 0; w < pfmax; ++w) cnt_div[mask][w] = freq[d][w];
      for (int w = 0; w < pfmax; ++w) cnt_exact[mask][w] = 0;
    }

    // Inclusion-Exclusion: compute cnt_exact (intersection exactly equals mask)
    vvi by_pop(sz + 1);
    for (int mask = 0; mask < Msub; ++mask) by_pop[__builtin_popcount((unsigned)mask)].push_back(mask);
    for (int pc = sz; pc >= 0; --pc) {
      for (int mask : by_pop[pc]) {
        for (int w = 0; w < pfmax; ++w) {
          int val = cnt_div[mask][w];
          int sup = ((Msub - 1) ^ mask);
          for (int s = sup; s; s = (s - 1) & sup) {
            int T = mask | s;
            val -= cnt_exact[T][w];
          }
          cnt_exact[mask][w] = val;
        }
      }
    }

    // aggregate by g = popcount(mask)
    vvi cnt_g(sz + 1, vi(pfmax));
    for (int mask = 0; mask < Msub; ++mask) {
      int g = __builtin_popcount((unsigned)mask);
      for (int w = 0; w < pfmax; ++w) cnt_g[g][w] += cnt_exact[mask][w];
    }

    // add contributions
    for (int g = 0; g <= sz; ++g) {
      for (int w = 0; w < pfmax; ++w) {
        int cnt = cnt_g[g][w];
        int base = sz + w - g;
        ll val = power(base, k);
        ll addv = mul(val, cnt);
        answer = add(answer, addv);
      }
    }

    //update frew
    total_prev_by_omega[sz] += 1;
    for (int mask = 0; mask < Msub; ++mask) {
      int d = d_of_mask[mask];
      freq[d][sz] += 1;
    }
  }

  cout << (answer % MOD + MOD) % MOD << '\n';
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
  int testCases;
  if (!(cin >> testCases)) return 0;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
  return 0;
}
