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
    ll n,k;
    cin>>n>>k;
    vl p(n), d(n);
    read(p,n);
    read(d,n);
    // debug2(p,d);
    // vvl adj(n);
    // fo(i,n)fo1(j,i+1,n){
    //     if(((p[j] - p[i])%k) == (d[j]-d[i]+k)%k) adj[j].pb(i);
    // }
    // debug(adj);
    ll q;
    cin>>q;
    while(q--){
        ll pos;
        cin>>pos;
        ll up = lower_bound(all(p),pos)-p.begin();
        ll time = 0;
        bool possible = true;
        map<int,vi> vis;
        vis[1].resize(n,false);
        vis[-1].resize(n,false);
        int dir = 1;
        while(up<n && up>=0){
            time += abs(p[up]-pos);
            // debug2(pos,time);
            // debug2(up,p[up]);
            if(time%k==d[up]){
                if(vis[dir][up]){
                    possible = false;
                    break;
                }
                vis[dir][up] = true;
                dir *= -1;
            }
            pos = p[up];
            up+=dir;
        }
        YN(possible);
    }
}

int main()
{
    fastio;
    // rror_file("0_Error.txt");
    int testCases = 1;
    cin >> testCases;
    fo(tt, testCases){
        test(tt + 1);
        solve();
    }
    test(0);
}
