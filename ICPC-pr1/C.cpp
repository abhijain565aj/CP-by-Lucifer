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
  return os << ']' << "\n";
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

  int testCases = 333;
  //   cin >> testCases;
  fo(tt, testCases) {
    solve();
  }
}

void solve() {
  int n;
  cin >> n;
  // n = 5;
  if (n > 3) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 2 && j == 2)
          cout << 1;
        else
          cout << 0;
      }
      cout << endl;
    }
    string s;
    cin >> s;
    if (s == "CORRECT") {
      return;
    }
    vs ans(n - 2);
    for (auto& x : ans)
      cin >> x;
    vvi holes(3, vi(3));
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        holes[i][j] = ans[2 - i][2 - j] - '0';
    // vvi holes(3, vi(3));
    // holes[0] = {1, 0, 1};
    // holes[1] = {0, 0, 1};
    // holes[2] = {1, 1, 1};
    // fo(i, 3) fo(j, 3) holes[i][j] = rand() % 2;
    vvi grid(n, vi(n, 1));
    vvi fixed(n, vi(n, 0));
    fo(i, n - 2) fo(j, n - 2) {
      int sum = 0;
      fo(k1, 3) fo(k2, 3) if (holes[k1][k2]) {
        sum += grid[i + k1][j + k2];
      }
      sum = sum % 2;
      fo(k1, 3) fo(k2, 3) if (holes[k1][k2]) {
        if (sum == 0 && fixed[i + k1][j + k2] == 0) {
          grid[i + k1][j + k2] ^= 1;
          sum = (sum + 1) % 2;
        }
        fixed[i + k1][j + k2] = 1;
      }
    }
    // debug(grid);
    // fo(i, n - 2) fo(j, n - 2) {
    //   int sum = 0;
    //   re(k1, 3) re(k2, 3) if (holes[k1][k2]) {
    //     sum += grid[i + k1][j + k2];
    //   }
    //   if (sum % 2 == 0) {
    //     debug(i, j);
    //     debug(holes);
    //     exit(0);
    //   }
    // }
    fo(i, n) {
      fo(j, n) cout << grid[i][j];
      cout << endl;
    }
    cin >> s;
  } else {
    while (true) {
      vvi grid(3, vi(3));
      fo(i, 3) {
        fo(j, 3) cout << rand() % 2;
        cout << endl;
      }
      string s;
      cin >> s;
      if (s == "CORRECT") {
        return;
      } else {
        int x;
        cin >> x;
      }
    }
  }
}
