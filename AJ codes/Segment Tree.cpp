#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Segment Tree
struct SegmentTree
{
    vector<ll> tree; // segment tree
    ll n;            // size of the array
    SegmentTree(ll n)
    {
        this->n = n;
        tree.resize(4 * n); // size of the segment tree is 4 times the size of the array
    }
    void build(vector<ll> &a)
    {
        buildp(a, 1, 0, n - 1);
    }
    ll sum(ll l, ll r)
    {
        return sump(1, 0, n - 1, l, r);
    }
    void update(ll pos, ll new_val)
    {
        updatep(1, 0, n - 1, pos, new_val);
    }
    ll operation(ll l, ll r)
    {
        return l + r;
        // sum, // max, // min, // gcd, // lcm, // xor, // or, // and, // product,
        // change the operation according to the query
    }

    void buildp(vector<ll> &a, ll v, ll tl, ll tr)
    {
        // a is the array, v is the index of the node, tl and tr are the range of the node

        if (tl == tr) // if the node is a leaf node
        {
            tree[v] = a[tl]; // store the value of the array in the node
        }
        else
        {
            ll tm = (tl + tr) / 2;                             // find the middle of the range
            buildp(a, v * 2, tl, tm);                          // build the left subtree
            buildp(a, v * 2 + 1, tm + 1, tr);                  // build the right subtree
            tree[v] = operation(tree[v * 2], tree[v * 2 + 1]); // merge the left and right subtree
        }
    }
    ll sump(ll v, ll tl, ll tr, ll l, ll r)
    {
        // v is the index of the node, tl and tr are the range of the node, l and r are the range of the query
        if (l > r)
        {
            return 0;
        }
        if (l == tl && r == tr)
        {
            return tree[v];
        }
        ll tm = (tl + tr) / 2;
        return operation(sump(v * 2, tl, tm, l, min(r, tm)), sump(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)); // merge the left and right subtree
    }
    void updatep(ll v, ll tl, ll tr, ll pos, ll new_val)
    {
        if (tl == tr)
        {
            tree[v] = new_val;
        }
        else
        {
            ll tm = (tl + tr) / 2;
            if (pos <= tm)
            {
                updatep(v * 2, tl, tm, pos, new_val);
            }
            else
            {
                updatep(v * 2 + 1, tm + 1, tr, pos, new_val);
            }
            tree[v] = operation(tree[v * 2], tree[v * 2 + 1]);
        }
    }
};

// Lazy Segment Tree
struct LazySegmentTree
{
    vector<ll> tree; // segment tree
    vector<ll> lazy; // lazy tree
    ll n;            // size of the array
    // lazy tree is used to store the pending updates
    LazySegmentTree(ll n)
    {
        this->n = n;
        tree.resize(4 * n); // size of the segment tree is 4 times the size of the array
        lazy.resize(4 * n); // size of the lazy tree is 4 times the size of the array
    }
    void build(vector<ll> &a)
    {
        buildp(a, 1, 0, n - 1);
    }
    ll sum(ll l, ll r)
    {
        return sump(1, 0, n - 1, l, r);
    }
    void update(ll l, ll r, ll val)
    {
        updatep(1, 0, n - 1, l, r, val);
    }
    ll operation(ll l, ll r)
    {
        return l + r;
        // sum, // max, // min, // gcd, // lcm, // xor, // or, // and, // product,
        // change the operation according to the query
    }

    void buildp(vector<ll> &a, ll v, ll tl, ll tr)
    {
        // a is the array, v is the index of the node, tl and tr are the range of the node

        if (tl == tr) // if the node is a leaf node
        {
            tree[v] = a[tl]; // store the value of the array in the node
        }
        else
        {
            ll tm = (tl + tr) / 2;                             // find the middle of the range
            buildp(a, v * 2, tl, tm);                          // build the left subtree
            buildp(a, v * 2 + 1, tm + 1, tr);                  // build the right subtree
            tree[v] = operation(tree[v * 2], tree[v * 2 + 1]); // merge the left and right subtree
        }
    }
    ll sump(ll v, ll tl, ll tr, ll l, ll r)
    {
        // v is the index of the node, tl and tr are the range of the node, l and r are the range of the query
        if (l > r)
        {
            return 0;
        }
        if (l == tl && r == tr)
        {
            return tree[v];
        }
        ll tm = (tl + tr) / 2;
        push(v);
        return operation(sump(v * 2, tl, tm, l, min(r, tm)), sump(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)); // merge the left and right subtree
    }
    void push(ll v) // push the pending updates to the children
    {
        tree[v * 2] += lazy[v];
        lazy[v * 2] += lazy[v];
        tree[v * 2 + 1] += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }
    // using push function in the updatep function
    void updatep(ll v, ll tl, ll tr, ll l, ll r, ll val)
    {
        if (l > r)
        {
            return;
        }
        if (l == tl && r == tr)
        {
            tree[v] += val;
            lazy[v] += val;
        }
        else
        {
            ll tm = (tl + tr) / 2;
            push(v);
            updatep(v * 2, tl, tm, l, min(r, tm), val);
            updatep(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
            tree[v] = operation(tree[v * 2], tree[v * 2 + 1]);
        }
    }
};
