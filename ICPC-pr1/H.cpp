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

#define int long long

#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define vb vector<bool>
#define pii pair<int, int>
#define v(x) vector<x>

#define fo(i, n) for (int i = 0; i < n; i++)
#define re(i, n) for (int i = n - 1; i >= 0; i--)
#define loop(i, a, b) for (int i = a; (a >= b) ? i >= b : i <= b; (a >= b) ? i-- : i++)

#define YN(possible) cout << ((possible) ? "YES" : "NO") << endl;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define pb push_back
// a.resize(unique(all(a)) - a.begin());

// DEBUG TEMPLATE
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", _print(__VA_ARGS__)
#define local true
#else
#define debug(...)
#define local false
#endif

template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p);
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream& operator<<(ostream& os, const T_container& v) {
  os << '[';
  string sep;
  for (const T& x : v) os << sep << x, sep = ", ";
  return os << ']';
}
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }

inline void _print() { cerr << endl; }
template <typename T, typename... V>
void _print(const T& t, const V&... v) {
  cerr << t;
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}

void file(string s = "") {
  if (local) {
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
    freopen(("input" + s + ".txt").c_str(), "r", stdin);
  }
}

/// MATH
constexpr int MOD = 998244353;
constexpr int N = 2e5 + 1;
constexpr int INF = 1e18;

int power(int a, int n) {
  int ans = 1;
  while (n) {
    if (n & 1) ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    n >>= 1;
  }
  return ans;
}

vi fac, fi, inv;

void precompute_fac(int n = 0) {
  if (n == 0) return;
  fac.resize(n);
  fi.resize(n);
  inv.resize(n);
  fac[0] = fac[1] = inv[1] = fi[0] = fi[1] = 1;
  loop(i, 2, n - 1) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    fi[i] = fi[i - 1] * inv[i] % MOD;
  }
}

int nCr(int n, int r) {
  if (n < 0 || r < 0 || r > n) return 0;
  return fac[n] * (fi[r] * fi[n - r] % MOD) % MOD;
}

vb prime;
void sieve(int n = 0) {
  if (n == 0) return;
  prime.resize(n, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i * i < n; i++) {
    if (!prime[i]) continue;
    for (int j = i * i; j < n; j += i) {
      prime[j] = false;
    }
  }
}

void solve();

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  file();
  precompute_fac(N);
  sieve();

  int testCases = 1;
  // cin >> testCases;
  fo(tt, testCases) {
    solve();
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  string t;
  cin >> t;
  vector<int> counts(26,0);
  for (int i = 0; i < n; i++){
    counts[s[i] - 'A']++;
  }
  vector<int> counts2(26, 0);
  for (int i = 0; i < m; i++){
    counts2[t[i] - 'A']++;
  }
  int num_permutations = fac[n];
  for (int i = 0; i < 26; i++){
    num_permutations*=fi[counts[i]];
    num_permutations %= MOD;
  }
  vector<int> suffix_sum_dp_of_excess(m+1, 0);
  suffix_sum_dp_of_excess[0] = 1;
  for (int i = 25; i >= 0; i--) {
    vector<int> dp_of_excess(m+1, 0);
    for (int t = 0; t <= counts2[i]; t++){
        if (t+counts[i]-counts2[i]>m) continue;
        if (t + counts[i] - counts2[i] < 0) dp_of_excess[t] = 0;
        else
        dp_of_excess[t] = suffix_sum_dp_of_excess[max((long long)0, t + counts[i] - counts2[i])]*nCr(counts[i], t+counts[i]-counts2[i]);
        dp_of_excess[t] %= MOD;
    }
    for (int t = m - 1; t >= 0; t--) {
      dp_of_excess[t] += dp_of_excess[t + 1];
      dp_of_excess[t] %= MOD;
    }
    suffix_sum_dp_of_excess = dp_of_excess;
    debug(char('A' + i));
    debug(suffix_sum_dp_of_excess);
  }
  int ans = num_permutations * suffix_sum_dp_of_excess[0];
  ans %= MOD;
  cout << ans;
}
