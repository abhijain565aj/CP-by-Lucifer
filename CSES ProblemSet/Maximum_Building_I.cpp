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
  int testCases = 1;
  // cin >> testCases;

  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}

int max_area(vi& h) {
  stack<pii> s;
  s.push({-1, -1});
  int n = h.size();
  vi l(n), r(n);
  fo(i, n) {
    while (s.top().F >= h[i]) s.pop();
    l[i] = s.top().S;
    s.push({h[i], i});
  }
  while (!s.empty()) s.pop();
  s.push({-1, n});
  re(i, n) {
    while (s.top().F >= h[i]) s.pop();
    r[i] = s.top().S;
    s.push({h[i], i});
  }
  int ans = 0;
  fo(i, n) ans = max(ans, h[i] * (r[i] - l[i] - 1));
  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vs a(n);
  read(a, n);
  vvi up(n, vi(m));
  int ans = 0;
  fo(i, n) {
    fo(j, m) {
      if (a[i][j] == '*')
        up[i][j] = i;
      else if (i > 0)
        up[i][j] = up[i - 1][j];
      else
        up[i][j] = -1;
    }
    vi heights(m);
    fo(j, m) heights[j] = i - up[i][j];
    ans = max(ans, max_area(heights));
  }
  cout << ans << endl;
}
