// Solution by Abhi Jain aka Lucifer aka abhijain565aj
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

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
  // cin >> testCases;

  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}

void precompute() {
}

struct Treap {
 public:
  struct Node {
    Node *left, *right;
    char key;
    int prior;
    int size;
    Node() : left(nullptr), right(nullptr), prior(rand()), size(0) {};
    Node(char key) : left(nullptr), right(nullptr), key(key), prior(rand()), size(1) {}
  };
  Node* root;
  Treap() : root(nullptr) {}
  void insert(char key) {
    if (root == nullptr) {
      root = new Node(key);
      return;
    } else {
      Node* n = new Node(key);
      merge(root, root, n);
    }
  }
  pair<Node*, Node*> split(Node* nd, int size) {
    Node *l, *r;
    split(nd, size, l, r);
    return {l, r};
  }
  void merge(Node* l, Node* r) {
    merge(root, l, r);
  }
  Node* getRoot() {
    return root;
  }
  string to_string(Node* t) {
    if (!t) return "";
    return to_string(t->left) + t->key + to_string(t->right);
  }

 private:
  int getSize(Node* t) {
    return t ? t->size : 0;
  }
  void split(Node* t, int size, Node*& l, Node*& r) {
    if (size == 0) {
      l = nullptr;
      r = t;
      return;
    }
    if (getSize(t->left) < size) {
      split(t->right, size - getSize(t->left) - 1, l, r);
      t->right = l;
      l = t;
    } else if (getSize(t->left) > size) {
      split(t->left, size, l, r);
      t->left = r;
      r = t;
    } else {
      l = t->left;
      t->left = nullptr;
      r = t;
    }
    t->size = 1 + getSize(t->left) + getSize(t->right);
  }
  void merge(Node*& t, Node* l, Node* r) {
    if (!l || !r) {
      t = l ? l : r;
      return;
    }
    if (l->prior > r->prior) {
      l->size += r->size;
      merge(l->right, l->right, r);
      t = l;
    } else {
      r->size += l->size;
      merge(r->left, l, r->left);
      t = r;
    }
    t->size = 1 + getSize(t->left) + getSize(t->right);
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  Treap treap;
  for (char c : s) treap.insert(c);
  while (m--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    auto [a, b] = treap.split(treap.getRoot(), l);
    auto [c, d] = treap.split(b, r - l + 1);
    treap.merge(a, d);
    treap.merge(treap.getRoot(), c);
  }
  cout << treap.to_string(treap.getRoot()) << endl;
}
