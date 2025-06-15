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

void solve()
{
    ll n,q;
    cin>>n>>q;
    vl b(n);
    read(b,n);
    vl c(n);
    v(v(v(pll))) adj(n);
    fo(i,n) adj[i].pb({});
    vvl val(n);
    v(v(pll)) queries(q);
    fo(i,q){
        int x,y,z;
        cin>>x>>y>>z;
        x--,y--,z--;
        queries[i] = {{x,c[x]},{y,c[y]},{z,c[z]+1}};
        adj[y][c[y]].pb({z, c[z]+1});
        adj[x][c[x]].pb({z, c[z]+1});
        c[z]++;
        adj[z].pb({});
    }
    fo(i,n) {
        val[i].resize(c[i]+1,-1);
        val[i].back() = b[i];
    }
    auto dfs = [&](auto &&dfs, int u, int cnt) -> int {
        if(val[u][cnt] != -1) return val[u][cnt];
        int ans = 0;
        for(auto &v : adj[u][cnt]) {
            ans = max(ans, dfs(dfs, v.F, v.S));
        }
        return val[u][cnt] = ans;
    };
    re(i,q){
        //check all queries
        int x = queries[i][0].F, y = queries[i][1].F, z = queries[i][2].F;
        int cnt_x = queries[i][0].S, cnt_y = queries[i][1].S, cnt_z = queries[i][2].S;
        dfs(dfs, x, cnt_x);
        dfs(dfs, y, cnt_y);
        dfs(dfs, z, cnt_z);
        if(val[x][cnt_x] == -1 || val[y][cnt_y] == -1 || val[z][cnt_z] == -1) {
            continue;
        }
        if(val[z][cnt_z] != min(val[y][cnt_y], val[x][cnt_x])) {
            cout << "-1" << endl;
            return;
        } 
    }
    fo(i,n) cout<<dfs(dfs, i, 0)<<" ";
    cout<<endl;
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
