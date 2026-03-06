#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll INF = 1e18;

struct Line {
  ll m, c;
  ll eval(ll x) { return m * x + c; }
};
struct node {
  // Might want inf to be 2e18 or 4e18
  // This template is for min queries. For max queries insert (-m, -c) lines while keeping the x values (the ones which are queried) same
  Line line;
  node* left = nullptr;
  node* right = nullptr;
  node(Line line) : line(line) {}
  void add_segment(Line nw, int l, int r, int L, int R) {
    if (l > r || r < L || l > R) return;
    int m = (l + 1 == r ? l : (l + r) / 2);
    if (l >= L and r <= R) {
      bool lef = nw.eval(l) < line.eval(l);
      bool mid = nw.eval(m) < line.eval(m);
      if (mid) swap(line, nw);
      if (l == r) return;
      if (lef != mid) {
        if (left == nullptr)
          left = new node(nw);
        else
          left->add_segment(nw, l, m, L, R);
      } else {
        if (right == nullptr)
          right = new node(nw);
        else
          right->add_segment(nw, m + 1, r, L, R);
      }
      return;
    }
    if (max(l, L) <= min(m, R)) {
      if (left == nullptr) left = new node({0ll, INF});
      left->add_segment(nw, l, m, L, R);
    }
    if (max(m + 1, L) <= min(r, R)) {
      if (right == nullptr) right = new node({0ll, INF});
      right->add_segment(nw, m + 1, r, L, R);
    }
  }
  ll query_segment(ll x, int l, int r, int L, int R) {
    if (l > r || r < L || l > R) return INF;
    int m = (l + 1 == r ? l : (l + r) / 2);
    if (l >= L and r <= R) {
      ll ans = line.eval(x);
      if (l < r) {
        if (x <= m && left != nullptr) ans = min(ans, left->query_segment(x, l, m, L, R));
        if (x > m && right != nullptr) ans = min(ans, right->query_segment(x, m + 1, r, L, R));
      }
      return ans;
    }
    ll ans = INF;
    if (max(l, L) <= min(m, R)) {
      if (left == nullptr) left = new node({0ll, INF});
      ans = min(ans, left->query_segment(x, l, m, L, R));
    }
    if (max(m + 1, L) <= min(r, R)) {
      if (right == nullptr) right = new node({0ll, INF});
      ans = min(ans, right->query_segment(x, m + 1, r, L, R));
    }
    return ans;
  }
};

struct LiChaoTree {
  int L, R;
  node* root;
  LiChaoTree() : L(numeric_limits<int>::min() / 2), R(numeric_limits<int>::max() / 2), root(nullptr) {}
  LiChaoTree(int L, int R) : L(L), R(R) {
    root = new node({0, INF});
  }
  void add_line(Line line) {
    root->add_segment(line, L, R, L, R);
  }
  void add_segment(Line line, int l, int r) {
    root->add_segment(line, L, R, l, r);
  }
  ll query(ll x) {
    return root->query_segment(x, L, R, L, R);
  }
  ll query_segment(ll x, int l, int r) {
    return root->query_segment(x, l, r, L, R);
  }
};