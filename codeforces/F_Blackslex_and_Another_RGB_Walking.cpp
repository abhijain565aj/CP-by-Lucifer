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

void solve1() {
  int n, m;
  cin >> n >> m;
  vvi adj(n);
  fo(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  queue<int> pq;
  pq.push(0);
  vi dist(n, INF), par(n, -1);
  vi col(n, -1);
  col[0] = 0;
  dist[0] = 0;
  debug(adj);
  while (!pq.empty()) {
    int u = pq.front();
    pq.pop();
    for (int v : adj[u]) {
      if (v != par[u] && col[v] == -1)
        col[v] = (1 + col[u]) % 3;
      if (dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1;
        par[v] = u;
        pq.push(v);
      }
    }
  }
  map<int, char> mp = {{0, 'r'}, {1, 'g'}, {2, 'b'}};
  string s = "";
  fo(i, n) s += mp[col[i]];
  cout << s << endl;
}

void solve2() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }
    map<char, int> mp;
    mp['r'] = mp['g'] = mp['b'] = -1;
    fo(i, n) {
      mp[s[i]] = i + 1;
    }
    if (mp['r'] * mp['g'] * mp['b'] > 0) {
      cout << 1 << endl;
      continue;
    }
    if (mp['r'] == -1) {
      cout << mp['b'] << endl;
    } else if (mp['b'] == -1) {
      cout << mp['g'] << endl;
    } else if (mp['g'] == -1) {
      cout << mp['r'] << endl;
    }
  }
}
signed main() {
  fastio;
  string s;
  cin >> s;
  //   Error_file("0_Error.txt");
  int testCases = 1000;
  cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    if (s == "first")
      solve1();
    else
      solve2();
  }
}
