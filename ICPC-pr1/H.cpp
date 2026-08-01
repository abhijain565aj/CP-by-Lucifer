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
  if (true) {
    freopen("error.txt", "w", stderr);
    // freopen("output.txt", "w", stdout);
    // freopen(("input" + s + ".txt").c_str(), "r", stdin);
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
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);

  file();
  precompute_fac();
  sieve();

  int testCases = 1;
  cin >> testCases;
  fo(tt, testCases) {
    solve();
  }
}

pair<int, int> find_lk_rk(int lj, int rj, int k, int response, int mid){
    if (k>mid){
      for (int a = 0; a <= k - mid; a++){
        if ((lj+k-mid-a)*(rj-a)==response){
          return {lj + k - mid - a, rj - a};
        }
      }
    }
    else {
        for (int a = 0; a <= mid - k; a++){
            if ((lj-a)*(rj+mid-k-a)==response){
              return {lj-a, rj+mid-k-a};
            }
        }
    }
}

void solve() {
  int n;
  cin >> n;
  if (n <= 10) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      cout << "type " << i+1 << "\n";
      cout.flush();
      string response;
      cin >> response;
      if (response=="lily"){
        ans.push_back(1);
      }
      else {
        ans.push_back(0);
      }
    }
    vector<int> lk(n);
    lk[0] = ans[0];
    for (int i = 1; i < n; i++) {
      lk[i] = lk[i - 1] + ans[i];
    }
    vector<int> rk(n);
    rk[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--){
      rk[i] = rk[i + 1] + (1 - ans[i+1]);
    }
    for (int i = 0; i < n; i++){
        if (rk[i]==lk[i]){
          cout << "answer " << i + 1 << "\n";
          cout.flush();
          return;
        }
    }
  }
  int mid = n / 2;
  cout << "multi " << mid << "\n";
  cout.flush();
  int response;
  cin >> response;
  if (response>0){
    cout << "multi " << mid + 1 << "\n";
    cout.flush();
    int response2;
    cin >> response2;
    int lmid, rmid;
    if (response2 > response) {
      rmid = response2 - response;
      lmid = response / rmid;
    }
    else {
      lmid = response - response2;
      rmid = response / lmid;
    }
    debug(response, response2, lmid, rmid);
    if (lmid == rmid) {
      cout << "answer " << mid << "\n";
      cout.flush();
      return;
    }
    int l, r;
    if (lmid > rmid) {
      l = 0;
      r = mid-1;
    }
    else {
      l = mid;
      r = n;
    }
    while (l<r){
      int mid = (l + r) / 2;
      cout << "multi " << mid + 1 << "\n";
      cout.flush();
      int response;
      cin >> response;
      auto p = find_lk_rk(lmid, rmid, mid+1, response, n / 2);
      debug(l, r, lmid, rmid, p.first, p.second);
      int lk = p.first;
      int rk = p.second;
      if (lk==rk){
        cout << "answer " << mid + 1 << "\n";
        return;
      }
      else if (lk>rk) {
        r = mid;
      }
      else {
        l = mid + 1;
      }
    }
  }
  else {
    cout << "type " << mid << "\n";
    cout.flush();
    string response;
    cin >> response;
    if (response=="lily"){
      cout << "answer " << 0 << "\n";
    }
    else {
      cout << "answer " << n << "\n";
    }
    cout.flush();
    return;
  }
}
