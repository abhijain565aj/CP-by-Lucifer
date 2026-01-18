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
//   cin >> testCases;
  fo(tt, testCases) {
    solve();
  }
}

#define a3 array<int,3>
#define a4 array<int,4>

struct Node{
    int max_prefix;
    int max_suffix;
    int sum;
    int max_total;
    int max_individual;
};

struct SegmentTree{
    vector<Node> tree;
    int n;
    SegmentTree(int n) {
        this->n = n;
        tree.resize(4 * n, {0,0,0,0,0});
    }
    void update(int pos, int new_val) {
        updatep(1, 0, n - 1, pos, new_val);
    }

    Node query(ll l, ll r) {
        return sump(1, 0, n - 1, l, r);
    }
    Node operation(const Node &left, const Node &right)
    {
      Node ans;
      ans.sum = left.sum + right.sum;
      ans.max_prefix = max(left.max_prefix, left.sum + right.max_prefix);
      ans.max_suffix = max(right.max_suffix, right.sum + left.max_suffix);
      ans.max_total = max({left.max_total, right.max_total, left.max_suffix + right.max_prefix});
      ans.max_individual = max(left.max_individual, right.max_individual);
      return ans;
    }

    Node sump(ll v, ll tl, ll tr, ll l, ll r) {
    if (l == tl && r == tr) {
      return tree[v];
    }
    ll tm = (tl + tr) / 2;
    if (l > tm)
      return sump(v * 2 + 1, tm + 1, tr, l, r);
    if (r <= tm)
      return sump(v * 2, tl, tm, l, r);
    return operation(sump(v * 2, tl, tm, l, tm), sump(v * 2 + 1, tm + 1, tr, tm + 1, r));
  }

    void updatep(ll v, ll tl, ll tr, ll pos, int new_val) {
    if (tl == tr) {
      tree[v].sum = tree[v].max_individual = new_val;
      tree[v].max_prefix = tree[v].max_suffix = tree[v].max_total = max(0ll, new_val);
    } else {
      ll tm = (tl + tr) / 2;
      if (pos <= tm) {
        updatep(v * 2, tl, tm, pos, new_val);
      } else {
        updatep(v * 2 + 1, tm + 1, tr, pos, new_val);
      }
      tree[v] = operation(tree[v * 2], tree[v * 2 + 1]);
    }
  }

};

void solve(){
  int n, m;
  cin >> n >> m;
  vector<array<int, 3> > events;
  
  fo(i, m)
  {
    int l, r, x;
    cin >> l >> r >> x;
    events.pb({l,i,x});
    events.pb({r + 1, i, 0});
  }
  sort(all(events));
  reverse(all(events));
  int q;
  cin >> q;
  vector<a4> queries(q);
  fo(i,q)
  {
    cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    queries[i][1]--;
    queries[i][2]--;
    queries[i][3] = i;
  }
  sort(all(queries));

  SegmentTree seg(m);
  vi ans(q);

  debug(events);
  debug(queries);

  for (int i = 0; i < q; i++)
  {
    int k = queries[i][0];
    while (events.size() && events.back()[0] <= k)
    {
      seg.update(events.back()[1], events.back()[2]);
      events.pop_back();
    }
    auto node = seg.query(queries[i][1], queries[i][2]);
    ans[queries[i][3]] = (node.max_individual < 0 ? node.max_individual : node.max_total);
  }

for (auto it : ans)
    cout << it << "\n";
}
