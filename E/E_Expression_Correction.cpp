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
  string s;
  cin >> s;
  auto si = [&](string s) -> int {
    if (s.size() == 0) return INF;
    if (s[0] == '0' && s.size() > 1) return INF;
    if (s.size() > 10) return INF;
    int val = 0;
    for (char c : s) {
      if (c < '0' || c > '9') return INF;
      val = val * 10 + (c - '0');
    }
    return val;
  };
  auto value = [&](string s) -> int {
    int ans = 0;
    string num = "";
    bool last_plus = true;
    for (char c : s) {
      if (c == '+' || c == '-') {
        int val = si(num);
        if (val == INF) return INF;
        ans += last_plus ? val : -val;
        last_plus = (c == '+');
        num = "";
      } else {
        num += c;
      }
    }
    int val = si(num);
    if (val == INF) return INF;
    ans += last_plus ? val : -val;
    return ans;
  };
  auto solve = [&](string s) -> bool {
    string lhs = "", rhs = "";
    int eq = s.find('=');
    // debug(s);
    lhs = s.substr(0, eq);
    rhs = s.substr(eq + 1, s.size() - eq - 1);
    // debug(lhs, rhs);
    auto lv = value(lhs);
    auto rv = value(rhs);
    if (lv == INF || rv == INF) return false;
    return lv == rv;
  };
  if (solve(s)) {
    cout << "Correct\n";
    return;
  }
  fo(i, s.size()) {
    if (s[i] == '+' || s[i] == '-' || s[i] == '=') continue;
    auto cp = s;
    cp.erase(cp.begin() + i);
    fo(j, cp.size()) {
      auto cp1 = cp;
      cp1.insert(cp1.begin() + j, s[i]);
      if (solve(cp1)) {
        cout << cp1 << "\n";
        return;
      }
    }
  }
  cout << "Impossible\n";
}

signed main() {
  fastio;
  Error_file("0_Error.txt");
  int testCases = 1;
  // cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
