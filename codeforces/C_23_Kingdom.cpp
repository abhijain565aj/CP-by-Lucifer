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
    int n;
    cin >> n;
    vi a(n);
    read(a, n);
    map<int, set<int>> m;
    fo(i, n){
        m[a[i]].insert(i);  
    }
    v(pii) ans(n,{0, 0});

    set<int> s;
    for(int i=n; i > 0; i--){
        s.insert(m[i].begin(), m[i].end());
        if(s.size()>=2){
            ans[*s.begin()] = {i, -1};
            ans[*s.rbegin()] = {i, +1};
            s.erase(*s.begin());
            s.erase(*s.rbegin());
        }
    }
    
    set<int> unique;
    for(int i=0; i<n; i++){
        unique.insert(ans[i].F);
    }
    debug(unique);
    
    ans.clear(), s.clear();
    ans.resize(n,{0, 0});
    for(int i=n;i>unique.size(); i--){
        s.insert(m[i].begin(), m[i].end());
    }
    for(int i=unique.size(); i > 0; i--){
        s.insert(m[i].begin(), m[i].end());
        if(s.size()>=2){
            ans[*s.begin()] = {i, -1};
            ans[*s.rbegin()] = {i, +1};
            s.erase(*s.begin());
            s.erase(*s.rbegin());
        }
    }
    int mx = unique.size();
    set<pii> li, ri;
    for(int i=0; i<n; i++){
        if(ans[i].S == -1){
            li.insert({-i,ans[i].F});
        }
        else if(ans[i].S == 1){
            ri.insert({i,ans[i].F});
        }
    }
    int val = 0;
    map<int,pii> mp;
    fo(i,n){
        if(ans[i].S==-1) mp[ans[i].F].F = i;
        else if(ans[i].S==1) mp[ans[i].F].S = i;    
    }
    for(int i = mx; i>=1 ;i--){
        bool erase = false;
        if(ri.lower_bound({mp[i].S, mx + 1}) != ri.end()){
            erase = true;
            
        }
        else if(li.lower_bound({-mp[i].F, mx + 1}) != li.end()){
            erase = true;

        }
        else{
            val += mp[i].S - mp[i].F;
        }
        li.erase({mp[i].F, i});
        ri.erase({mp[i].S, i});
        if(erase){
            mp.erase(i);
        }
    }
    for(auto [i,j]:mp){
        val += j.S - j.F;
    }
    cout<<val << endl;
    debug(ans);
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
