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
  using A = array<array<int, 3>, 3>;
  A init{};
  fo(i, 3) fo(j, 3) cin >> init[i][j];
  A fin{};
  fin[0] = {1, 2, 3};
  fin[1] = {4, 5, 6};
  fin[2] = {7, 8, 9};
  vi gx = {0, 0, 0, 0, 1, 1, 1, 2, 2, 2};
  vi gy = {0, 0, 1, 2, 0, 1, 2, 0, 1, 2};
  auto fn = [&](A a) {
    int res = 0;
    fo(i, 3) fo(j, 3) res = res + abs(gx[a[i][j]] - gx[fin[i][j]]) + abs(gy[a[i][j]] - gy[fin[i][j]]);
    return res / 2;
  };

  map<A, int> dis;
  priority_queue<pair<int, A>, vector<pair<int, A>>, greater<pair<int, A>>> q;
  q.push({fn(init), init});
  dis[init] = 0;
  while (!q.empty()) {
    auto [_, n] = q.top();
    int d = dis[n];
    if (n == fin) {
      cout << d << endl;
      return 0;
    }
    q.pop();
    fo(i, 3) fo(j, 2) {
      auto c1 = n, c2 = n;
      swap(c1[i][j], c1[i][j + 1]);
      swap(c2[j][i], c2[j + 1][i]);
      if (dis.find(c1) == dis.end()) {
        dis[c1] = d + 1;
        q.push({fn(c1) + d + 1, c1});
      }
      if (dis.find(c2) == dis.end()) {
        dis[c2] = d + 1;
        q.push({fn(c2) + d + 1, c2});
      }
    }
  }
};
