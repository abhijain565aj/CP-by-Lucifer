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
    vector<pll> tree;
    ll n;
    SegmentTree(ll n){ this->n = n, tree.resize(4 * n); }
    void build(vector<ll> &a){ buildp(a, 1, 0, n - 1); }
    pll sum(ll l, ll r){
        return sump(1, 0, n - 1, l, r);
    }
    pll operation(pll l, pll r){
        return min(l,r);
    }
    void buildp(vector<ll> &a, ll v, ll tl, ll tr)
    {
        if (tl == tr)
            tree[v] = {a[tl],tl};
        else
        {
            ll tm = (tl + tr) / 2;
            buildp(a, v * 2, tl, tm);                          
            buildp(a, v * 2 + 1, tm + 1, tr);                  
            tree[v] = operation(tree[v * 2], tree[v * 2 + 1]); 
        }
    }
    pll sump(ll v, ll tl, ll tr, ll l, ll r)
    {
        if (l > r)
            return {1e9,-1};
        if (l == tl && r == tr)
            return tree[v];
        ll tm = (tl + tr) / 2;
        return operation(
            sump(v * 2, tl, tm, l, min(r, tm)),
            sump(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
        ); 
    }
};

int main()
{
    fastio; 
    int n,m;
    cin>>n>>m;
    vvl adj(n);
    fo(i,n-1){
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    v(pll) paths(m);
    fo(i,m) cin>>paths[i].F>>paths[i].S, paths[i].F--, paths[i].S--;
    vl arr;
    vl parent(n,-1),distance(n);
    auto dfs = [&](auto&&dfs, int node)->void{
        arr.pb(node);
        for(auto x:adj[node]){
            if(x==parent[node]) continue;
            parent[x] = node;
            distance[x] = distance[node]+1;
            dfs(dfs,x);
            arr.pb(node);
        }
    };
    dfs(dfs,0);
    
    vi pos(n);
    fo(i,arr.size()) pos[arr[i]]=i;

    vl arr_ranks(arr.size());
    fo(i,arr.size()) arr_ranks[i] = distance[arr[i]];

    SegmentTree st(arr.size());
    st.build(arr_ranks);
    debug(arr);
    debug(pos);
    auto fn = [&](int i, int j)->int{
        if(pos[i]>pos[j]) swap(i,j);
        return arr[st.sum(pos[i],pos[j]).S];
    };
    
    vl val(n);
    for(auto [x,y]:paths){
        auto lca = fn(x,y);
        debug3(x,y,lca);
        val[x]+=1,val[y]+=1;
        val[lca]-=1;
        if(parent[lca]!=-1) val[parent[lca]] -=1;
    }

    vl dp(n);
    auto dfs2 = [&](auto&&dfs2, int node)->int{
        dp[node] = val[node];
        for(auto x:adj[node]){
            if(x==parent[node]) continue;
            dp[node] += dfs2(dfs2,x);
        }
        return dp[node];
    };
    dfs2(dfs2,0);
    print_space(dp,n);
}
