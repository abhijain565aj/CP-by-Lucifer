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

// #define MOD 1000000007
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

int MOD = 998244353;
ll mod(ll a, ll m = MOD) {return (a % m + m) % m;}
ll add(ll a, ll b, ll m = MOD){return mod(a + b, m);}
ll sub(ll a, ll b, ll m = MOD){return mod(a - b, m);}
ll mul(ll a, ll b, ll m = MOD){return mod(a * b, m);}
ll power(ll a, ll b, ll m = MOD){
    ll res = 1;
    while (b){
        if (b & 1)
            res = mul(res, a, m);
        a = mul(a, a, m);
        b >>= 1;
    }
    return res;
}
ll inv(ll a, ll m = MOD){return power(a, m - 2, m);}
ll divide(ll a, ll b, ll m = MOD){return mul(a, inv(b, m), m);}
void solve()
{
    ll n, m ,k;
    cin >> n >> m >> k;
    vvl adj(n);
    fo(i, m){
        int u, v;
        cin >> u >> v;
        adj[u - 1].pb(v - 1);
    }
    //run dfs and mark colouring;
    // also mark component of each node
    vl colour(n, -1);
    vl component(n, -1);
    int current = 0;
    bool possible = true;
    function<void(int, int)> dfs = [&](int node, int col){
        colour[node] = col;
        component[node] = current; 
        for(auto i: adj[node]){
            if(colour[i] == -1){
                dfs(i, col ^ 1);
            }
            else if(colour[i] == col){
                possible = false;
            }
        }
    };
    if(!possible){
        cout << 0 << endl;
        return;
    }
    for(int i = 0; i < n; i++){
        if(colour[i] == -1){
            dfs(i, 0);
            current++;
        }
    }
    vvi count(current, vi(2,0));
    fo(i, n){
        count[component[i]][colour[i]]++;
    }
    debug2(component, colour);
    debug(count);
    fo(i,current) k-=min(count[i][0], count[i][1]);
    if(k < 0){
        cout << 0 << endl;
        return;
    }
    vi v;
    fo(i,current){
        v.pb(max(count[i][0], count[i][1]) - min(count[i][0], count[i][1]));
    }
    sortall(v);
    vi dp(k + 1, 0);
    dp[0] = 1;
    for (int num : v) {
        for (int s = k; s >= num; s--) {
            dp[s] += dp[s - num];
        }
    }
    cout<<divide(dp[k], power(2,n))<<endl;
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
