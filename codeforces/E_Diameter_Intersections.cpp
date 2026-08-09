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
constexpr int N = 1e5 + 1;
constexpr int INF = 1e18;

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd>& a, bool invert) {
  int n = a.size();

  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    while (j & bit) {
      j ^= bit;
      bit >>= 1;
    }
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }

  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));

    for (int i = 0; i < n; i += len) {
      cd w(1);
      for (int j = 0; j < len / 2; j++) {
        cd u = a[i + j];
        cd v = a[i + j + len / 2] * w;

        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;

        w *= wlen;
      }
    }
  }

  if (invert) {
    for (cd& x : a)
      x /= n;
  }
}

vector<int> possible_sums(const vector<int>& left,
                          const vector<int>& right,
                          int mx) {
  vector<cd> A(mx + 1), B(mx + 1);

  for (int x : left) A[x] = 1;
  for (int x : right) B[x] = 1;

  int n = 1;
  while (n <= 2 * mx) n <<= 1;

  A.resize(n);
  B.resize(n);

  fft(A, false);
  fft(B, false);

  for (int i = 0; i < n; i++)
    A[i] *= B[i];

  fft(A, true);

  vector<int> ans;
  for (int s = 0; s <= 2 * mx; s++) {
    if ((int)round(A[s].real()) > 0)
      ans.push_back(s);
  }
  return ans;
}

void solve();
void precompute();

signed main() {
  fastio;
  file();
  precompute();

  int testCases = 1;
  cin >> testCases;

  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}

void precompute() {
}

void solve() {
  int n;
  cin >> n;
  vvi adj(n);
  fo(i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  if (n == 2) {
    cout << 1 << " " << 1 << endl;
    return;
  }
  // find 1st diameter
  int start = 0;
  {
    vi dis(n, -1);
    auto dfs = [&](auto self, int u, int p) -> void {
      for (int v : adj[u]) {
        if (v == p) continue;
        dis[v] = dis[u] + 1;
        self(self, v, u);
      }
    };
    dis[start] = 0;
    dfs(dfs, start, -1);
    start = max_element(all(dis)) - dis.begin();
  }
  vi lp(n), lps;
  int dim_length = 0;
  {
    vi dis(n, -1);
    auto dfs = [&](auto self, int u, int p) -> void {
      for (int v : adj[u]) {
        if (v == p) continue;
        dis[v] = dis[u] + 1;
        self(self, v, u);
      }
    };
    dis[start] = 0;
    dfs(dfs, start, -1);
    dim_length = *max_element(all(dis));
    start = max_element(all(dis)) - dis.begin();
    fo(i, n) if (dis[i] == dim_length) lp[i] = 1, lps.pb(i);
  }
  vi rp(n), rps;
  {
    vi dis(n, -1);
    auto dfs = [&](auto self, int u, int p) -> void {
      for (int v : adj[u]) {
        if (v == p) continue;
        dis[v] = dis[u] + 1;
        self(self, v, u);
      }
    };
    dis[start] = 0;
    dfs(dfs, start, -1);
    fo(i, n) if (dis[i] == dim_length) rp[i] = 1, rps.pb(i);
  }
  // find center edge of diameter
  int cu = -1, cv = -1;
  {
    // find path from lps[0] to rps[0]
    vi path;
    auto dfs = [&](auto self, int u, int p) -> bool {
      path.pb(u);
      if (u == rps[0]) return true;
      for (int v : adj[u]) {
        if (v == p) continue;
        if (self(self, v, u)) return true;
      }
      path.pop_back();
      return false;
    };
    dfs(dfs, lps[0], -1);
    // dim_length always odd
    cu = path[dim_length / 2];
    cv = path[dim_length / 2 + 1];
  }

  // from cu dfs to find all distances to nodes which have in there subtree a node from lps
  // from cv dfs to find all distances to nodes which have in there subtree a node from rps

  debug(lps, rps);
  debug(cu, cv);
  vi disl(n, -1), disr(n, -1);
  {
    auto dfs = [&](auto self, int u, int p) -> bool {
      bool has_lps = lp[u];
      int cnt = 0;
      for (int v : adj[u]) {
        if (v == p) continue;
        disl[v] = disl[u] + 1;
        if (self(self, v, u)) cnt++;
      }
      if (!has_lps && cnt <= 1) disl[u] = -1;
      return has_lps || cnt > 0;
    };
    disl[cu] = 0;
    dfs(dfs, cu, cv);
  }
  {
    auto dfs = [&](auto self, int u, int p) -> bool {
      bool has_rps = rp[u];
      int cnt = 0;
      for (int v : adj[u]) {
        if (v == p) continue;
        disr[v] = disr[u] + 1;
        if (self(self, v, u)) cnt++;
      }
      if (!has_rps && cnt <= 1) disr[u] = -1;
      return has_rps || cnt > 0;
    };
    disr[cv] = 0;
    dfs(dfs, cv, cu);
  }

  vi left, right;
  fo(i, n) if (disl[i] != -1) left.pb(disl[i] + 1);
  fo(i, n) if (disr[i] != -1) right.pb(disr[i]);
  sortall(left);
  sortall(right);
  left.resize(unique(all(left)) - left.begin());
  right.resize(unique(all(right)) - right.begin());

  debug(left);
  debug(right);

  int mx = dim_length;

  vi ans = possible_sums(left, right, mx);
  sortall(ans);
  cout << ans.size() << " ";
  for (auto x : ans) cout << x << " ";
  cout << endl;
}
