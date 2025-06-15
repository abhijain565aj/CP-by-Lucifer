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

void brute()
{
    int n;
    cin>>n;
    v(vvl) a(n, vvl(n, vl(n)));
    fo(i,n) fo(j,n) fo(k,n) cin>>a[i][j][k];
    ll x,y,z;
    x = y = z = (1<<n)-1;
    auto check = [&](ll i, ll j, ll k)->bool{
        if((x>>i & 1) & (y>>j & 1) & (z>>k & 1)) return true;
        else return false;
    };
    auto add = [&](ll i, ll j, ll k){
        x ^= 1<<i;
        y ^= 1<<j;
        z ^= 1<<k;
    };
    auto remove = add;
    ll ans = 1e15;
    vi dx = {-1,1};
    auto dfs = [&](auto&& dfs, int i, int j, int k, ll sum)->void{
        debug3(i,j,k);
        add(i,j,k);
        fo(j1,n) fo(k1,n){
            if(check(i+1,j1,k1)){
                dfs(dfs,i+1,j1,k1,sum+a[i+1][j1][k1]);
            }
        }
        if(x==0 && y==0 && z==0) ans = min(ans,sum);
        remove(i,j,k);
    };
    fo(j,n) fo(k,n) dfs(dfs,0,j,k,a[0][j][k]);
    cout<<ans<<endl;
}
void solve(){
    int n;
    cin>>n;
    v(vvl) a(n, vvl(n, vl(n)));
    fo(i,n) fo(j,n) fo(k,n) cin>>a[i][j][k];
    ll x,y,z;
    x = y = z = (1<<n)-1;
    auto check = [&](ll i, ll j, ll k)->bool{
        if((x>>i & 1) & (y>>j & 1) & (z>>k & 1)) return true;
        else return false;
    };
    auto add = [&](ll i, ll j, ll k){
        x ^= 1<<i;
        y ^= 1<<j;
        z ^= 1<<k;
    };
    auto remove = add;
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
