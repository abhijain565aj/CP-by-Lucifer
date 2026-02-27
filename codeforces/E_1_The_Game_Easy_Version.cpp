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
    // cout<<"Hello World\n";
    ll n;
    cin >> n;
    vl a(n);
    read(a, n);
    vvl adj(n);
    fo(i,n-1){
        ll u,v;cin>>u>>v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vl b = a;
    sortall(b);
    b.resize(unique(all(b))-b.begin());
    map<ll,ll> mp;
    fo(i,b.size()){
        mp[b[i]] = b.size()-i;
    }
    fo(i,n) a[i] = mp[a[i]];
    v(pll) best(n);
    vl parent(n,-1);
    vl distance(n,0);
    function<void(int,int)> dfs1 = [&](int u, int p)->void{
        best[u] = {a[u],u};
        for(auto v:adj[u]){             
            if(v==p) continue;
            parent[v] = u;
            distance[v] = distance[u]+1;
            dfs1(v,u);
            best[u] = min(best[u],best[v]);
        }
    };
    dfs1(0,-1);
    map<ll,set<int>> pos;
    fo(i,n){
        pos[a[i]].insert(i);
    }
    debug(pos);
    vl path_to_root;
    int current = *pos[1].begin();
    for(auto x: pos[a[0]]){
        if(distance[x]>distance[current]) current = x;
    }
    debug(current);
    while(current!=-1){
        path_to_root.pb(current);
        current = parent[current];
    }
    int cb = 0;
    int nb = 1; 
    vl v;
    for(auto x:path_to_root){
        if(a[x]<cb){
            cout<<v.back()+1<<endl;
            return;
        }
        else if(a[x]==cb){
            v.pb(x);
        }
        else if(a[x]==nb){
            v.pb(x);
            cb = nb;
            nb++;
        }
    }
    debug(v);
    auto erase = [&](auto&& erase, int x)->void{
        pos[1].erase(x);
        for(auto y:adj[x]){
            if(a[y]==1 && pos[1].find(y)!=pos[1].end()){
                erase(erase,y);
            }
        }
    };
    int ret = -1;
    for(auto x:v){
        if(a[x]==1)
            erase(erase,x);
        else if(a[x]==2){
            ret = x;
            break;
        }
    }
    debug(pos);
    for(auto x:v){
        pos[a[x]].erase(x);
    }
    for(auto [x,s]:pos){
        if(x!=1){
            if(s.size()>=1){
                cout<<*s.begin()+1<<endl;
                return;
            }
        }
    }
    if(pos[1].size()>=1){
        cout<<ret<<endl;
        return;
    }
    cout<<0<<endl;
    debug(v);
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
