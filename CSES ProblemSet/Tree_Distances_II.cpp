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
ll n;
vvl adj;
vi parents;
vl ans;
vector<unordered_map<ll,pll>> dp; //subtree_size nd distance_sum
void dfs(int current,int parent){
    if(parent!=-1)
        dp[parent][current].F = 1;
    for(auto child: adj[current]){
        if(child==parent) continue;
        dfs(child,current);
        parents[child] = current;
        if(parent ==-1) continue;
        dp[parent][current].F += dp[current][child].F;
        dp[parent][current].S += dp[current][child].S + dp[current][child].F;
    }
}
void dfs1(int current,int parent){
    ans[current] = ans[parent] - 2*dp[parent][current].F + n; 
    for(auto child: adj[current]){
        if(child==parent) continue;
        dfs1(child,current);
    }
}
void solve()
{
    cin>>n;
    adj.resize(n);
    fo(i,n-1){
        ll u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    parents.resize(n,-1);
    dp.resize(n);
    ans.resize(n);

    dfs(0,-1);
    debug(dp);
    for(auto c:adj[0]) ans[0]+=dp[0][c].F + dp[0][c].S;
    debug(ans[0]);
    for(auto c:adj[0]) dfs1(c,0);
    print_space(ans,n);
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
