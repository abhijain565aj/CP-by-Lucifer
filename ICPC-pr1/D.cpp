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
  if (local) {
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
    freopen(("input" + s + ".txt").c_str(), "r", stdin);
  }
}

/// MATH
constexpr int MOD = 998244353;
constexpr int N = 1e5 + 10;
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
void solve2();
int powers2[N];

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  file();
  precompute_fac();
  sieve();

  int testCases = 1;
  //   cin >> testCases;
  powers2[0] = 1;
  loop(i, 1, N - 1)
      powers2[i] = powers2[i - 1] * 2 % MOD;
  fo(tt, testCases) {
    solve();
    // solve2();
  }
}

void solve2()
{
  int n, q;
  cin >> n >> q;
  vi p(n);
  read(p, n);
  fo(i, n)
      p[i]--;
  while (q--)
  {
    char c;
    cin >> c;
    if (c == 's')
    {
      int l, r;
      cin >> l >> r;
      l--, r--;
      int ans = 0;
      int pos = 0;
      for (int i = r; i >= l; i--)
      {
        if (p[i] != pos){
          ans = (ans + powers2[i - l]) % MOD;
          pos = 3 - pos - p[i];
        }
      }
      cout << ans << "\n";
    } else {
      int x, y;
      cin >> x >> y;
      p[x - 1] = y - 1;
    }
  }
}

void solve() {
  int n, q;
  cin >> n >> q;
  vi p(n);
  read(p, n);
  fo(i, n)
      p[i]--;
  vi block_num(n);
  int block_sz = sqrt(n);
  fo(i, n) {
    if (i >= block_sz) {
      block_num[i] = block_num[i - block_sz] + 1;
    }
  }
  int num_blocks = block_num.back() + 1;
  vector<vvi> answer_blocks(num_blocks, vvi(3, vi(3)));  // For each incoming pos -> outgoing_pos, cost, num_changes

  auto compute_block = [&](int block) {
    int l = block * block_sz;
    int r = min(n, (block + 1) * block_sz) - 1;
    fo(i, 3) {
      answer_blocks[block][i][0] = (p[l] == i ? i : 3 - i - p[l]);
      answer_blocks[block][i][1] = (p[l] == i ? 0 : 1);
      answer_blocks[block][i][2] = (p[l] == i ? 0 : 1);
    }
    for (int i = l + 1; i <= r; i++) {
      auto prev = answer_blocks[block];
      for (int j = 0; j <= 2; j++) {
        answer_blocks[block][j][0] = prev[(p[i] == j ? j : 3 - p[i] - j)][0];
        answer_blocks[block][j][1] = ((p[i] == j ? 0 : powers2[i - l]) + (p[i] == j ? prev[j][1] : prev[3 - j - p[i]][1])) % MOD;
        answer_blocks[block][j][2] = (p[i] == j ? 0 : 1) + (p[i] == j ? prev[j][2] : prev[3 - j - p[i]][2]);
      }
    }
  };

  auto query = [&](int l, int r) -> int {
    int r_block_num = block_num[r];
    int l_block_num = block_num[l];
    cout << l << " " << r << " " << l_block_num << " " << r_block_num << "\n";

    if (l_block_num == r_block_num){
      int pos = 0;
      int ans = 0;
      for (int i = r; i >= l; i--)
      {
        if (p[i] != pos)
        {
          ans = (ans + powers2[i - l]) % MOD;
          pos = 3 - p[i] - pos;
        }
      }
      return ans;
    }

    int ans = 0;
    int pos = 0;
    while (block_num[r] == r_block_num){
      cout << r << " " << pos << " ";
      if (p[r] != pos) {
        cout << powers2[r - l] << " ";
        ans = (ans + powers2[r - l]) % MOD;
        pos = 3 - pos - p[r];
      }
      r--;
      cout << "\n";
    }
    for (int block = r_block_num - 1; block > l_block_num; block--){
      ans = (ans + answer_blocks[block][pos][1] *  powers2[block * block_sz - l] % MOD) % MOD;
      pos = answer_blocks[block][pos][0];
    }

    for (int idx = (l_block_num + 1) * block_sz - 1; idx >= l; idx--){
      cout << idx << " " << pos << " ";
      if (p[idx] != pos){
        cout << powers2[idx - l] << " ";
        ans = (ans + powers2[idx - l]) % MOD;
        pos = 3 - pos - p[idx];
      }
      cout << "\n";
      idx--;
    }

    return ans;

  };

  fo(i, num_blocks) {
    compute_block(i);
  }

  while (q--) {
    char c;
    cin >> c;
    if (c == 's') {
      int l, r;
      cin >> l >> r;
      cout << query(l - 1, r - 1) << "\n";
    } else {
      int x, y;
      cin >> x >> y;
      p[--x] = --y;
      compute_block(block_num[x]);
    }
  }
}
