// Solution by Abhi Jain aka Lucifer aka abhijain565aj
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> // find_by_order, order_of_key

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
    ll n;
    cin>>n;
    vl a(n);
    read(a, n);
    debug(a);
    ll notans = 0;
    fo1(i,1,11){
        vl b(n);
        fo(j,n){b[j] = (a[j]>i) - (a[j]<=i);}
        vl presum(n+1);
        fo(j,n) presum[j+1] = presum[j] + b[j];
        map<ll,ll> mp;
        fo(j,n+1) mp[presum[j]]++;
        for(auto [x,y]:mp){
            notans += y*(y-1)/2;
        }

        //remove ranges which dont have i
        vvi ranges;
        ranges.pb({});
        fo(j,n) {
            if(a[j] == i) {
                ranges.pb({});
            } else {
                ranges.back().pb(a[j]);
            }
        }
        for(auto r:ranges){
            vl b(r.size());
            fo(j,r.size()) b[j] = (r[j]>i) - (r[j]<=i);
            vl presum(r.size()+1);
            fo(j,r.size()) presum[j+1] = presum[j] + b[j];
            map<ll,ll> mp;
            fo(j,r.size()+1) mp[presum[j]]++;
            for(auto [x,y]:mp){
                notans -= y*(y-1)/2;
            }
        }
        debug(mp);
        debug(notans);
    }
    ll ans = n*(n+1)/2 - notans;
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
