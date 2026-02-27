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

void solve()
{
    ll m,n;
    cin >> m>>n;
    vl d(m);
    read(d, m);
    sortall(d);
    debug(d);
    vl dist;
    ll sum = 0;
    fo(i,n-1) sum += d[i];
    fo1(i,n-1,m){
        dist.pb(sum + d[i]);
        sum += d[i] - d[i - n + 1];
    }
    for(auto &x:dist) x*=2;
    debug(dist);

    //storing sum of distances upto next n-1 elements
    vl dist3;
    sum = 0;
    fo(i,n){
        sum += d[i]-d[0];
    }
    dist3.pb(sum);
    fo1(i,n,m){
        sum -= (n-1)*(d[i-n+1]-d[i-n]);
        sum += d[i] - d[i-n+1];
        dist3.pb(sum);
    }   
    debug(dist3);

    //storing all pairs of distances from i to i+n-1
    vl dist2;
    sum = 0;
    fo(i,n-1){
        sum +=(d[i+1]-d[i])*(i+1)*(n-i-1);
    }
    dist2.pb(sum);
    fo1(i,n,m){
        sum -= dist3[i-n];
        sum += (d[i]-d[i-1])*(n-1);
        dist2.pb(sum);
    }
    ll ans = INF;
    fo(i,dist.size()){
        ans = min(ans, dist[i] + 2*dist2[i]);
    }
    cout<<ans<<endl;
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
