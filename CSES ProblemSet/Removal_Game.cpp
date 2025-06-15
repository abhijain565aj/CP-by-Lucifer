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

pll rev(pll &a)
{
    return {a.S,a.F};
}
pll operator+ (pll &a,pll &b)
{
    return {a.F+b.F,a.S+b.S};
}
int main()
{
    fastio; 
    // Error_file("0_Error.txt");
    ll n;
    cin>>n;
    vl a(n);
    read(a,n);
    v(v(pll)) dp(n,v(pll)(n,{-1,-1}));
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(i==j) {
                dp[i][j] = {a[i],0};
                continue;
            }
            dp[i][j].F = max(dp[i+1][j].S+a[i],dp[i][j-1].S+a[j]);
            if(dp[i][j].F == dp[i+1][j].S+a[i]){
                dp[i][j].S = dp[i+1][j].F;
            }else{
                dp[i][j].S = dp[i][j-1].F;
            }
        }
    }
    cout<<dp[0][n-1].F<<endl;
    debug(dp);
}
