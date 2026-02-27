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
  // ()-1,)(,((,))-0
  // (()()()()-10,)(()()()(-6,((((((((-0,)())))))))-1
  // 500

  // now finding a single '('
  int n;
  cin >> n;
  auto ask = [&](vi ind) -> int {
    cout << "? " << ind.size() << " ";
    for (auto x : ind) cout << x + 1 << " ";
    cout << endl;
    int res;
    cin >> res;
    return res;
  };

  vi a(n);
  fo(i, n) a[i] = i;
  int lf = n - 1;

  if (ask(a))
    while (a.size() != 1) {
      vi left, right;
      int n1 = a.size();
      fo(i, n1 / 2) left.pb(a[i]);
      fo1(i, n1 / 2, n1) right.pb(a[i]);

      int res1 = ask(left);
      int res2 = ask(right);
      if (res1 == 0 && res2 == 0) {
        lf = left.back();
        break;
      } else if (res2) {
        a = right;
      } else {
        a = left;
      }
    }

  auto ask2 = [&](int i) -> string {
    vi ind = {i, lf, i + 1, i, i + 1, i, i + 1, i, i + 1};
    auto res = ask(ind);
    if (res == 10)
      return "()";
    else if (res == 6)
      return ")(";
    else if (res == 0)
      return "((";
    else
      return "))";
  };
  string ans = "";
  fo(i, n / 2) ans += ask2(2 * i);
  if (n & 1) {
    ans.pop_back();
    ans += ask2(n - 2);
  }
  cout << "! " << ans << endl;
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
