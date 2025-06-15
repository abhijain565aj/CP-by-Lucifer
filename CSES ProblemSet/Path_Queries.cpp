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

int main()
{
    fastio; 
    //tree input
    int n,q;
    cin>>n>>q;
    vl val(n);
    read(val,n);
    auto val_orig = val;
    vvl adj(n);
    fo(i,n-1){
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vl parent(n,-1),subtree(n);
    vl arr;
    auto dfs = [&](auto&&dfs, int node)->void{
        arr.pb(node);
        subtree[node] = 1;
        for(auto x:adj[node]){
            if(x==parent[node]) continue;
            parent[x] = node;
            val[x]+=val[node];
            dfs(dfs,x);
            subtree[node] += subtree[x];
        }
    };
    dfs(dfs,0);
    debug(subtree);
    debug(arr);
    vl pos(n);
    fo(i,arr.size()) pos[arr[i]]=i;
    
    vl arr_val;
    fo(i,n) arr_val.pb(val[arr[i]]);
    debug(arr_val);

    LazySegmentTree st(arr.size());
    st.build(arr_val);
    fo(i,q){
        int type;
        cin>>type;
        if(type==1){
            int s,x;
            cin>>s>>x;
            s--;
            st.update(pos[s],pos[s]+subtree[s]-1,x-val_orig[s]);
            debug(st.sum(pos[s],pos[s]))
            val_orig[s] = x;
        }
        else{
            int s;
            cin>>s;
            s--;
            cout<<st.sum(pos[s],pos[s])<<endl;
        }
    }
}
