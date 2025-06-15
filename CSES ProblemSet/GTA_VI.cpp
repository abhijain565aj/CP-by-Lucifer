// Solution by Abhi Jain aka Lucifer aka abhijain565aj
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> // find_by_order, order_of_key

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
struct DSU
{
    vector<int> parent, size; // parent of each node and size of each component
    int components;           // number of connected components
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        components = n;
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = find(parent[x]); // path compression
    }
    void unite(int x, int y)
    {
        x = find(x); // find the parent of x
        y = find(y); // find the parent of y
        if (x != y)  // if x and y are not in the same component
        {
            if (size[x] < size[y])
            {
                swap(x, y);
            }
            parent[y] = x;
            size[x] += size[y];
            components--;
        }
    }
    bool same(int x, int y) // check if x and y are in the same component
    {
        return find(x) == find(y);
    }
    int getSize(int x) // get the size of the component of x
    {
        return size[find(x)];
    }
    int getComponents() // get the number of connected components
    {
        return components;
    }
};
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
        return min(l,r);
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
            return 1e15;
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
    ll n,m;
    cin>>n>>m;
    vvl edges(m);
    fo(i,m){
        int u,v,a;
        cin>>u>>v>>a;
        u--;v--;
        edges[i] = {u,v,a};
    }

    //creating MST
    DSU dsu(n);
    vvl edges_needed;
    for(auto e:edges){
        if(!dsu.same(e[0],e[1])){
            dsu.unite(e[0],e[1]);
            edges_needed.pb(e);
        }
    }
    v(v(pll)) adj(n);
    for(auto e:edges_needed){
        adj[e[0]].pb({e[1],e[2]});
        adj[e[1]].pb({e[0],e[2]});
    }

    debug(edges_needed);
    //Storing distances from root in MST
    vl parent(n,-1);
    vl distance(n);
    vl order;
    unordered_map<ll,vl> mp;
    auto dfs = [&](auto&&dfs, int i)->void{
        mp[i].pb(order.size());
        order.pb(i);
        for(auto [j,w]:adj[i]){
            if(j!=parent[i]){
                parent[j] = i;
                distance[j] = distance[i]+w;
                dfs(dfs,j);
                mp[i].pb(order.size());
                order.pb(i);
            }
        }
    };
    dfs(dfs,0);
    debug(order);
    debug(distance);

    //Finding LCA in log(n) time
    vl euler_path_array;
    for(auto x:order) euler_path_array.pb(distance[x]);
    debug(euler_path_array);
    SegmentTree st(2*n);
    st.build(euler_path_array);
    ll q;
    cin>>q;
    while(q--){
        ll n1, n2;
        cin>>n1>>n2;
        n1--;
        n2--;
        ll l = min(mp[n1][0],mp[n2][0]);
        ll r = max(mp[n1][0],mp[n2][0]);
        debug2(l,r);
        ll min_dis = st.sum(l,r);
        debug(min_dis);
        cout<<distance[n1]+distance[n2]-2*min_dis<<endl;
    }
}

int main()
{
    fastio; Error_file("0_Error.txt");
    int testCases = 1;
    cin >> testCases;
    fo(tt, testCases){
        test(tt + 1);
        solve();
    }
    test(0);
}
