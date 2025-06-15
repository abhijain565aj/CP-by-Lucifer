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
    ll n;
    cin >> n;
    debug(n);

    v(pll) pxy(n), pyx(n);
    fo(i, n) {
        cin >> pxy[i].F >> pxy[i].S;
        pyx[i].F = pxy[i].S;
        pyx[i].S = pxy[i].F;
    }
    if(n == 1){
        cout<<1 << endl;
        return;
    }
    sort(all(pxy));
    sort(all(pyx));
    set<pll> pts;
    pts.insert(pxy[0]);
    pts.insert(pxy[n-1]);
    pts.insert(pxy[1]);
    pts.insert(pxy[n-2]);
    pts.insert({pyx[0].S, pyx[0].F});
    pts.insert({pyx[n-1].S, pyx[n-1].F});
    pts.insert({pyx[1].S, pyx[1].F});
    pts.insert({pyx[n-2].S, pyx[n-2].F});
    ll ans = 1e18+10;
    debug2(pxy,pyx);
    debug(pts);
    for(auto p : pts){
        auto cp = pts;
        cp.erase(p);
        ll min_x = 1e18, max_x = -1e18;
        ll min_y = 1e18, max_y = -1e18;
        for(auto q : cp){
            min_x = min(min_x, q.F);
            max_x = max(max_x, q.F);
            min_y = min(min_y, q.S);
            max_y = max(max_y, q.S);
        }
        ll area = (max_x - min_x + 1) * (max_y - min_y + 1);
        if(area < n) area += min(max_x - min_x + 1, max_y - min_y + 1);
        ans = min(ans, area);
    }
    cout << ans << "\n";
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
