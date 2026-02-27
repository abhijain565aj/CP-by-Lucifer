// Solution by Abhi Jain aka Lucifer aka abhijain565aj
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
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
#define int ll
// disjoint set union
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
int32_t main()
{
    fastio; 
    Error_file("0_Error.txt");
    ll n, m;
    cin>>n>>m;
    vector<map<int,int>> e(n);
    int extra = (n*(n-1))/2 - m;
    vvi edges;
    int w_xor = 0;
    fo(i,m){
        ll u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        w_xor ^= w;
        e[u][v] = e[v][u] = w;
        edges.pb({w,u,v});
    }
    // assign one edge to be w_xor and all others 0
    // if two vertices are not connected then they are in the same component
    DSU dsu(n);
    set<int> s;
    fo(i,n) s.insert(i);

    auto DFS = [&](auto&&DFS, int u){
        s.erase(u);
        for (int v = 0;;) {
            auto it = s.lower_bound(v);
            if (it == s.end()) {
                return;
            }
            v = *it;
            if (e[u].count(v)==0) {
                dsu.unite(u, v);
                extra--;
                DFS(DFS,v);
            }
            v++;
        }
    };
    fo(i,n) {
        if (s.count(i)) {
            DFS(DFS,i);
        }
    }
    debug(dsu.getComponents())
    if(extra>0) w_xor = 0;
    sortall(edges);
    DSU dsu2(n);
    ll ans = 0;
    for(auto e:edges){
        if(!dsu.same(e[1],e[2])){
            dsu.unite(e[1],e[2]);
            dsu2.unite(e[1],e[2]);
            ans+=e[0];
        }
        else if(!dsu2.same(e[1],e[2])){
            dsu2.unite(e[1],e[2]);
            w_xor = min(w_xor,e[0]);
        }
    }
    cout<<ans+w_xor<<endl;
}
