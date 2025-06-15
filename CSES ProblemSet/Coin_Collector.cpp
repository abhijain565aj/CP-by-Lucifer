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

int main()
{
    fastio; 
    // Error_file("0_Error.txt");
    ll n, m;
    cin>>n>>m;
    vl k(n);
    read(k,n);
    vvi adj(n), rev(n);
    fo(i,m){
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].pb(v);
        rev[v].pb(u);
    }
    vi order;
    vi visited(n);
    auto dfs1 = [&](auto&&dfs1, int node)->void{
        visited[node] = 1;
        for(auto neigh:adj[node]){
            if(!visited[neigh]) dfs1(dfs1,neigh);
        }
        order.pb(node);
    };
    fo(i,n) if(!visited[i]) dfs1(dfs1,i);
    vi visited1(n);
    int curr = 1;
    auto dfs2 = [&](auto&&dfs2, int node)->void{
        visited1[node] = curr;
        for(auto neigh:rev[node]){
            if(!visited1[neigh]) dfs2(dfs2,neigh);
        }
    };
    reverse(all(order));
    for(auto x:order) if(!visited1[x]) {
        dfs2(dfs2,x);
        curr++;
    }
    for(auto &x: visited1) x--;
    int new_n = curr-1;
    vl K(new_n);
    fo(i,n) K[visited1[i]]+=k[i];
    debug(K);
    vvi new_adj(new_n);
    fo(i,n)for(auto x:adj[i]){
        if(visited1[i]!=visited1[x]) new_adj[visited1[i]].pb(visited1[x]);
    } 
    debug(new_adj);
    vl ans(n,-1);
    auto dfs3 = [&](auto &&dfs, int node)->ll{
        if(ans[node]!=-1) return ans[node];
        debug(node);
        ans[node] = K[node];
        ll add = 0;
        for(auto x:new_adj[node]){
            add = max(dfs(dfs,x),add);
        }
        return ans[node]+=add;
    };
    fo(i,new_n) dfs3(dfs3,i);
    cout<<*max_element(all(ans))<<endl;
}
