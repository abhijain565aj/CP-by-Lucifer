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
  int n;
  cin >> n;
  string s;
  string t;
  cin >> s >> t;
  v(pii) sol;
  auto flip = [&](int j) {
    if (s[j] == '0')
      s[j] = '1';
    else
      s[j] = '0';
  };
  auto flip2 = [&](int l, int r) {
    for (int i = l; i <= r; i++) {
      flip(i);
    }
    sol.pb({l + 1, r + 1});
  };
  fo(i, n) {
    if (s[i] == t[i]) continue;
    if (i + 1 < n && s[i + 1] == s[i]) {
      flip2(i, i + 1);
    } else if (i + 2 < n && s[i] == s[i + 2]) {
      flip2(i, i + 2);
    } else if (i + 2 < n) {
      flip2(i + 1, i + 2);
      flip2(i, i + 2);
    }
  }
  debug(s, t);

  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == t[i]) continue;
    if (i - 1 >= 0 && s[i - 1] == s[i]) {
      flip2(i - 1, i);
    } else if (i - 2 >= 0 && s[i] == s[i - 2]) {
      flip2(i - 2, i);
    } else if (i - 2 >= 0) {
      flip2(i - 2, i - 1);
      flip2(i - 2, i);
    }
  }
  debug(s, t);
  if (s != t) {
    cout << -1 << endl;
    return;
  }
  cout << sol.size() << endl;
  for (auto p : sol) {
    cout << p.F << " " << p.S << endl;
  }
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
