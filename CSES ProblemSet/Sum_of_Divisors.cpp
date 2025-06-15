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

ll MOD = 1000000007;

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
void brute(int n){
    ll sum = 0;
    fo1(i,1,n) sum += n%i;
    cout << sum << "\n";
}
int main()
{
    fastio; 
    // Error_file("0_Error.txt");
    ll n; cin>>n;
    if(n==1){
        cout<<1<<"\n";
        return 0;
    }
    ll i = 0;
    ll ans = n;
    pll last = {1, mod(n)};
    ll inv_2 = inv(2);
    for(i=2;i*i<=n;i++){
        ans = add(ans,sub(n,n%i));
        // debug(ans);
        auto current = make_pair(i, mod(n/i));
        ll n_elem = sub(last.S, current.S);
        ll aPlusL = add(last.S, current.S + 1);
        ll mul_sum = mul(mul(n_elem, aPlusL),inv_2);
        ll v = mul(mul_sum,last.F);
        ans = add(ans,v);
        // debug(ans);
        last = current;
    }
    debug(ans);
    debug(last);
    if(last.F!= last.S) {
        ans = add(ans,sub(n,n%last.S));
    }
    cout<<ans<<"\n";
}