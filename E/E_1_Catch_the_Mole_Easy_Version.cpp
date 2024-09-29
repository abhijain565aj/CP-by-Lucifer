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
        {                         \
            cout << a[i] << "\n"; \
        }                         \
        else                      \
        {                         \
            cout << a[i] << ' ';  \
        }

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

#ifndef ONLINE_JUDGE
#define debug2(x, y)          \
    cerr << #x << " ";        \
    _print(x);                \
    cerr << " " << #y << " "; \
    _print(y);                \
    cerr << endl;
#else
#define debug2(x, y)
#endif

#ifndef ONLINE_JUDGE
#define debug3(x, y, z)       \
    cerr << #x << " ";        \
    _print(x);                \
    cerr << " " << #y << " "; \
    _print(y);                \
    cerr << " " << #z << " "; \
    _print(z);                \
    cerr << endl;
#else
#define debug3(x, y, z)
#endif

#ifndef ONLINE_JUDGE
#define test(tt) \
    cerr << "------------------------------------------\nCase #" << tt << ": \n";
#else
#define test(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.F);
    cerr << ",";
    _print(p.S);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]\n";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]\n";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]\n";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]\n";
}
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

void printTC(int tt) { cout << "------------------------------------------\nCase #" << tt << ": \n"; }

/*
|     /\     |  _ \  | |  | | |_   _| ( )          / ____|  / __ \  |  __ \  |  ____| |
|    /  \    | |_) | | |__| |   | |   |/   ___    | |      | |  | | | |  | | | |__    |
|   / /\ \   |  _ <  |  __  |   | |       / __|   | |      | |  | | | |  | | |  __|   |
|  / ____ \  | |_) | | |  | |  _| |_      \__ \   | |____  | |__| | | |__| | | |____  |
| /_/    \_\ |____/  |_|  |_| |_____|     |___/    \_____|  \____/  |_____/  |______| |
*/
void solve()
{
    int n;
    cin >> n;
    // int current;
    // cin >> current;
    vvi a(n + 1);
    fo(i, n - 1)
    {
        int x, y;
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    debug(a);
    // apply bfs to calculate parent of each node
    vi dist(n + 1, -1);
    vi parent(n + 1, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int child : a[node])
        {
            if (dist[child] == -1)
            {
                dist[child] = dist[node] + 1;
                q.push(child);
                parent[child] = node;
            }
        }
    }
    vi size(n + 1, 1);
    function<void(int, int)> dfs = [&](int node, int par)
    {
        for (int child : a[node])
        {
            if (child != par)
            {
                dfs(child, node);
                size[node] += size[child];
            }
        }
    };
    dfs(1, -1);
    vi parents;
    int current_parent = 1;
    while (true)
    {
        parents.pb(current_parent);
        if (a[current_parent].size() == 2 && current_parent != 1)
        {
            for (auto child : a[current_parent])
            {
                if (child != parent[current_parent])
                {
                    current_parent = child;
                    break;
                }
            }
            continue;
        }
        else if (a[current_parent].size() == 1 && current_parent != 1)
        {
            break;
        }
        bool found = false;
        auto comp = [&](int x, int y)
        { return size[x] > size[y]; };
        sort(all(a[current_parent]), comp);
        for (auto child : a[current_parent])
        {
            if (child == parent[current_parent])
                continue;
            cout << "? " << child << endl;
            int reply;
            cin >> reply;
            if (reply == 1)
            {
                found = true;
                current_parent = child;
                break;
            }
        }
        if (!found)
        {
            break;
        }
    }
    debug(parents);
    int len = parents.size();
    int l1 = len / 2;
    while (true)
    {
        cout << "? " << parents[l1] << endl;
        int reply;
        cin >> reply;
        if (reply == 1)
        {
            len /= 2;
            if (len == 1)
            {
                if (l1 + 1 >= parents.size())
                {
                    cout << "! " << parents[l1] << endl;
                    return;
                }
                cout << "? " << parents[l1 + 1] << endl;
                cin >> reply;
                if (reply == 1)
                {
                    cout << "! " << parents[l1 + 1] << endl;
                }
                else
                {
                    cout << "! " << parents[l1 - 1] << endl;
                }
                return;
            }
            l1 += len / 2;
        }
        else if (reply == 0)
        {
            parents.erase(parents.end() - l1, parents.end());
            len = parents.size();
            l1 = len / 2;
        }
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
    cin >> testCases;
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
