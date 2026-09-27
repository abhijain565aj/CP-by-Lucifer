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

struct TrieNode {
  int child[2] = {0, 0};
  int cnt = 0;
};

struct PersistentTrie {
  vector<TrieNode> t;
  PersistentTrie(int n) {
    t.reserve(32 * n + 10);
    t.pb(TrieNode());
  }

  int add(int old, int x) {
    int root = t.size();
    t.pb(t[old]);

    int u = root, v = old;
    // two pointers, u is new, v is old
    t[u].cnt++;

    for (int b = 30; b >= 0; b--) {
      int bit = (x >> b) & 1;

      int nxt = t.size();
      auto& oldNode = t[v].child[bit];
      auto& newNode = t[u].child[bit];

      t.pb(t[oldNode]);
      newNode = nxt;

      u = nxt;
      v = oldNode;

      t[u].cnt++;
    }

    return root;
  }

  int kth(int root, int x, int k) {
    // finding kth smallest in trie with xor with x min
    int u = root;
    int ans = 0;

    for (int b = 30; b >= 0; b--) {
      int bit = (x >> b) & 1;

      int v = t[u].child[bit];
      int cnt = v ? t[v].cnt : 0;

      if (k <= cnt) {
        u = v;
      } else {
        k -= cnt;
        u = t[u].child[bit ^ 1];
        ans |= (1LL << b);
      }
    }

    return ans;
  }
};

vi transform(vi a) {
  int n = a.size();

  PersistentTrie trie(n);
  vi root(n + 1, 0);
  // root i is a[i] to a[n-1]

  for (int i = n - 1; i >= 0; i--)
    root[i] = trie.add(root[i + 1], a[i]);

  priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
  // array =  val, i, curr_k
  for (int i = 0; i < n - 1; i++) {
    int val = trie.kth(root[i + 1], a[i], 1);
    pq.push({val, i, 1});
  }

  vi ans(n);
  for (int j = 0; j < n; j++) {
    auto [val, i, k] = pq.top();
    debug(val, i, k);

    pq.pop();
    ans[j] = val;
    k++;

    if (k <= n - i - 1) {
      val = trie.kth(root[i + 1], a[i], k);
      pq.push({val, i, k});
      debug(val, i, k);
    }
  }

  return ans;
}

void solve() {
  int n, q;
  cin >> n >> q;
  vi a(n);
  read(a, n);
  sort(all(a));
  vi ans(33);
  for (int i = 0; i < 32; i++) {
    ans[i] = a.back() - a[0];
    a = transform(a);
  }
  ans[32] = 0;
  fo(i, q) {
    int x;
    cin >> x;
    cout << ans[min(x, 32ll)] << endl;
  }
}
