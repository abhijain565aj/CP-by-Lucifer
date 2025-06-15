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
vvl fac(5001);
void solve()
{
    int n;
    cin >> n;
    vl a(n);
    read(a, n);
    ll gcd = a[0];  
    fo1(i, 1, n) {
        gcd = __gcd(gcd, a[i]);
    }
    ll cnt1 = 0;
    map<int,int> taken;
    for(auto &x : a) {
        x /= gcd;
        if(x == 1) {
            cnt1++;
        }
        ll new_x = x;
        for(auto &f : fac[x]) {
            while(new_x % (f*f) == 0) {
                new_x /= f;
            }
        }
        x = new_x;
        taken[x]++;
    }
    debug(a);
    if(cnt1){
        cout << n - cnt1 << endl;
        return;
    }
    sortall(a);
    a.resize(unique(all(a)) - a.begin());
    vl curr = a;
    ll ans1 = 0;
    while(curr[0]!=1){
        vl new_curr;
        for(auto &x:a){
            for(auto &y:curr){
                ll z = __gcd(x, y);
                if(!taken[z]) new_curr.pb(z);
            }
        }
        ans1++;
        curr = new_curr;
        sortall(curr);
        curr.resize(unique(all(curr)) - curr.begin());
    }
    cout << ans1 + n - 1 << endl;
}

int main()
{
    fastio; 
    // Error_file("0_Error.txt");
    for(int i = 2; i<5001;i++){
        if(fac[i].size() == 0){
            for(int j = i; j<5001;j+=i){
                fac[j].pb(i);
            }
        }
    }
    int testCases = 1;
    cin >> testCases;
    fo(tt, testCases){
        test(tt + 1);
        solve();
    }
    test(0);
}
