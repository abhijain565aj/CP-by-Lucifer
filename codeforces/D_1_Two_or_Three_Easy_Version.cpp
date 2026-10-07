#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define all(x) (x).begin()(x).end()
#define pb push_back
#define YN(possible) cout << ((possible) ? "YES" : "NO") << endl;

constexpr int MOD = 998244353;
constexpr int N = 2500;
constexpr int INF = 1e18;

int mod(int x) {
  return (x % MOD + MOD) % MOD;
}

template <typename T>
class SegmentTree {
  vector<T> tree;
  int n;
  T def = 0;
  T merge(T lhs, T rhs) {
    return lhs + rhs;
  }
  SegmentTree(int n) {
    this->n = n;
    tree.resize(4 * n);
  }
  void build(vector<T>& a) {
    buildp(a, 1, 0, n - 1);
  }
  T query(int l, int r) {
    return queryp(1, 0, n - 1, l, r);
  }
  void update(int pos, T new_val) {
    updatep(1, 0, n - 1, pos, new_val);
  }
  void buildp(vector<T>& a, int v, int tl, int tr) {
    if (tl == tr) {
      tree[v] = a[tl];
    } else {
      int tm = (tl + tr) / 2;
      buildp(a, v * 2, tl, tm);
      buildp(a, v * 2 + 1, tm + 1, tr);
      tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
  }
  T queryp(int v, int tl, int tr, int l, int r) {
    if (l > r) {
      return def;
    }
    if (l == tl && r == tr) {
      return tree[v];
    }
    int rm = (tl + tr) / 2;
    return 0;
    // return merge(queryp(v * 2, tl, tm, l, min(r, tm)), queryp(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
  void updatep(int v, int tl, int tr, int pos, T new_val) {
    if (tl == tr) {
      tree[v] = new_val;
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm) {
        updatep(v * 2, tl, tm, pos, new_val);
      } else {
        updatep(v * 2 + 1, tm + 1, tr, pos, new_val);
      }
      tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
  }
};

long long fact[N + 1], ifact[N + 1], D[N + 1];

long long pos_mod(long long x) {
  return (x % MOD + MOD) % MOD;
}

long long pw(long long a, long long b) {
  long long r = 1;
  a = pos_mod(a);
  for (; b; b >>= 1, a = a * a % MOD) {
    if (b & 1) r = r * a % MOD;
  }
  return r;
}

long long inv(long long q) {
  return pw(q, MOD - 2);
}

void pre() {
  fact[0] = 1;
  D[0] = 1;

  for (int i = 1; i <= N; i++)
    fact[i] = fact[i - 1] * i % MOD;

  ifact[N] = inv(fact[N]);
  for (int i = N; i > 0; i--)
    ifact[i - 1] = ifact[i] * i % MOD;

  for (int i = 2; i <= N; i++)
    D[i] = (i - 1) * (D[i - 1] + D[i - 2]) % MOD;
}

long long nCr(int n, int r) {
  if (r < 0 || r > n) return 0;
  return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

long long nPr(int n, int r) {
  if (r < 0 || r > n) return 0;
  return fact[n] * ifact[n - r] % MOD;
}

long long catalan(int n) {
  return nCr(2 * n, n) * inv(n + 1) % MOD;
}

long long stars_bars(int n, int k) {
  return nCr(n + k - 1, k - 1);
}

void solve();
void precompute();

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  precompute();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}

struct Node {
  int cnt;
  int c2;
  int c3;
};
void precompute() {
}
void solve() {
  int N;
  cin >> N;

  vector<unordered_map<int, Node>> dp(N + 10);  // dp[i][j] =  for length i how many arrays with c2 - c3 = j
  int div6 = N / 6;
  int div2 = N / 2 - div6;
  int div3 = N / 3 - div6;
  int divN = N - div2 - div3 - div6;

  dp[1][0].cnt += div6;
  dp[1][0].c2 += div6;
  dp[1][0].c3 += div6;

  dp[1][1].cnt += div2;
  dp[1][1].c2 += div2;

  dp[1][-1].cnt += div3;
  dp[1][-1].c3 += div3;

  dp[1][0].cnt += divN;

  for (int j = 2; j <= N; j++) {
    for (auto [c, nd] : dp[j - 1]) {
      dp[j][c].cnt += mod(div6 * nd.cnt);
      dp[j][c].c2 += mod(nd.c2 * div6 + div6 * nd.cnt);
      dp[j][c].c3 += mod(nd.c3 * div6 + div6 * nd.cnt);
    }
    for (auto [c, nd] : dp[j - 1]) {
      dp[j][c + 1].cnt += mod(div2 * nd.cnt);
      dp[j][c + 1].c2 += mod(nd.c2 * div2 + div2 * nd.cnt);
      dp[j][c + 1].c3 += mod(nd.c3 * div2);
    }
    for (auto [c, nd] : dp[j - 1]) {
      dp[j][c - 1].cnt += mod(div3 * nd.cnt);
      dp[j][c - 1].c2 += mod(nd.c2 * div3);
      dp[j][c - 1].c3 += mod(nd.c3 * div3 + div3 * nd.cnt);
    }
    for (auto [c, nd] : dp[j - 1]) {
      dp[j][c].cnt += mod(divN * nd.cnt);
      dp[j][c].c2 += mod(divN * nd.c2);
      dp[j][c].c3 += mod(divN * nd.c3);
    }

    for (auto& [c, nd] : dp[j]) {
      nd.cnt = mod(nd.cnt);
      nd.c2 = mod(nd.c2);
      nd.c3 = mod(nd.c3);
    }
  }
  // for (int i = 1; i <= N; i++) {
  //   cerr << "--" << i << "\n";
  //   for (auto [c, nd] : dp[i]) {
  //     cerr << c << " " << nd.cnt << " " << nd.c2 << " " << nd.c3 << endl;
  //   }
  // }
  int ans = 0;
  for (auto [c, nd] : dp[N]) {
    if (c >= 0) {
      ans += nd.c2;
    } else {
      ans += nd.c3;
    }
    ans = mod(ans);
  }
  cout << ans << endl;
}
