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
#define BITS 35
vi pow_k(1e5);
int main()
{
    fastio; Error_file("0_Error.txt");
    ll m,k,d;
    cin >> m >> k >> d;
    pow_k[0] = 1;
    for(ll i=1;i<1e5;i++) pow_k[i] = mul(k,pow_k[i-1]);
    vvl dp(d+2,vl(2*d+2,-1));
    auto rec = [&](auto &&rec, ll depth, ll length) -> ll{
        if(dp[depth][length] != -1) return dp[depth][length];
        if(depth+length/2>d) return dp[depth][length] = 0;
        debug2(depth,length);
        dp[depth][length] = mul(k,rec(rec,depth+1,length));
        debug(dp[depth][length])
        if(length>2){
            ll v = divide(mul(k,k-1),2LL);
            ll mf = 0;
            if(d >= depth + length - 2) mf = length - 2;
            else mf = 2*(d-depth) + 2 - length; 
            v = mul(v,mf);
            v = mul(v,pow_k[length-3]); //k^[i-1]*k[length-i-1]
            dp[depth][length] = add(dp[depth][length],v);
        }
        if(length>=1 && depth+length-1<=d){
            dp[depth][length] = add(dp[depth][length],pow_k[length-1]); 
        }
        return dp[depth][length];
    };  
    vi paths(2*d+2,0); //stored the number of paths of each length
    fo1(i,1,2*d+2) {
        if(k>1)
            paths[i] = rec(rec,0,i);
        else
            paths[i] = max(d+2-i,0ll);
    }
    debug(dp);
    debug(paths);

    //calculating the count of each bit;
    vl count(BITS);
    fo(j,BITS){
        ll pow2 = 1LL << (j+1);
        count[j] = (m/pow2)*(pow2/2);
        auto v = m%pow2 - pow2/2 + 1;
        if(v>0) count[j]+=v;
    }
    debug(count);
    vvl ncr(2*d+2,vl(2*d+2,-1));
    auto cal_ncr = [&](auto&& cal_ncr, ll n, ll r)->ll{
        if(r>n) return 0;
        if(ncr[n][r] != -1) return ncr[n][r];
        if(r==0 || r==n) return ncr[n][r]=1;
        return ncr[n][r] = add(cal_ncr(cal_ncr,n-1,r-1),cal_ncr(cal_ncr,n-1,r));
    };
    fo(i,2*d+2) fo(j,i+1) cal_ncr(cal_ncr,i,j);
    debug(ncr);
    auto bit_exist = [&](int bit)->vl{
        ll success = divide(count[bit],m);
        ll fail = sub(1ll,success);
        vl odd(2*d+2);
        //calculating powers of success failure
        vl power_of_fail(2*d+2);
        vl power_of_success(2*d+2);
        power_of_fail[0] = 1;
        power_of_success[0] = 1;
        for(int i=1;i<=2*d+1;i++){
            power_of_fail[i] = mul(power_of_fail[i-1],fail);
            power_of_success[i] = mul(power_of_success[i-1],success);
        }
        for(int i=1;i<=2*d+1;i++){
            for(int j=1;j<=i;j+=2){
                odd[i] = add(odd[i],mul(power_of_fail[i-j],mul(power_of_success[j],ncr[i][j])));
            }
        }
        return odd;
    };
    vvl b;
    fo(i,BITS) b.pb(bit_exist(i));
    debug(b);
    vl exp(2*d+2,0);
    for(ll i=1; i<=2*d+1; i++){
        for(ll j=0; j<BITS; j++){
            exp[i]=add(exp[i],mul(b[j][i],1LL<<j));
        }
    }
    debug(exp);
    ll ans = 0;
    for(ll i=1;i<=2*d+1;i++) ans = add(ans,mul(exp[i],paths[i]));
    cout<<ans<<endl;
}