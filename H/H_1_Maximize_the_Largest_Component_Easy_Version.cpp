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
    cerr << "]";
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
    cerr << "]";
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
    cerr << "]";
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
    cerr << "]";
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
    int n, m;
    cin >> n >> m;
    vs s(n);
    read(s, n);
    v(vb) point(n + 2, vb(m + 2, false));
    fo1(i, 1, n + 1)
    {
        fo1(j, 1, m + 1)
        {
            if (s[i - 1][j - 1] == '#')
            {
                point[i][j] = true;
            }
        }
    }
    v(vb) done(n + 2, vb(m + 2, false));
    fo(i, n + 2)
    {
        done[i][0] = done[i][m + 1] = true;
    }
    fo(i, m + 2)
    {
        done[0][i] = done[n + 1][i] = true;
    }
    map<int, int> compSize;
    v(vi) comp(n + 2, vi(m + 2, 0));
    int current = 1;
    fo1(i, 1, n + 1)
    {
        fo1(j, 1, m + 1)
        {
            if (point[i][j] && !done[i][j])
            {
                queue<pii> q;
                q.push({i, j});
                done[i][j] = true;
                comp[i][j] = current;
                int size = 1;
                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int dx = -1; dx <= 1; dx++)
                    {
                        for (int dy = -1; dy <= 1; dy++)
                        {
                            if (dx == 0 && dy == 0)
                                continue;
                            if (dx != 0 && dy != 0)
                                continue;
                            if (point[x + dx][y + dy] && !done[x + dx][y + dy])
                            {
                                q.push({x + dx, y + dy});
                                done[x + dx][y + dy] = true;
                                comp[x + dx][y + dy] = current;
                                size++;
                            }
                        }
                    }
                }
                compSize[current] = size;
                current++;
            }
        }
    }
    debug(compSize);
    debug(point);
    debug(comp);
    int mx = 0;
    fo1(i, 1, n + 1)
    {
        set<int> s;
        int count = 0;
        fo1(j, 1, m + 1)
        {
            if (point[i][j] == 0)
            {
                count++;
            }
            s.insert(comp[i - 1][j]);
            s.insert(comp[i][j]);
            s.insert(comp[i + 1][j]);
        }
        for (auto x : s)
        {
            count += compSize[x];
        }
        debug(s);
        debug(count);
        mx = max(mx, count);
    }
    fo1(j, 1, m + 1)
    {
        set<int> s;
        int count = 0;
        fo1(i, 1, n + 1)
        {
            if (point[i][j] == 0)
            {
                count++;
            }
            s.insert(comp[i][j - 1]);
            s.insert(comp[i][j]);
            s.insert(comp[i][j + 1]);
        }
        for (auto x : s)
        {
            count += compSize[x];
        }
        debug(s);
        debug(count);
        mx = max(mx, count);
    }
    cout << mx << endl;
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
