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

struct Trienode {
  int val;
  int level;
  int counts;
  Trienode* child[2];
  Trienode(int val, int level) : val(val), level(level) {
    child[0] = child[1] = nullptr;
    counts = 0;
  }
};

struct Trie {
  Trienode* root;
  Trie() {
    root = new Trienode(0, 32);
  }
  void insert(int num) {
    root->counts++;
    Trienode* node = root;
    re1(i, 31, 0) {
      int bit = (num >> i) & 1;
      if (!node->child[bit]) {
        node->child[bit] = new Trienode(bit, i);
      }
      node = node->child[bit];
      node->counts++;
    }
  }

  int max_xor(int num, int avoid) {
    debug(num, avoid);
    int ans = 0;
    Trienode* node = root;
    // vi bits;
    bool matching = avoid != -1;
    if (root->counts == 1 && avoid != -1) return 0;
    re1(i, 31, 0) {
      int bit = (num >> i) & 1;
      int avoid_bit = (avoid >> i) & 1;
      // if (!node) return 0;
      auto parent = node;
      if (node->child[!bit]) {
        if (avoid_bit != 1 - bit) matching = false;
        node = parent->child[!bit];
        if (matching && node->counts == 1) {
          matching = false;
          node = parent->child[bit];
        } else {
          ans |= (1 << i);
        }
      } else {
        if (avoid_bit != bit) matching = false;
        node = node->child[bit];
      }
    }
    // debug(bits);
    return ans;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  v(v(pii)) adj(n);
  fo(i, n - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].pb({v, w});
    adj[v].pb({u, w});
  }

  vi dist(n, INF);
  vi hop_count(n, INF);
  dist[0] = 0;
  hop_count[0] = 0;
  auto dfs = [&](auto&& self, int u, int p) -> void {
    for (auto& [v, w] : adj[u]) {
      if (v == p) continue;
      dist[v] = dist[u] ^ w;
      hop_count[v] = hop_count[u] + 1;
      self(self, v, u);
    }
  };
  dfs(dfs, 0, -1);
  debug(dist);
  debug(hop_count);

  Trie trie_even, trie_odd;
  fo(i, n) if (hop_count[i] & 1) {
    trie_odd.insert(dist[i]);
  }
  else {
    trie_even.insert(dist[i]);
  }

  int global_xor = 0;
  while (m--) {
    char c;
    cin >> c;
    if (c == '^') {
      int x;
      cin >> x;
      global_xor ^= x;
    } else {
      int v, x;
      cin >> v >> x;
      v--;
      auto val = dist[v] ^ x;
      if (hop_count[v] % 2) val ^= global_xor;
      int v1 = trie_odd.max_xor(val ^ global_xor, (hop_count[v] & 1) ? dist[v] : -1);
      int v2 = trie_even.max_xor(val, (hop_count[v] & 1) ? -1 : dist[v]);
      debug(val, v1, v2);
      cout << max(v1, v2) << " ";
    }
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
