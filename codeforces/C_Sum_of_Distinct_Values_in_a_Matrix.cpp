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
  int n, m;
  cin >> n >> m;
  int x, y;
  cin >> x >> y;
  vi a(x), b(y);
  read(a, x);
  read(b, y);
  if (n >= m) {
    swap(n, m);
    swap(x, y);
    swap(a, b);
  }
  set<int> sa(all(a)), sb(all(b));
  vi comb;
  comb.insert(comb.end(), all(a));
  comb.insert(comb.end(), all(b));
  sortall(comb);
  comb.resize(unique(all(comb)) - comb.begin());

  debug(comb);
  // if (x == n && y == m ) {
  //   cout << accumulate(all(comb), 0ll) - 1 << endl;
  //   return;
  // }
  if (x >= n && y >= m) {
    if ((int)comb.size() < n + m) {
      cout << accumulate(all(comb), 0ll) << endl;
      return;
    }
    cout << accumulate(all(comb), 0ll) - comb[0] << endl;
    return;
  }
  if (x < n) {
    debug("c1");
    int ans = 0;
    ans += accumulate(all(a), 0ll);
    debug(ans);
    vi bn;
    for (int i = y - 1; i >= 0; i--) {
      if (sa.find(b[i]) == sa.end()) {
        bn.pb(b[i]);
      }
    }
    debug(bn);
    if (bn.size())
      ans += accumulate(bn.begin(), bn.begin() + min(m, (int)bn.size()), 0ll);
    cout << ans << endl;
  } else if (y < m) {
    debug("c2");
    int ans = 0;
    ans += accumulate(all(b), 0ll);
    vi an;
    for (int i = x - 1; i >= 0; i--) {
      if (sb.find(a[i]) == sb.end()) {
        an.pb(a[i]);
      }
    }
    if (an.size())
      ans += accumulate(an.begin(), an.begin() + min(n, (int)an.size()), 0ll);
    cout << ans << endl;
  }
}
