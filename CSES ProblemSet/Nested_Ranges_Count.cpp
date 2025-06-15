// Solution by Abhi Jain aka Lucifer aka abhijain565aj
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;
#define ordered_set tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> // find_by_order, order_of_key

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

int main()
{
    fastio;Error_file("0_Error.txt");
    ll n;
    cin>>n;
    v(pll) a;
    fo(i,n){
        ll l,r;
        cin>>l>>r;
        a.pb({l,r});
    }
    vvl b;
    fo(i,n){
        b.pb({a[i].F,-1,i});
        b.pb({a[i].S,+1,i});   
    }
    sortall(b);
    vl inside(n);
    vl outside(n);
    ordered_set open;
    ordered_set closed;
    debug(b);
    fo(i,b.size()){
        if(b[i][1]==-1) open.insert({b[i][0],b[i][2]});
        else if(b[i][1]==1){
            vvl temp;
            int j = i;
            while(i<b.size()&&b[i][0]==b[j][0]){
                temp.pb(b[i]);
                i++;
            }
            i--;
            for(auto x:temp){
                closed.insert({a[x[2]].F,x[2]});
            }
            for(auto x:temp){
                outside[x[2]] = open.order_of_key({a[x[2]].F,n+1})-1; 
                inside[x[2]] = closed.size()-1-closed.order_of_key({a[x[2]].F,-1});
            }
            for(auto x:temp){
                open.erase({a[x[2]].F,x[2]});
            }
        }
    }
    print_space(inside,n);
    print_space(outside,n);
}
