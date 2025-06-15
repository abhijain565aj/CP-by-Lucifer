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

int S_MAX = 50000;
v(pii) mmp(S_MAX + 1, {0, 0});
void draw(ll p, ll s) {
    debug2(p, s);
    ll xtra = (p - mmp[s].F)/2;
    v(pll) ans;
    vb corner;
    ll sq = static_cast<ll>(floor(sqrt(s)));
    if(sq * sq == s) sq--;
    ll s1 = s;
    for(ll i=0;i<=sq;i++){
        for(int j=0;j<=sq&&s1>0;j++,s1--){
            if(j==0) corner.pb(true);
            else corner.pb(false);
            ans.pb({i, j});
        }
    }
    v(pii) xtra_arr;
    int ct = 0;
    fo(i,xtra){
        while(corner.back()){
            corner.pop_back();
            ans.pop_back();
            xtra_arr.pb({0, -ct - 1});
            ct++;
        }
        corner.pop_back();
        ans.pop_back();
        xtra_arr.pb({0,-ct-1});
        ct++;
    }
    for(auto [x, y] : ans) {
        cout << x << " " << y << "\n";
    }
    for(auto [x, y] : xtra_arr) {
        cout << x << " " << y << "\n";
    }
}
void solve(){
    ll p,s;
    cin >> p >> s;
    ll gcd = __gcd(p, s);
    p /= gcd, s /= gcd;
    for(int i=1;i<=S_MAX;i++){
        if(i%s) continue;
        ll p1 = p * (i / s);
        if(p1%2) continue;
        if(p1>=mmp[i].F && p1<=mmp[i].S){
            cout << i << endl;
            draw(p1, i);
            return;
        }
    }
    cout<<-1<<endl;
}

int main()
{
    fastio; 
    // Error_file("0_Error.txt");
    set<ll> s;
    map<ll, pll> rec;
    for(ll i=1;i<=1000;i++){
        s.insert(i*i);
        rec[i*i] = {i, i};
    }
    for(ll i=1;i<=1000;i++){
        s.insert(i*(i+1));
        rec[i*(i+1)] = {i, i+1};
    }
    for(ll i=1;i<=S_MAX;i++){
        if(i%1000==0){
            debug(i);
        }
        ll ind = *lower_bound(all(s), i);
        mmp[i].F = 2*(rec[ind].F + rec[ind].S);
        mmp[i].S = 2*i+2;
    }
    // debug(mmp);
    int testCases = 1;
    cin >> testCases;
    fo(tt, testCases){
        solve();
    }
}
