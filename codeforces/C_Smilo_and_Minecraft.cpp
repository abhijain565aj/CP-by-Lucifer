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
    int n,m,k;
    cin >> n >> m >> k;
    k--;
    vs s(n);
    fo(i, n) cin >> s[i];
    vvi a(n, vi(m));
    a[0][0] = s[0][0] =='g';
    fo1(i,1,n) a[i][0] = a[i-1][0] + (s[i][0] == 'g');
    fo1(j,1,m) a[0][j] = a[0][j-1] + (s[0][j] == 'g');
    fo1(j,1,m){
        fo1(i,1,n){
            a[i][j] = a[i][j-1]+a[i-1][j] - a[i-1][j-1] + (s[i][j] == 'g');
        }
    }
    debug(a);
    auto fn = [&](int i, int j){
        j = min(j, m-1);
        i = min(i, n-1);
        if(i<0 || j<0) return 0;
        else return a[i][j];
    };
    int total = a[n-1][m-1];
    int ans = 1e9;
    fo(i,n)fo(j,m) if(s[i][j]=='.'){
        int curr = fn(i+k,j+k) - fn(i-k-1,j+k) - fn(i+k,j-k-1) + fn(i-k-1,j-k-1);
        ans = min(ans, curr);
    };
    cout << total - ans << endl;
}

int main()
{
    fastio; 
    //Error_file("0_Error.txt");
    int testCases = 1;
    cin >> testCases;
    fo(tt, testCases){
        test(tt + 1);
        solve();
    }
    test(0);
}
