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
struct TrieNode {
  int b;
  TrieNode* children[2];
  int idx = -1;
  TrieNode(int bit) {
    b = bit;
    children[0] = nullptr;
    children[1] = nullptr;
  }
  ~TrieNode() {
    delete children[0];
    delete children[1];
  }
};
struct Trie {
  int SIZE = 32;
  TrieNode* root;
  Trie() {
    root = new TrieNode(-1);
  }
  void insert(int num, int idx) {
    TrieNode* node = root;
    re1(i, SIZE - 1, 0) {
      int bit = (num >> i) & 1;
      if (!node->children[bit]) {
        node->children[bit] = new TrieNode(bit);
      }
      node->idx = max(node->idx, idx);
      // debug(node->b, node->idx);
      node = node->children[bit];
    }
    node->idx = max(node->idx, idx);
    // debug(node->b, node->idx);
  }
  int solve(int a, int k) {
    TrieNode* node = root;
    int ans = -1;
    re1(i, SIZE - 1, 0) {
      int bitA = (a >> i) & 1;
      int bitK = (k >> i) & 1;
      int oppA = bitA ^ 1;
      if (bitK == 1) {
        if (node->children[oppA]) {
          node = node->children[oppA];
        } else {
          return ans;
        }
      } else if (bitK == 0) {
        if (node->children[oppA]) {
          ans = max(ans, node->children[oppA]->idx);
        }
        if (node->children[bitA]) {
          node = node->children[bitA];
        } else {
          return ans;
        }
      }
      // debug(node->b, node->idx, bitA, bitK);
    }
    ans = max(ans, node->idx);
    return ans;
  }
  ~Trie() {
    delete root;
  }
};
void solve() {
  int n, k;
  cin >> n >> k;
  vi a(n);
  read(a, n);
  if (k == 0) {
    cout << 1 << endl;
    return;
  }
  Trie trie;
  int ans = -1;
  fo(i, n) {
    int idx = trie.solve(a[i], k);
    debug(idx);
    if (idx != -1)
      if (ans == -1 || i - idx + 1 < ans) {
        ans = i - idx + 1;
      }
      
    trie.insert(a[i], i);
  }
  cout << ans << endl;
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
