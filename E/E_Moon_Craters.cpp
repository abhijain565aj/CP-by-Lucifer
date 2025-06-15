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
ll INF = 1e18;

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
    cin >> n;
    v(pll) a(n);
    map<pll, ll> mp;
    fo(i, n) {
        int c,r;
        cin >> c >> r;
        a[i] = {c - r, c + r};
        mp[a[i]] = i+1;
    }
    sort(all(a));
    map<pll,ll> dp;
    map<pll,pll> dp2;
    map<pll, ll> dp3;
    auto fn = [&](auto &&fn,v(pll)&arr, ll l, ll r) -> ll{
        debug2(l, r);
        if(l>=r) return 0;
        if(dp.find({l,r})!=dp.end()) return dp[{l,r}];
        ll l1 = upper_bound(all(arr), make_pair(l,-INF)) - arr.begin();
        ll r1 = lower_bound(all(arr), make_pair(r,INF)) - arr.begin();
        v(pll) b;
        ll inc = 0;
        fo1(i,l1,r1){
            if(arr[i].F==l && arr[i].S==r) {
                inc = 1;
                dp3[{l,r}] = mp[arr[i]];
            }
            else if(arr[i].F >= l && arr[i].S <= r) {
                b.pb(arr[i]);
            }
        }
        ll ans = 0;
        pll max_p = {0, 0};
        for(auto &p : b){
            if(ans<fn(fn, b, l, p.F) + fn(fn, b, p.S, r) + fn(fn, b, p.F, p.S)){
                ans = fn(fn, b, l, p.F) + fn(fn, b, p.S, r) + fn(fn, b, p.F, p.S);
                max_p = p;
            }
        }
        if(max_p != make_pair(0ll, 0ll)) {
            dp2[{l,r}] = max_p;
        }
        return dp[{l,r}] = inc+ans;
    };
    debug(a);
    fn(fn, a, -INF, INF);
    pll p = {-INF, INF};
    vl ans;
    queue<pll> q;
    q.push(p);
    while(!q.empty()){
        pll curr = q.front();
        q.pop();
        if(dp[curr] == 0) continue;
        if(dp3.find(curr) != dp3.end()) {
            ans.pb(dp3[curr]);
        }
        if(dp2.find(curr) == dp2.end()) continue;
        pll next = dp2[curr];
        q.push({curr.F, next.F});
        q.push({next.S, curr.S});
        q.push({next.F, next.S});
    }
    sort(all(ans));
    cout << ans.size() << endl;
    for(auto &x : ans) {
        cout << x << " ";
    }
    debug(dp);
}

int main()
{
    fastio; 
    // Error_file("0_Error.txt");
    int testCases = 1;
    // cin >> testCases;
    fo(tt, testCases){
        test(tt + 1);
        solve();
    }
    test(0);
}
