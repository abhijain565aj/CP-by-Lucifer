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
    vvl a(n);
    fo(i,n-1){
        int u,v;
        cin>>u>>v;
        a[u-1].pb(v-1);
        a[v-1].pb(u-1);
    }
    debug(a);
    vl sub_tree(n,0);
    vl distance(n,0);
    vl parent(n,-1);
    auto dfs = [&](auto&&dfs, int i)->void{
        sub_tree[i] = 1;
        for(auto j : a[i]){
            if(j==parent[i]) continue;
            distance[j] = distance[i]+1;
            parent[j] = i;
            dfs(dfs,j);
            sub_tree[i] += sub_tree[j];
        }
    };
    dfs(dfs,0);
    vl total_sub(n,0);
    fo(i,n) total_sub[distance[i]]+=sub_tree[i];
    debug(sub_tree);
    debug(distance);
    debug(total_sub);
    ll ans = 0;
    fo(i,n){
        ans += sub_tree[i]*(total_sub[distance[i]]-sub_tree[i]);
    }
    ll a2 = (n-1)*n;
    a2/=2;
    debug(a2);
    fo(i,n){
        a2 -= sub_tree[i]-1;
    }
    debug(a2);
    cout<<ans-a2<<endl;
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
