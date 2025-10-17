// B87678
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
  auto ask = [&](int k, set<int> &s) {
    cout << "? " << k << " " << s.size() << " ";
    for (auto x : s) cout << x << " ";
    cout << endl;
    int ans;
    cin >> ans;
    return ans;
  };
  int n;
  cin >> n;
  set<int> s;
  fo(i, n) s.insert(i + 1);
  set<pii> res;
  fo(i, n) {
    res.insert({ask(i + 1, s), i + 1});
  }
  vi path;
  while (!res.empty()) {
    auto [val, idx] = *res.rbegin();
    res.erase(*res.rbegin());
    while (res.size() && res.rbegin()->F == val) {
      s.erase(res.rbegin()->S);
      res.erase(*res.rbegin());
    }
    path.pb(idx);
    v(pii) temp;
    while (res.size() && res.rbegin()->F == val - 1) {
      temp.pb(*res.rbegin());
      s.erase(res.rbegin()->S);
      res.erase(*res.rbegin());
    }
    if (temp.size() == 1) {
      res.insert(temp[0]);
      s.insert(temp[0].S);
      s.erase(idx);
      continue;
    }
    for (auto [v, i] : temp) {
      s.insert(i);
      if (ask(idx, s) == val) {
        res.insert({v, i});
        break;
      }
      s.erase(i);
    }
    s.erase(idx);
  }
  cout << "! " << path.size() << " ";
  for (auto x : path) cout << x << " ";
  cout << endl;
}

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1;
  cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
