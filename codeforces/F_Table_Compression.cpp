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
struct DSU
{
    vector<int> parent, size; // parent of each node and size of each component
    int components;           // number of connected components
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        components = n;
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = find(parent[x]); // path compression
    }
    void unite(int x, int y)
    {
        x = find(x); // find the parent of x
        y = find(y); // find the parent of y
        if (x != y)  // if x and y are not in the same component
        {
            if (size[x] < size[y])
            {
                swap(x, y);
            }
            parent[y] = x;
            size[x] += size[y];
            components--;
        }
    }
    bool same(int x, int y) // check if x and y are in the same component
    {
        return find(x) == find(y);
    }
    int getSize(int x) // get the size of the component of x
    {
        return size[find(x)];
    }
    int getComponents() // get the number of connected components
    {
        return components;
    }
};
void solve()
{
    ll n,m;
    cin >> n>>m;

    vvl a(n,vl(m));
    fo(i,n){
        fo(j,m){
            cin >> a[i][j];
        }
    }
    auto b = a;
    fo(i,n) fo(j,m){
        b[i][j] = i*m + j;
    }   
    vvl rev_adj(m*n);
    DSU dsu(n*m);
    //joining the same elements in same row or same column
    fo(i,n) {
        auto temp = a[i];
        map<ll, vl> mp;
        fo(j,m) {
            mp[temp[j]].pb(i*m + j);
        }
        for(auto [x,v]:mp){
            for(int j=1;j<v.size();j++){
                dsu.unite(v[j],v[j-1]);
            }
        }
    }
    //joining the same elements in same column
    fo(j,m){
        vl temp;
        fo(i,n) temp.pb(a[i][j]);
        map<ll, vl> mp;
        fo(i,n) {
            mp[temp[i]].pb(i*m + j);
        }
        for(auto [x,v]:mp){
            for(int j=1;j<v.size();j++){
                dsu.unite(v[j],v[j-1]);
            }
        }
    }
    
    fo(i,n){
        auto temp = a[i];
        map<ll, ll> mp;
        fo(j,temp.size()){
            mp[temp[j]] = dsu.find(i*m+j);
        }
        sortall(temp);
        temp.resize(unique(all(temp)) - temp.begin());
        fo(i,temp.size()-1){
            rev_adj[mp[temp[i+1]]].pb(mp[temp[i]]);
        }
    }
    fo(j,m){
        vl temp;
        fo(i,n) temp.pb(a[i][j]);
        map<ll, ll> mp;
        fo(i,temp.size()){
            mp[temp[i]] = dsu.find(i*m+j);
        }

        sortall(temp);
        temp.resize(unique(all(temp)) - temp.begin());

        fo(i,temp.size()-1){
            rev_adj[mp[temp[i+1]]].pb(mp[temp[i]]);
        }
    }

    debug(a);
    debug(rev_adj);
    vl max_dist(m*n, 1);
    set<pii> arr;
    fo(i,m*n){
        int x = dsu.find(i);
        arr.insert({a[x/m][x%m],x});
    }
    for(auto [val, i]:arr){
        ll ans = 1;
        for(auto x:rev_adj[i]){
            ans = max(ans, max_dist[x]+1);
        }
        max_dist[i] = ans;
    }
    fo(i,n) fo(j,m) a[i][j] = max_dist[dsu.find(i*m+j)];
    fo(i,n){
        fo(j,m){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    fastio; 
    // Error_file("0_Error.txt");
    int testCases = 1;
    // cin >> testCases;
    fo(tt, testCases){
        test(tt + 1);
        solve();
    }
    test(0);
}
