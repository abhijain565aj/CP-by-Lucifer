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

ll MOD = 998244353;

// Modular Arithmetic
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
vector<int> p2(100005);
void solve()
{
    ll n;
    cin>>n;
    vl a(n);
    read(a,n);
    vector<pll> t;
    vl o;
    vl count(n);
    count[0] = (a[0]==2);
    fo1(i,1,n) count[i] = count[i-1]+(a[i]==2);
    debug(count);
    fo(i,n) {
        if(a[i] == 1) o.pb(i); 
        else if(a[i]==3) t.pb({i,-1});
    }
    if(t.empty()){
        cout<<0<<endl;
        return;
    }
    t.back().S = power(2,count[t.back().F]);
    for(int i=t.size()-2;i>=0;i--) t[i].S = add(t[i+1].S,p2[count[t[i].F]]);
    ll ans = 0;
    debug2(o,t);    
    for(auto i:o){
        auto itr = upper_bound(all(t),make_pair(i,0ll));
        if(itr == t.end()) continue;
        int it = itr-t.begin();
        ll v = divide(t[it].S,p2[count[i]]);
        ll b = sub(v,t.size()-it);
        debug(b);
        ans = add(ans,b);
        debug(ans);
    }
    cout<<ans<<endl;
}

int main()
{
    fastio; Error_file("0_Error.txt");
    int testCases = 1;
    cin >> testCases;
    p2[0] = 1;
    fo1(i,1,100005) p2[i] = mul(2,p2[i-1]);
    fo(tt, testCases){
        test(tt + 1);
        solve();
    }
    test(0);
}
