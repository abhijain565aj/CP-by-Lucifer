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
    cin>>n;
    vvl adj(n);
    fo(i,n-1){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    debug(adj);
    vi parent(n,-1);
    vi distance(n,0);
    function<void(int)> dfs = [&](int i){
        for(auto x:adj[i]){
            if(x==parent[i]) continue;
            parent[x] = i;
            distance[x] = distance[i]+1;
            dfs(x);
        }
    };
    dfs(0);
    int maxdist = *max_element(all(distance));
    int ind = -1;
    fo(i,n) if(distance[i]==maxdist) ind = i;
    debug2(maxdist,ind);
    fo(i,n) distance[i] = 0, parent[i] =-1;
    dfs(ind);
    maxdist = *max_element(all(distance));
    int ind1 = -1;
    fo(i,n) if(distance[i]==maxdist) ind1 = i;
    debug2(maxdist,ind);
    auto distance1 = distance;
    fo(i,n) distance[i] = 0, parent[i] =-1;
    dfs(ind1);
    fo(i,n) cout<<max(distance[i],distance1[i])<<" ";
    cout<<endl;
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
