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

int cnt(int num, int n) {
  string s = bitset<64>(num).to_string();
  s = s.substr(s.size() - n);
  int cnt = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    for (int j = i; j < (int)s.size(); j++) {
      int num = 0;
      for (int k = i; k <= j; k++) {
        num = num * 2 + (s[k] - '0');
      }
      if (num % 3 == 0) cnt++;
    }
  }
  return cnt;
}

void solve() {
  int n;
  cin >> n;
  // int min_cnt = INF;
  // map<int, int> mp;
  // for (int i = 0; i < (1 << n); i++) {
  //   mp[i] = cnt(i, n);
  //   min_cnt = min(min_cnt, mp[i]);
  // }
  // cout << n << " " << min_cnt << endl;
  // for (auto [key, value] : mp) {
  //   if (value == min_cnt) {
  //     string s;
  //     s = bitset<64>(key).to_string();
  //     int cnt1 = 0;
  //     for (int i = 0; i < (int)s.size(); i++) {
  //       if (s[i] == '1') cnt1++;
  //     }
  //     if (cnt1 > 3) continue;
  //     s = s.substr(s.size() - n);
  //     cout << s << endl;
  //     // return;
  //   }
  // }
  map<int, string> ans;
  ans[1] = "1";
  ans[2] = "10";
  ans[3] = "101";
  ans[4] = "1010";

  if (n <= 4) {
    cout << ans[n] << endl;
    return;
  }

  map<int, array<int, 3>> dp;
  dp[0] = {1, 1, 0};
  dp[1] = {1, 1, 1};
  dp[2] = {2, 1, 1};
  dp[3] = {2, 1, 2};
  dp[4] = {2, 1, 3};
  dp[5] = {3, 3, 1};
  n -= 5;
  auto res = dp[n % 6];
  auto xtra = (n / 6) * 2;
  debug(res, xtra);
  for (int i = 0; i < 3; i++) res[i] += xtra;
  string s = "1";
  for (int i = 0; i < res[0]; i++) s += "0";
  s += "1";
  for (int i = 0; i < res[1]; i++) s += "0";
  s += "1";
  for (int i = 0; i < res[2]; i++) s += "0";
  cout << s << endl;
}
