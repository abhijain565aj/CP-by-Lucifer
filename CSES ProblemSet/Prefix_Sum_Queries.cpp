// Solution by Abhi Jain aka Lucifer aka abhijain565aj
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
template<class T>
using ordered_multiset =  tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order, order_of_key

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "./0_debug.cpp"
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define test(tt)
#define Error_file(x)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define MOD 1000000007
#define INF 1e18

#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pll pair<ll, ll>
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
// a.resize(unique(all(a)) - a.begin());  -> unque element me convert karta hai

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define read(a, n) for (int i = 0; i < n; ++i) cin >> a[i];
#define print_space(a, n) for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');
#define int long long
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
        return max(l, r);
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
};
signed main()
{
    fastio; 
    // Error_file("0_Error.txt");
    int n,q;
    cin >> n >> q;
    LazySegmentTree<ll> seg(n, -INF);
    vl a(n);
    read(a, n);
    vl pref_query(n);
    pref_query[0] = a[0];
    fo1(i, 1, n) pref_query[i] = pref_query[i - 1] + a[i];
    seg.build(pref_query);
    debug(pref_query);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int k, x;
            cin >> k >> x;
            k--;
            seg.update(k, n-1, x-a[k]);
            a[k] = x;
        } else {
            int l, r;
            cin >> l >> r;
            l--; r--;
            ll ans = seg.query(l, r);
            if(l>0) ans -= seg.query(l-1,l-1);
            cout << max(ans,0LL) << endl;
        }
    }
}
