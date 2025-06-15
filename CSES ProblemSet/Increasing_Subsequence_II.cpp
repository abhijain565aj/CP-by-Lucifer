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
        return (l + r)%MOD;
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
void solve()
{
    ll n;
    cin >> n;
    vl a(n);
    read(a, n);
    set<ll> st;
    for (auto x : a)
        st.insert(x);
    ll cnt = 0;
    map<ll, ll> mp;
    for(auto x:st) mp[x] = cnt++;
    SegmentTree stree(cnt);
    vl b(cnt);
    stree.build(b);
    for(auto x:a){
        ll pos = mp[x];
        stree.update(pos,stree.sum(0,pos)+1);
    }
    cout << stree.sum(0,cnt-1) << endl;
}   

int main()
{
    fastio; 
    Error_file("0_Error.txt");
    int testCases = 1;
    // cin >> testCases;
    fo(tt, testCases){
        test(tt + 1);
        solve();
    }
    test(0);
}
