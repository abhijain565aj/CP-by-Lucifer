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
// A hash function used to hash a pair of any kind
void solve()
{
    ll n, q;
    cin>>n>>q;
    vvl adj(n);
    fo(i,n-1){
        ll u,v; cin>>u>>v;
        adj[u-1].pb(v-1);
        adj[v-1].pb(u-1);
    }
    debug(adj);
    vvl parents(n,vl(20,-1));
    vl powers;
    fo(i,20) powers.pb(1<<i);
    debug(powers);
    vl call_stack;
    vl distance(n);
    auto dfs = [&](auto&& dfs, int current)->void{
        int sz = call_stack.size();
        fo(i,20){
            int ind = sz - (1<<i);
            if(ind>=0){
                parents[current][i] = call_stack[ind];
            }
            else break;
        }
        call_stack.pb(current);
        for(auto c:adj[current]) {
            if(c==parents[current][0]) continue;
            distance[c]=distance[current]+1; 
            dfs(dfs,c);
        }
        call_stack.pop_back();
    };
    dfs(dfs,0);
    debug(parents);
    debug(distance);
    auto ancestor = [&](int n, int k){
        vi bin;
        fo(i,20){
            if(k&(1<<i)) bin.pb(i);
        }
        for(auto x:bin){
            n = parents[n][x];
            if(n==-2) break;
        }
        return n;
    };
    while(q--){
        int u,v;
        cin>>u>>v;u--;v--;
        ll ans = distance[u]+distance[v];
        debug2(u,v);
        if(distance[u]>distance[v]) swap(u,v);
        v = ancestor(v,distance[v]-distance[u]);
        debug2(u,v);
        while(u!=v){
            re(i,20){
                if(parents[u][i]!=parents[v][i]){
                    u = parents[u][i]; 
                    v = parents[v][i];
                    break;
                }
            }
            if(parents[u][0]==parents[v][0]){
                u = v = parents[u][0];
                break;
            }
        }
        cout<<ans-2*distance[u]<<"\n";
    }
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
