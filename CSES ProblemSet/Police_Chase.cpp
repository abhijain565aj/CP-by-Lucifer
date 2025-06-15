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
    ll n,m;
    cin>>n>>m;
    vvl adj(n,vl(n));
    vvl ind(n);
    fo(i,m){
        ll u,v,c;
        cin>>u>>v;
        u--,v--;
        adj[u][v] = 1;
        adj[v][u] = 1;
        ind[u].pb(v);
        ind[v].pb(u);
    }
    auto cap = adj;
    fo(i,n){
        sort(all(ind[i]));
        ind[i].resize(unique(all(ind[i]))-ind[i].begin());
    }
    vl parent(n,-1);
    auto bfs = [&]()->bool{
        parent.assign(n,-1);
        parent[0] = -2;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(auto i:ind[cur]) if(adj[cur][i]>0 && parent[i]==-1){
                q.push(i);
                parent[i] = cur;
                if(i==n-1) return true;
            }
        }
        return false;
    };
    debug(adj);
    ll ans = 0;
    while(bfs()){
        int s = 0, t = n-1;
        vl path = {n-1};
        if(parent[n-1]==-1) break;
        while(parent[path.back()]!=-2){
            path.pb(parent[path.back()]);
        }
        debug(path);
        ll bottleneck = 1e18;
        for(int i=path.size()-1;i>0;i--){
            bottleneck = min(bottleneck,adj[path[i]][path[i-1]]);
        }
        debug(bottleneck)
        for(int i=path.size()-1;i>0;i--){
            adj[path[i]][path[i-1]]-=bottleneck;
            adj[path[i-1]][path[i]]+=bottleneck;
        }
        ans+=bottleneck;
    }
    cout<<ans<<endl;
    fo(i,n)fo(j,n) if(cap[i][j]>0 && parent[i]!=-1 && parent[j]==-1){
        cout<<i+1<<" "<<j+1<<endl;
    }
}
