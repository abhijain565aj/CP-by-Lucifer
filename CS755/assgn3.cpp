// Solution by Abhi Jain aka Lucifer aka abhijain565aj
#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> // find_by_order, order_of_key

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
#define nextL cout << "\n"

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

#define read(a, n)              \
    for (int i = 0; i < n; ++i) \
        cin >> a[i];
#define print_space(a, n)         \
    for (int i = 0; i < n; ++i)   \
        if (i == n - 1)           \
            cout << a[i] << "\n"; \
        else                      \
            cout << a[i] << ' ';
#ifndef ONLINE_JUDGE
#include "../0_debug.cpp"
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define test(tt)
#define printTC(tc)
#endif

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("0_Error.txt", "w", stderr);
#endif
    int n, m;
    cin >> n >> m;
    vvi adj1(n), adj0(n);
    fo(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 1)
            adj1[a].pb(b);
        if (c == 0)
            adj0[a].pb(b), adj0[b].pb(a);
    }
    debug2(adj1, adj0);
    vi vis(n, 0);
    vi arrival(n, 0);
    vi parents(n, -1);
    int time = 0;
    bool possible = true;
    v(pii) edges_directed;
    auto dfs = [&](auto &&dfs, int node, int parent) -> int
    {
        debug2(node, parent);
        vis[node] = 1;
        arrival[node] = time++;
        auto deepest = arrival[node];
        // join to make a single vector
        auto adj = adj1[node];
        adj.insert(adj.end(), adj0[node].begin(), adj0[node].end());
        for (auto child : adj)
        {
            if (child == parent)
                continue;
            if (vis[child] == 1)
            {
                deepest = min(deepest, arrival[child]);
            }
            else
            {
                parents[child] = node;
                deepest = min(dfs(dfs, child, node), deepest);
            }
        }
        // for (auto child : adj0[node])
        // {
        //     if (child == parent)
        //         continue;
        //     if (vis[child] == 1)
        //     {
        //         deepest = min(deepest, arrival[child]);
        //         if (arrival[child] < arrival[node])
        //             edges_directed.pb({node, child});
        //     }
        //     else
        //     {
        //         parents[child] = node;
        //         deepest = min(dfs(dfs, child, node), deepest);
        //         edges_directed.pb({node, child});
        //     }
        // }
        if (parents[node] != -1 && deepest >= arrival[node])
            possible = false;
        return deepest;
    };
    dfs(dfs, 0, -1);
    if (accumulate(all(vis), 0) != n)
        possible = false;
    if (!possible)
    {
        cout << "impossible\n";
        return 0;
    }
    else
    {
        cout << "possible\n";
        for (auto [x, y] : edges_directed)
            cout << x << ' ' << y << '\n';
        cout << '\n';
    }
}
