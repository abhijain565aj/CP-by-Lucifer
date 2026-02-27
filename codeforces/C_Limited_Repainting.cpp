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
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vi a(n);
    read(a,n);
    vector<pair<int,char>> b;
    int i=0;
    for(;i<n;i++) if(s[i]=='B') break;
    if(i<n){
        b.pb({a[i],s[i]});
        fo1(j,i+1,n){
            if(s[j]==s[j-1]) b.back().F = max(a[j],b.back().F);
            else b.pb({a[j],s[j]});
        }
        if(b.back().S=='R') b.pop_back();     
    }
    if(b.size()/2+1<=k){
        cout<<0<<endl;
        return;
    }
    set<pii> blue;
    set<pii> red;
    vi s(b.size());
    for(int i=0;i<b.size();i++){
        s[i] = b[i].F;
        ((b[i].S=='R')?red:blue).insert({s[i],i});
    }
    int ans = 0;
    vb fix(b.size(),false);
    while(k){
        fix[b.rbegin()->S] = true;
        blue.erase(*b.rbegin());
        k--;
    }
    vi max_red(b.size(),-1);
    for(int i=0;i<b.size();i+=2) if(fix[i]) max_red[i] = 0;
    for(int i=2; i<b.size();i+=2){
        if(max_red[i-2]!=-1){
            max_red[i] = max(max_red[i-2],b[i-1].F);
        }
    }
    for(int i=b.size()-3;i>=0;i--){
        if(max_red[i+2]!=-1){
            max_red[i] = min(max_red[i],max(max_red[i+2],b[i-1].F));
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans,min(max_red[i],b[i]->F));
    }
    cout<<ans<<endl;
}

int main()
{
    fastio; 
    Error_file("0_Error.txt");
    int testCases = 1;
    cin >> testCases;
    fo(tt, testCases){
        test(tt + 1);
        solve();
    }
    test(0);
}
