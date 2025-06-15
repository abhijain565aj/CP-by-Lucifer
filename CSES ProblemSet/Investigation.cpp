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

#define int ll
signed main()
{
    fastio; 
    // Error_file("0_Error.txt");
    int n,m;
    cin>>n>>m;
    v(v(pii)) adj(n),rev(n);
    fo(i,m){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        adj[u].pb({v,w});
        rev[v].pb({u,w});
    }
    vi dist1(n,INF);
    set<pii> s;
    dist1[0] = 0;
    s.insert({0,0});
    while(s.size()){
        auto [d,u] = *s.begin();
        s.erase(s.begin());
        for(auto[c,w]:adj[u]){
            if(d+w<dist1[c]){
                s.erase({dist1[c],c});
                dist1[c] = d+w;
                s.insert({dist1[c],c});
            }
        }
    }
    vi dist2(n,INF);
    dist2[n-1] = 0;
    s.insert({0,n-1});
    while(s.size()){
        auto [d,u] = *s.begin();
        s.erase(s.begin());
        for(auto[c,w]:rev[u]){
            if(d+w<dist2[c]){
                s.erase({dist2[c],c});
                dist2[c] = d+w;
                s.insert({dist2[c],c});
            }
        }
    }
    set<int> good_nodes;
    int req = dist1[0]+dist2[0];
    fo(i,n) if(dist1[i]+dist2[i]==req) good_nodes.insert(i);
    debug2(dist1,dist2);
    map<int,vi> Adj;
    fo(i,n) if(good_nodes.find(i)!=good_nodes.end()){
        for(auto [x,w]:adj[i]) if(good_nodes.find(x)!=good_nodes.end() && dist1[x]==dist1[i]+w) Adj[i].pb(x);
    }
    debug(good_nodes);
    //Minimum price
    cout<<req<<" ";
    vi count(n);
    vi vis(n);
    vi distmx(n);
    vi order;
    auto dfs = [&](auto&&dfs, int node)->void{
        vis[node] = true;
        for(auto x:Adj[node]) if(!vis[x]) dfs(dfs,x);
        order.pb(node);
    };
    for(auto x:good_nodes) if(!vis[x]) dfs(dfs,x);
    debug(order);
    count[n-1] = 1;
    distmx[n-1] = 0;
    for(auto y:order){
        for(auto x:Adj[y]) count[y]=(count[y]+count[x])%MOD;
        for(auto x:Adj[y]) distmx[y] = max(distmx[y],distmx[x]+1);
    }
    //Min and Max number of flights
    vi dis(n,-1);
    queue<int> q;
    q.push(0);
    dis[0] = 0;
    while(!q.empty()){
        int nd = q.front();
        q.pop();
        for(auto x:Adj[nd]) if(dis[x]==-1) dis[x] = dis[nd]+1, q.push(x);
    }
    cout<<count[0]<<" "<<dis[n-1]<<" "<<distmx[0];
}
