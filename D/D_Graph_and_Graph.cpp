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

void solve()
{
    ll n;
    cin>>n;
    int a,b;
    cin>>a>>b; a--;b--;
    vvi adj1(n);
    int m1;cin>>m1;
    fo(i,m1){
        int u,v;
        cin>>u>>v;
        adj1[u-1].pb(v-1);
        adj1[v-1].pb(u-1);
    }
    vvi adj2(n);
    int m2;cin>>m2;
    fo(i,m2){
        int u,v;
        cin>>u>>v;
        adj2[u-1].pb(v-1);
        adj2[v-1].pb(u-1);
    }
    //dijkstra on graph with nodes {v1,v2};
    v(pii) goal;
    vvi dist(n,vi(n,1e9));
    dist[a][b] = 0;
    set<pii> pq;
    pq.insert({0,a+b*2000});
    while(!pq.empty()){
        auto [d,node] = *pq.begin();
        int u = node%2000, v = node/2000;
        pq.erase({d,node});
        for(auto u1:adj1[u]) for(auto v1:adj2[v]){
            if(u==v && u1==v1) {
                goal.pb({u,v});
            }
            if(dist[u1][v1]>d+abs(u1-v1)){
                pq.erase({dist[u1][v1],u1+v1*2000});
                dist[u1][v1] = d + abs(u1-v1);
                pq.insert({dist[u1][v1],u1+v1*2000});    
            }
        }
    }
    debug(dist);
    debug(goal);
    if(goal.size()==0){
        cout<<-1<<endl;
        return;
    }
    int min = 1e9;
    for(auto [u,v]:goal){
        min = std::min(min,dist[u][v]);
    }
    cout<<min<<endl;
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
