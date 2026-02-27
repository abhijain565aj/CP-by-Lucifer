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
    vvl adj(n);
    fo(i, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    v(pll) b(n);
    fo(i,n) b[i] = {adj[i].size(),i};
    sortall(b);
    reverse(all(b));
    vl maxv;
    maxv.pb(b[0].S);
    ll ans = 0;
    fo1(i,1,b.size()){
        if(b[i].F==b[0].F){
            maxv.pb(b[i].S);
        }
    }
    debug(b);
    debug(maxv);
    if(maxv.size()>2){
        cout<<2*b[0].F-1<<endl;
    }
    else if(maxv.size()==2){
        bool edge = false;
        //check if edge between b[0] and b[1]
        for(auto i:adj[b[0].S]){
            if(i==b[1].S){
                edge = true;
                break;
            }
        }
        if(edge){
            cout<<2*b[0].F-2<<endl;
        }
        else{
            cout<<2*b[0].F-1<<endl;
        }
    }
    else{
        set<int> max2;
        max2.insert(b[1].S);
        fo(i,b.size()){
            if(b[i].F==b[1].F){
                max2.insert(b[i].S);
            }
        }
        ans = b[0].F+b[1].F-2;
        debug(ans);
        for(auto x:adj[b[0].S]){
            max2.erase(x);
        }
        if(max2.size()>0){
            ans++;
        }
        cout<<ans<<endl;
    }
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
