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

void solve()
{
    int n,m;
    cin>>n>>m;
    vvl edges;
    fo(i,m){
        ll a,b,w;
        cin>>a>>b>>w;
        a--;b--;
        edges.pb({a,b,w});
    }
    vvl adj(n);
    vvl adj1(n);
    vb visited(n);
    for(auto e:edges){
        adj[e[1]].pb(e[0]);
        adj1[e[0]].pb(e[1]);
    }
    auto dfs = [&](auto&& dfs, int current)->void{
        visited[current]=true;
        for(auto c:adj[current]){
            if(visited[c]) continue;
            visited[c]=true; dfs(dfs,c);
        }
    };
    dfs(dfs,n-1);
    vb visited1(n);
    auto dfs1 = [&](auto&& dfs1, int current)->void{
        visited1[current]=true;
        for(auto c:adj1[current]){
            if(visited1[c]) continue;
            visited1[c]=true; dfs1(dfs1,c);
        }
    };
    dfs1(dfs1,0);
    debug(visited);
    debug(visited1);
    vl distance(n,-1e15);
    distance[0]=0;
    bool possible = true;
    fo(i,n){
        int change = false;
        for(auto e: edges){
            if(distance[e[0]]+e[2]>distance[e[1]]){
                change = true;
                distance[e[1]] = distance[e[0]]+e[2];
                if(i==n-1 && visited[e[1]] && visited1[e[1]]) possible = false;
            }
        }
        if(!change) break;
        debug(distance);
    }
    if(possible) cout<<distance[n-1]<<endl;
    else cout<<-1<<endl;

}

int main()
{
    fastio; Error_file("0_Error.txt");
    int testCases = 1;
    // cin >> testCases;
    fo(tt, testCases){
        test(tt + 1);
        solve();
    }
    test(0);
}
