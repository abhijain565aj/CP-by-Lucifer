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
constexpr int N = 1e6 + 10;
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
vb prime(N, true);
vector<vi> pf(N);  // stores pf with odd powers
void precompute() {
  prime[0] = prime[1] = false;
  for (int i = 0; i < N; i++) {
    if (prime[i]) {
      for (int j = i * i; j < N; j += i) {
        prime[j] = false;
      }
    }
  }
  for (int i = 2; i < N; i++) {
    if (prime[i]) {
      for (int j = i; j < N; j += i) {
        int cnt = 0;
        int x = j;
        while (x % i == 0) {
          x /= i;
          cnt++;
        }
        if (cnt % 2) pf[j].pb(i);
      }
    }
  }
}

void solve() {
  int n;
  cin >> n;
  vi a(n);
  read(a, n);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int val = 1;
    for (auto x : pf[a[i]]) {
      val *= x;
    }
    mp[val]++;
  }
  set<int> arr;
  int ans = 0;
  for (auto x : a) {
    for (auto y : pf[x]) {
      if (arr.find(y) != arr.end()) {
        arr.erase(y);
      } else {
        arr.insert(y);
      }
    }
    if (arr.size() < 10) {
      int temp = 1;
      for (auto y : arr) {
        temp *= y;
      }
      ans += mp[temp];
    }
  }
  cout << ans << endl;
}
