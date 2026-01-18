#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Segment Tree
template <typename T>
struct SegmentTree {
  vector<T> tree;
  ll n;
  SegmentTree(ll n) {
    this->n = n;
    tree.resize(4 * n);
  }
  void build(vector<T>& a) {
    buildp(a, 1, 0, n - 1);
  }
  T sum(ll l, ll r) {
    return sump(1, 0, n - 1, l, r);
  }
  void update(ll pos, T new_val) {
    updatep(1, 0, n - 1, pos, new_val);
  }
  T operation(T l, T r) {
    return l + r;
    // change this
  }

  void buildp(vector<T>& a, ll v, ll tl, ll tr) {
    if (tl == tr) {
      tree[v] = a[tl];
    } else {
      ll tm = (tl + tr) / 2;
      buildp(a, v * 2, tl, tm);
      buildp(a, v * 2 + 1, tm + 1, tr);
      tree[v] = operation(tree[v * 2], tree[v * 2 + 1]);
    }
  }
  T sump(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) {
      return 0;
    }
    if (l == tl && r == tr) {
      return tree[v];
    }
    ll tm = (tl + tr) / 2;
    return operation(sump(v * 2, tl, tm, l, min(r, tm)), sump(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
  void updatep(ll v, ll tl, ll tr, ll pos, T new_val) {
    if (tl == tr) {
      tree[v] = new_val;
    } else {
      ll tm = (tl + tr) / 2;
      if (pos <= tm) {
        updatep(v * 2, tl, tm, pos, new_val);
      } else {
        updatep(v * 2 + 1, tm + 1, tr, pos, new_val);
      }
      tree[v] = operation(tree[v * 2], tree[v * 2 + 1]);
    }
  }
};

// Lazy Segment Tree
template<typename T>
struct LazySegmentTree
{
    vector<T> tree;
    vector<T> lazy;
    ll n;
    ll default_value;
    LazySegmentTree(ll n, ll default_value = 0)
    {
        this->n = n;
        this->default_value = default_value;
        tree.resize(4 * n);
        lazy.resize(4 * n);
    }
    void build(vector<T> &a){
        buildp(a, 1, 0, n - 1);
    }
    ll query(ll l, ll r){
        return queryp(1, 0, n - 1, l, r);
    }
    void update(ll l, ll r, T val){
        updatep(1, 0, n - 1, l, r, val);
    }
    T operation(T l, T r){
        return l + r;
    }

    void buildp(vector<T> &a, ll v, ll tl, ll tr)
    {
        if (tl == tr) 
            tree[v] = a[tl];
        else
        {
            ll tm = (tl + tr) / 2;
            buildp(a, v * 2, tl, tm);
            buildp(a, v * 2 + 1, tm + 1, tr);
            tree[v] = operation(tree[v * 2], tree[v * 2 + 1]);
        }
    }
    void push(ll v)
    {
        tree[v * 2] += lazy[v];
        lazy[v * 2] += lazy[v];
        tree[v * 2 + 1] += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }
    T queryp(ll v, ll tl, ll tr, ll l, ll r)
    {
        if (l > r) return default_value;
        if (l == tl && r == tr) return tree[v];
        ll tm = (tl + tr) / 2;
        push(v);
        return operation(
            queryp(v * 2, tl, tm, l, min(r, tm)),
            queryp(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
        );
    }
    void updatep(ll v, ll tl, ll tr, ll l, ll r, T val)
    {
        if (l > r) return;
        if (l == tl && r == tr) {
            tree[v] += val;
            lazy[v] += val;
        } else {
            ll tm = (tl + tr) / 2;
            push(v);
            updatep(v * 2, tl, tm, l, min(r, tm), val);
            updatep(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
            tree[v] = operation(tree[v * 2], tree[v * 2 + 1]);
        }
    }
    ll tm = (tl + tr) / 2;
    push(v);
    return operation(sump(v * 2, tl, tm, l, min(r, tm)), sump(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));  // merge the left and right subtree
  }
  void push(ll v)  // push the pending updates to the children
  {
    tree[v * 2] += lazy[v];
    lazy[v * 2] += lazy[v];
    tree[v * 2 + 1] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
  }
  // using push function in the updatep function
  void updatep(ll v, ll tl, ll tr, ll l, ll r, ll val) {
    if (l > r) {
      return;
    }
    if (l == tl && r == tr) {
      tree[v] += val;
      lazy[v] += val;
    } else {
      ll tm = (tl + tr) / 2;
      push(v);
      updatep(v * 2, tl, tm, l, min(r, tm), val);
      updatep(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
      tree[v] = operation(tree[v * 2], tree[v * 2 + 1]);
    }
  }
};
