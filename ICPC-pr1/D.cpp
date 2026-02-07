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
#define read_array(a, n) \
  for (int i = 0; i < n; i++) cin >> a[i];
#define read(a, n) read_array(a, n)
#define ll long long

#define fo(i, n) for (int i = 0; i < n; i++)
#define re(i, n) for (int i = n - 1; i >= 0; i--)
#define loop(i, a, b) for (int i = a; (a >= b) ? i >= b : i <= b; (a >= b) ? i-- : i++)

#define YN(possible) cout << ((possible) ? "Y" : "N") << endl;
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
constexpr int MOD = 1000000007;
constexpr int N = 1e5 + 1;
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
  precompute_fac();
  sieve();

  int testCases = 1;
  fo(tt, testCases) {
    solve();
  }
}

vector<int> z_function(vi& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) z[i] = min(r - i, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) 
        {z[i]++;}
        if(i + z[i] > r) {
            l = i, r = i + z[i];
        }}
    return z;
}

pair<int, int> product(pair<int, int> a, pair<int, int> b, int n, int mod){
  return {(a.first * b.first % MOD + ((n - 1) * b.second % MOD) * a.second % MOD) % MOD, (((n - 2) * a.second) % MOD * b.second % MOD + b.first * a.second % MOD + b.second * a.first % MOD) % MOD};
}

int calc_shift(vector<int> &a, vector<int> &b, int m)
{
  vector<int> temp = a;
  temp.push_back(m);
  for (auto it: b)
    temp.push_back(it);
  for (auto it : b)
    temp.push_back(it);

  auto res = z_function(temp);
  int n = a.size();
  for (int i = n + 1; i <= 2 * n; i++) {
    if (res[i] >= n)
    {
    return i - n - 1;
    }
  }
    return -1;
}

void solve(){
  int n, m, k;
  cin >> n >> m >> k;
  vi array_a(n);
  vi array_b(n);
  read_array(array_a, n);
  read_array(array_b, n);
  vi a_diff_array(n);
  vi b_diff_array(n);
  for (int i = 0; i < n; i++){
    array_a[i]%=m;
    array_b[i] %= m;
  }
    for (int i = 0; i < n; i++) {
      a_diff_array[i] = (m + array_a[(i + 1) % n] - array_a[i]) % m;
      b_diff_array[i] = m - (m + array_b[(i + 1) % n] - array_b[i]) % m;
      if (b_diff_array[i] == m) b_diff_array[i] = 0;
    }
    debug(a_diff_array);
    debug(b_diff_array);
    vi res = z_function(a_diff_array);
    int shift = calc_shift(a_diff_array, b_diff_array, m);

    if (shift == -1)
    {
      cout << "0\n";
      return;
    }

    int cyclicity = n;
    for (int i = 0; i < n; i++) {
        if (i+res[i]==n){
          cyclicity = i;
          break;
        }
    }
    vector<pair<int, int>> powers_of_two;
    powers_of_two.push_back({0, 1});
    for (int i = 1; i < 32; i++) {
      powers_of_two.push_back(product(powers_of_two.back(), powers_of_two.back(), n, MOD));
    }
    pair<int, int> prod({0,0});
    for (int i = 0; i < 32; i++){
        if (k&(1LL<<i)){
            if (prod.first == prod.second && prod.first == 0){
              prod = powers_of_two[i];
            }
            else
              prod = product(prod, powers_of_two[i], n, MOD);
        }
    }
    int ans = 0;
    for (int i = 0; i < n / cyclicity; i++) {
      int x = (shift + i * cyclicity) % n;
      if (x==0){
        ans += prod.first;
      }
          else {
        ans += prod.second;
      }
      ans %= MOD;
    }
    cout << ans << "\n";
}
