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
constexpr int N = 1001;
constexpr int INF = 1e18;

void solve();
void precompute();

using B = bitset<N + 10>;
// Modular Arithmetic
ll mod(ll a, ll m = MOD) { return (a % m + m) % m; }
ll add(ll a, ll b, ll m = MOD) { return mod(a + b, m); }
ll sub(ll a, ll b, ll m = MOD) { return mod(a - b, m); }
ll mul(ll a, ll b, ll m = MOD) { return mod(a * b, m); }
ll power(ll a, ll b, ll m = MOD) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res = mul(res, a, m);
    a = mul(a, a, m);
    b >>= 1;
  }
  return res;
}
ll inv(ll a, ll m = MOD) { return power(a, m - 2, m); }
ll divide(ll a, ll b, ll m = MOD) { return mul(a, inv(b, m), m); }

signed main() {
  fastio;
  vvi p(N * 5);
  map<int, int> mp;
  int ind = 0;
  for (int i = 2; i < N * 5; i++) {
    if (p[i].size()) continue;
    mp[i] = ind++;
    for (int j = i; j < N * 5; j += i) p[j].pb(i);
  }
  int n;
  cin >> n;
  vi a(n);
  read(a, n);
  vector<B> b(n);
  fo(i, n) {
    auto& v = p[a[i]];
    for (auto j : v) {
      int cnt = 0;
      while (a[i] % j == 0) {
        a[i] /= j;
        cnt++;
      }
      if (cnt % 2) b[i].set(mp[j]);
    }
  }
  int np = mp.size();
  vector<B> basis(N);
  int sz = 0;
  auto add = [&](B b) -> void {
    for (int i = np; i >= 0; i--) {
      if (!b[i]) continue;
      if (!basis[i].any()) {
        basis[i] = b;
        sz++;
        return;
      }
      b ^= basis[i];
    }
  };
  for (auto& x : b) add(x);
  cout << power(2, n - sz) << endl;
}
