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
    int n;
    cin >> n;
    v(pii) a(n);
    fo(i,n){
        string s1,s2;
        cin>>s1>>s2;
        a[i].F = s1=="set";
        a[i].S = s2=="true";
    }
    debug(a);
    int m;
    cin>>m;
    vvi adj(n);
    fo(i,m){
        int u,v;
        cin>>u>>v;
        adj[--u].pb(--v);
    }
    debug(adj);
    int st = -1, ust = -1;
    set<int> sf,usf;
    fo(i,n) {
        if(a[i]==make_pair(1,1)) st=i; 
        if(a[i]==make_pair(0,1)) ust=i;
        if(a[i]==make_pair(1,0)) sf.insert(i);
        if(a[i]==make_pair(0,0)) usf.insert(i);
    }
    debug2(sf,usf); 
    debug2(st,ust);
    if(ust!=-1) for(auto v:adj[ust]){
        if(v==st || sf.count(v)) {
            cout<<"-1\n";
            return;
        }
    }
    vi topo;
    vb vis(n);
    bool possible = true;
    auto dfs = [&](auto &&dfs, int i)->void{
        vis[i]=1;
        for(auto v:adj[i]){
            if(v==st) possible = false;
            if(!vis[v] && sf.count(v)) dfs(dfs,v);
        }
        topo.pb(i);
    };
    for(auto i:sf){
        if(!vis[i]) dfs(dfs,i);
    }
    //adding st,ust to topo
    if(st!=-1)topo.pb(st),vis[st]=1;
    reverse(all(topo));
    if(ust!=-1) topo.pb(ust),vis[ust]=1;
    debug(vis);
    debug(topo);
    unordered_map<int,vector<int>> newadj;
    newadj[-1]={};
    fo(i,n){
        if(vis[i]){
            for(auto x: adj[i]) if(!vis[x]) newadj[-1].pb(x);
        }
        else{
            newadj[i]={};
            for(auto x: adj[i]) {
                if(!vis[x]) newadj[i].pb(x);
            }
            for(auto x: adj[i]) {
                if(vis[x]) newadj[i].pb(-1);break;
            }
        }
    }
    debug(newadj);
    //doing topo sort of remaining
    unordered_map<int,int> newvis;
    vi final_topo;
    //st + sf + ust = -1
    auto dfs1 = [&](auto &&dfs1, int i)->void{
        newvis[i]=1;
        for(auto v:newadj[i]){
            if(!newvis[v]) dfs1(dfs1,v);
            if(newvis[v]==1) possible = false;
        }
        newvis[i]=2;
        final_topo.pb(i);
    };
    dfs1(dfs1,-1);
    for(auto [x,y]:newadj) if(!newvis[x])dfs1(dfs1,x);
    reverse(all(final_topo));
    debug(final_topo)

    vi answer;
    for(auto x:final_topo){
        if(x!=-1) answer.pb(x+1);
        else if(x==-1){
            for(auto y:topo) answer.pb(y+1);
        }
    }

    if(st == -1 && topo.size()) possible = false;
    if(ust == -1 && final_topo.back()!=-1) possible = false;
    if(possible) {print_space(answer,n);}
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
