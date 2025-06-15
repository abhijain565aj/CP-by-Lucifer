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
vi pow2(1e5+1);
void solve()
{
    ll n;
    cin >> n;
    vl b(n), c(n);
    read(b, n);
    read(c, n);
    vl r(n);
    v(pll) bmax(n), cmax(n);
    bmax[0] = {b[0], 0};
    cmax[0] = {c[0], 0};
    fo1(i, 1, n) {
        bmax[i] = max(bmax[i-1], {b[i], i});
        cmax[i] = max(cmax[i-1], {c[i], i});
    }
    fo(i, n) {
        if(bmax[i].F > cmax[i].F) {
            auto ind = bmax[i].S;
            r[i] = pow2[b[ind]] + pow2[c[i-ind]];
        }
        else if(cmax[i].F > bmax[i].F) {
            auto ind = cmax[i].S;
            r[i] = pow2[b[i-ind]] + pow2[c[ind]];
        }
        else {
            auto j1 = bmax[i].S;
            auto j2 = cmax[i].S;
            if(c[i-j1]>b[i-j2]){
                r[i] = pow2[b[j1]] + pow2[c[i-j1]];
            }
            else {
                r[i] = pow2[b[i-j2]] + pow2[c[j2]];
            }
        }
        r[i] = (r[i]) % MOD;
    }
    print_space(r, n);
}

int main()
{
    fastio; Error_file("0_Error.txt");
    int testCases = 1;
    pow2[0] = 1;
    fo1(i, 1, 1e5+1) {
        pow2[i] = (pow2[i-1] * 2) % MOD;
    }
    cin >> testCases;
    fo(tt, testCases){
        test(tt + 1);
        solve();
    }
    test(0);
}
