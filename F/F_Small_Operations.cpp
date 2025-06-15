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
vvl fac(1000001);
ll count(vector<ll> &a, ll k) {
    if(a.empty()) {
        debug("Empty");
        return 0;
    }
    ll bin = a.size();
    v(pll) b;
    b.pb({a[0],0});
    for(auto x:a) {
        if(b.back().F == x) {
            b.back().S++;
        }
        else {
            b.pb({x,1});
        }
    }
    map<v(pll),pll> dp;   //oper, left
    dp[{}] = {0, k}; // base case
    auto fn = [&](auto&&fn, v(pll)& b) -> pll{
        if(dp.find(b) != dp.end()) {
            return dp[b];
        }
        auto ans = pll(INF, 0);
        int count = 0;
        for(int i=0; i<b.size(); i++){
            if(b[i].S<=0) continue;
            count++;
            b[i].S--;
            pll res = fn(fn,b);
            if(res.S >= b[i].F){
                ans.F = min(ans.F, res.F);
                if(ans.F == res.F) {
                    ans.S = max(ans.S, res.S/b[i].F);
                }
            }
            else {
                ans.F = min(ans.F, res.F + 1);
                if(ans.F == res.F + 1) {
                    ans.S = max(ans.S, max(res.S, k/b[i].F));
                }
            }
            b[i].S++;
        }
        if(count == 0) {
            ans.F = 1;
            ans.S = k;
        }
        return dp[b] = ans;
    };
    auto ans = fn(fn,b);
    return ans.F;
}
void solve()
{
    ll x,y,k;
    cin >> x >> y >> k;
    ll ans = 0;
    map<ll,ll> mp;
    for(auto f: fac[x]){
        while(x%f == 0) {
            x /= f;
            mp[f]--;
        }
    }
    for(auto f: fac[y]){
        while(y%f == 0) {
            y /= f;
            mp[f]++;
        }
    }
    vl div, mul;
    for(auto [f,c]: mp){
        if(c > 0) {
            fo(i,c) mul.pb(f);
        }
        else {
            fo(i,-c) div.pb(f);
        }
    }
    debug2(div,mul);
    if((div.size()>0 && div.back()>k) || (mul.size()>0 && mul.back()>k)) {
        cout << "-1\n";
        return;
    }
    cout << count(mul, k) + count(div, k) << "\n";
}

int main()
{
    fastio; 
    Error_file("0_Error.txt");
    int testCases = 1;
    cin >> testCases;
    for(int i = 2; i <= 1000000; i++) {
        for(int j = i; j <= 1000000; j += i) {
            fac[j].pb(i);
        }
    }
    fo(tt, testCases){
        test(tt + 1);
        solve();
    }
    test(0);
}
