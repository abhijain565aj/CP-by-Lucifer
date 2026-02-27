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

ll N = 1e18;
void solve()
{
    ll n, m, l;
    cin >> n >> m >> l;
    vl A(l);
    read(A, l);
    vvl adj(n);
    fo(i,m){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    debug(adj);
    vl dist_odd(n, INF);
    vl dist_even(n, INF);
    //dijkstra
    set<pair<pll, bool>> st;
    // bool is_odd flag
    st.insert({{0, 0}, 0});
    dist_even[0] = 0;
    while (!st.empty()) {
        auto it = st.begin();
        ll d = it->first.first;
        ll u = it->first.second;
        bool is_odd = it->second;
        st.erase(it);
        if (is_odd) {
            if (d > dist_odd[u]) continue;
            for (auto v : adj[u]) {
                if (dist_even[v] > d + 1) {
                    // Remove old entry if exists
                    if (dist_even[v] != INF)
                        st.erase({{dist_even[v], v}, 0});
                    dist_even[v] = d + 1;
                    st.insert({{dist_even[v], v}, 0});
                }
            }
        } else {
            if (d > dist_even[u]) continue;
            for (auto v : adj[u]) {
                if (dist_odd[v] > d + 1) {
                    // Remove old entry if exists
                    if (dist_odd[v] != INF)
                        st.erase({{dist_odd[v], v}, 1});
                    dist_odd[v] = d + 1;
                    st.insert({{dist_odd[v], v}, 1});
                }
            }
        }
    }
    debug2(dist_even,dist_odd)
    vl ans(n);
    ll max_dist = accumulate(all(A), 0ll);
    bool odd_flag = false;
    for(auto x: A){
        if(x%2 == 1) odd_flag = true;
    }
    ll min_odd = 1e18;
    for(auto x: A){
        if(x%2 == 1) min_odd = min(min_odd, x);
    }
    debug(max_dist);
    if(!odd_flag){
        fo(i,n) {
            if(dist_even[i] <= max_dist) ans[i] = 1;
            else ans[i] = 0;
        }
    }
    else{
        fo(i,n){
            if(dist_odd[i] <= max_dist){
                ans[i] = 1;
                ll diff = max_dist - dist_odd[i];
                if(diff%2==1 && diff < min_odd) ans[i] = 0;
            } 
            if(ans[i]==0 && dist_even[i] <= max_dist){
                ans[i] = 1;
                ll diff = max_dist - dist_even[i];
                if(diff%2==1 && diff < min_odd) ans[i] = 0;
            }
        }
    }

    string final_ans = "";
    for(auto x:ans) final_ans += to_string(x);
    cout << final_ans << endl;
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
