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
    int n, m;
    cin >> n >> m;
    vvi a(n,vi(m));
    fo(i,n) fo(j,m) cin >> a[i][j];
    int mxV = 0;
    fo(i,n) fo(j,m) mxV = max(mxV, a[i][j]);
    v(pii) ind;
    fo(i,n) fo(j,m) if(a[i][j] == mxV) ind.pb({i,j});
    debug2(mxV, ind);
    pii mx1 = {ind[0].F, ind[0].S};
    pii mx2 = {ind[0].F, ind[0].S};
    fo1(i,1,ind.size()){
        if(ind[i].F!= mx1.F && ind[i].S != mx1.S){
            mx1.S = ind[i].S;
            mx2.F = ind[i].F;
            break;
        }
    }
    debug2(mx1, mx2);
    bool possible1 = true;
    bool possible2 = true;    
    for(auto p : ind){
        if(p.F != mx1.F && p.S != mx1.S) possible1 = false;
    }
    for(auto p : ind){
        if(p.F != mx2.F && p.S != mx2.S) possible2 = false;
    }
    if(possible1 || possible2){
        cout<<mxV - 1 << endl;
        return;
    }
    cout<<mxV<< endl;
}

int main()
{
    fastio; 
    // Error_file("0_Error.txt");
    int testCases = 1;
    cin >> testCases;
    fo(tt, testCases){
        test(tt + 1);
        solve();
    }
    test(0);
}
