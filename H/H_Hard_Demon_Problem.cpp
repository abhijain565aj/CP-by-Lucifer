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
#include "./0_debug.cpp"
#else
#define debug(...)
#define Test(tt)
#define Error_file(x)
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

#define fo(i, n) for (decltype(n) i = 0; i < n; i++)
#define re(i, n) for (decltype(n) i = n - 1; i >= 0; i--)
#define fo1(i, a, b) for (decltype(b) i = a; i < b; i++)
#define re1(i, a, b) for (decltype(a) i = a; i >= b; i--)

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
#define print_space(a, n) \
  for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');

constexpr int MOD = 1000000007;
constexpr int N = 1e5 + 1;
constexpr int INF = 1e18;

void solve() {
  int n, q;
  cin >> n >> q;
  vvi a(n, vi(n));
  fo(i, n) fo(j, n) cin >> a[i][j];
  auto rec = a;
  auto irec = a;
  auto jrec = a;
  fo(i, n) fo(j, n) {
    rec[i][j] += (i > 0) ? rec[i - 1][j] : 0;
    rec[i][j] += (j > 0) ? rec[i][j - 1] : 0;
    rec[i][j] -= (i > 0 && j > 0) ? rec[i - 1][j - 1] : 0;

    irec[i][j] *= (i + 1);
    irec[i][j] += (i > 0) ? irec[i - 1][j] : 0;
    irec[i][j] += (j > 0) ? irec[i][j - 1] : 0;
    irec[i][j] -= (i > 0 && j > 0) ? irec[i - 1][j - 1] : 0;

    jrec[i][j] *= (j + 1);
    jrec[i][j] += (i > 0) ? jrec[i - 1][j] : 0;
    jrec[i][j] += (j > 0) ? jrec[i][j - 1] : 0;
    jrec[i][j] -= (i > 0 && j > 0) ? jrec[i - 1][j - 1] : 0;
  }
  debug(rec, irec, jrec);
  auto query = [&](int x1, int y1, int x2, int y2, vvi& v) -> int {
    int sum = v[x2][y2];
    if (x1) sum -= v[x1 - 1][y2];
    if (y1) sum -= v[x2][y1 - 1];
    if (x1 && y1) sum += v[x1 - 1][y1 - 1];
    return sum;
  };
  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    int normal = query(x1, y1, x2, y2, rec);
    int isum = query(x1, y1, x2, y2, irec);
    int jsum = query(x1, y1, x2, y2, jrec);
    debug(normal, isum, jsum);
    isum -= normal * (x1 + 1);
    jsum -= normal * (y1);
    debug(isum, jsum);
    cout << jsum + isum * (y2 - y1 + 1) << " ";
  }
  cout << endl;
}

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1000;
  cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
