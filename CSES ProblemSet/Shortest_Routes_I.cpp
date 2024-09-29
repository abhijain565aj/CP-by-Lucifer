// Solution by Abhi Jain aka Lucifer aka abhijain565aj
// Mera solution kyun dekh rha?? ... (｡◕‿‿◕｡)

// Template maine nhi banaya he pura, codeforces pe dusro k solutions se inspired template he ...
// Kudos to them ❤

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

int main()
{
    ll n, m;
    cin >> n >> m;
    v(v(pll)) adj(n);
    ll a, b, c;
    fo(i, m)
    {
        cin >> a >> b >> c;
        a--, b--;
        adj[a].pb({b, c});
    }
    vl dist(n, -1);
    vb vis(n, false);
    dist[0] = 0;
    priority_queue<pll, v(pll), greater<pll>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto [d, v] = pq.top();
        pq.pop();
        if (vis[v])
            continue;
        vis[v] = true;
        for (auto [x, w] : adj[v])
        {
            if (dist[x] > dist[v] + w || dist[x] == -1)
            {
                dist[x] = dist[v] + w;
                pq.push({dist[x], x});
            }
        }
    }
    print_space(dist, n);
}
