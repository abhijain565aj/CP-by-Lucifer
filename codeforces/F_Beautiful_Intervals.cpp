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

pii intersect(pii a, pii b) {
  int l = max(a.F, b.F);
  int r = min(a.S, b.S);
  if (l > r) return {-1, -1};
  return {l, r};
}

void solve() {
  int n, m;
  cin >> n >> m;
  v(pii) a(m);
  fo(i, m) {
    cin >> a[i].F >> a[i].S;
    a[i].F--;
    a[i].S--;
  }
  pii curr = {0, n - 1};
  fo(i, m) {
    curr = intersect(curr, a[i]);
  }
  // if interseection exists => I can create Mex(B) = 0
  if (curr.F != -1) {
    vi ans(n);
    fo(i, n) ans[i] = i;
    swap(ans[0], ans[curr.F]);
    print_space(ans, n);
    debug(1);
    return;
  }
  // if any cell where not covered by any interval => 0 there => Mex(B) = 1
  vi cover(n, 0);
  fo(i, m) fo1(j, a[i].F, a[i].S + 1) cover[j] += 1;
  fo(i, n) {
    if (cover[i] == 0) {
      vi ans(n);
      fo(j, n) ans[j] = j;
      swap(ans[0], ans[i]);
      print_space(ans, n);
      debug(2);
      return;
    }
  }

  vi lboundary(n);
  vi rboundary(n);
  fo(i, m) lboundary[a[i].F]++, rboundary[a[i].S]++;

  vi ans(n);
  fo(i, n) ans[i] = i;
  fo(i, n - 1) if (rboundary[i] == 0) {
    debug(i);
    if (i != 0) {
      swap(ans[i + 1], ans[1]);
      swap(ans[i], ans[0]);
    }
    print_space(ans, n);
    debug(3);
    return;
  }
  else if (lboundary[i + 1] == 0) {
    if (i != 0) {
      swap(ans[i + 1], ans[0]);
      swap(ans[i], ans[1]);
    } else {
      swap(ans[1], ans[0]);
    }
    print_space(ans, n);
    debug(4);
    return;
  }
  // If not, B atleast has 0
  // I try that any array has both 0,1 or none
  int lp = 0, rp = n - 1;
  fo(i, n) {
    if (i & 1)
      ans[lp++] = i;
    else
      ans[rp--] = i;
  }
  print_space(ans, n);
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
