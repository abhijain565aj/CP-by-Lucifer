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
#include "D:/CodeForces/0_debug.cpp"
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define test(tt)
#define printTC(tc)
#endif

// min_max functions
template <typename T>
T max3(T a, T b, T c)
{
    return max(a, max(b, c));
}
template <typename T>
T max4(T a, T b, T c, T d)
{
    return max(max(a, d), max(b, c));
}
template <typename T>
T min3(T a, T b, T c)
{
    return min(a, min(b, c));
}
template <typename T>
T min4(T a, T b, T c, T d)
{
    return min(min(a, d), min(b, c));
}

/*
|     /\     |  _ \  | |  | | |_   _| ( )          / ____|  / __ \  |  __ \  |  ____| |
|    /  \    | |_) | | |__| |   | |   |/   ___    | |      | |  | | | |  | | | |__    |
|   / /\ \   |  _ <  |  __  |   | |       / __|   | |      | |  | | | |  | | |  __|   |
|  / ____ \  | |_) | | |  | |  _| |_      \__ \   | |____  | |__| | | |__| | | |____  |
| /_/    \_\ |____/  |_|  |_| |_____|     |___/    \_____|  \____/  |_____/  |______| |
*/

struct Graph
{
    int V;
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> parent;
    vector<int> path;
    vector<int> orig;
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
        visited.resize(V, false);
        parent.resize(V, -1);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void makeGraph(int E)
    {
        int u, v;
        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            addEdge(u - 1, v - 1);
        }
    }
    void debugGraph()
    {
#ifndef ONLINE_JUDGE
        for (int i = 0; i < V; i++)
        {
            cerr << i << " -> ";
            for (int j : adj[i])
            {
                cerr << j << " ";
            }
            cerr << endl;
        }
#endif
    }
    vector<int> calculateDistance(int vertex)
    {
        vector<int> distance(V, 0);
        queue<int> q;
        q.push(vertex);
        distance[vertex] = 0;
        while (!q.empty())
        {
            int parent = q.front();
            q.pop();
            for (auto child : adj[parent])
            {
                if (distance[child] != -1)
                {
                    distance[child] = distance[parent] + 1;
                    q.push(child);
                }
            }
        }
        return distance;
    }
    void dfs(int vertex)
    {
        if (visited[vertex])
        {
            return;
        }
        path.pb(vertex);
        debug(vertex);
        visited[vertex] = true;
        debug(adj[vertex]);
        for (auto child : adj[vertex])
        {
            if (!visited[child])
            {
                parent[child] = vertex;
                dfs(child);
                path.pop_back();
            }
            else
            {
                if (parent[vertex] != child && orig.size() == 0)
                {
                    path.pb(child);
                    re(j, path.size())
                    {
                        orig.pb(path[j] + 1);
                        if (j != path.size() - 1 && path[j] == path[path.size() - 1])
                        {
                            break;
                        }
                    }
                    debug2(vertex, child);
                    debug2(parent[vertex], parent[child]);
                }
            }
        }
    }
    void bfs(int vertex)
    {
        queue<int> q;
        q.push(vertex);
        visited[vertex] = true;
        while (!q.empty())
        {
            int p = q.front();
            q.pop();
            for (auto child : adj[p])
            {
                if (!visited[child])
                {
                    visited[child] = true;
                    q.push(child);
                }
            }
        }
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    Graph g(n);
    g.makeGraph(m);
    fo(i, n)
    {
        g.dfs(i);
    }
    debug(g.parent);
    debug(g.orig);
    if (g.orig.size() == 0)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    cout << g.orig.size() << endl;
    for (auto x : g.orig)
    {
        cout << x << " ";
    }
}
/*
|   _____    ____    _____    ______     ______   _   _   _____     _____
|  / ____|  / __ \  |  __ \  |  ____|   |  ____| | \ | | |  __ \   / ____| |
| | |      | |  | | | |  | | | |__      | |__    |  \| | | |  | | | (___   |
| | |      | |  | | | |  | | |  __|     |  __|   | . ` | | |  | |  \___ \  |
| | |____  | |__| | | |__| | | |____    | |____  | |\  | | |__| |  ____) | |
|  \_____|  \____/  |_____/  |______|   |______| |_| \_| |_____/  |_____/  |
*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("D:/CodeForces/0_Error.txt", "w", stderr);
#endif
    int testCases = 1;
    // cin >> testCases;
    fo(tt, testCases)
    {
        test(tt + 1);
#ifndef ONLINE_JUDGE
        // printTC(tt + 1);
#endif
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "------------------------------------------\n";
#endif
}
