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
// constexpr int INF = 1e18;

signed main() {
  fastio;
  int n, k;
  cin >> n >> k;
  vs s(n);
  for (auto& x : s) cin >> x;
  v(v(pii)) diag(2 * n - 1);
  fo(i, n) fo(j, n) diag[i - j + n - 1].pb({i, j});

  vvi A(n + 1, vi(n + 1));
  vvi Same(n + 1, vi(n + 1));
  vvi Next(n + 1, vi(n + 1));
  fo(c, k) {
    fo(i, n) fo(j, n) {
      A[i + 1][j + 1] = A[i][j + 1] + A[i + 1][j] - A[i][j] + (s[i][j] == 'A' + c);
      if (s[i][j] == 'A' + c) {
        Same[i + 1][j + 1] = A[i + 1][j + 1];
      }
      if (i < n - 1 && j < n - 1 && s[i + 1][j + 1] == 'A' + c) {
        Next[i + 1][j + 1] = A[i + 1][j + 1];
      }
    }
  }
  vi ans(n);
  for (auto& v : diag) {
    for (int lp = 0, rp = 0; lp < (int)v.size(); lp++) {
      auto [i, j] = v[lp];
      auto c = s[i][j];
      rp = max(rp, lp);
      while (true) {
        if (rp == (int)v.size() - 1) break;
        auto [i1, j1] = v[rp];
        if (i1 >= n - 1 || j1 >= n - 1) break;
        if (s[i1 + 1][j1 + 1] != c) break;
        // auto& A = cnt[c - 'A'];
        // assert(i1 + 2 <= n && j1 + 2 <= n && i < n && j < n);
        auto ct = A[i1 + 2][j1 + 2] - A[i][j1 + 2] - A[i1 + 2][j] + A[i][j];
        if (ct != (i1 + 2 - i) * (j1 + 2 - j)) break;
        rp++;
      }
      // ans[c - 'A'] += rp - lp + 1;
      ans[c - 'A'] += rp - lp + 1;
    }
  }
  fo(i, k) cout << ans[i] << "\n";
}
