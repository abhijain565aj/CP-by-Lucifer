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
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vi a(n);
    fo(i, n)
    {
        a[i] = s[i] - '0';
    }
    vi b(n);
    fo(i, n)
    {
        b[i] = t[i] - '0';
    }
    fo1(i, 1, n - 1)
    {
        if (a[i - 1] == 0 && a[i + 1] == 0 && b[i] == 0)
        {
            b[i] = 2;
        }
    }
    fo1(i, 1, n - 1)
    {
        if (b[i - 1] >= 1 && b[i + 1] >= 1 && a[i] == 0)
        {
            a[i] = 2;
        }
    }
    debug(a);
    debug(b);
    vl c(n + 1, 0); // c[i] = number of one till i-1 in a
    fo(i, n)
    {
        if (a[i] == 1)
            c[i + 1] = c[i] + 1;
        else
            c[i + 1] = c[i];
    }
    debug(c);
    vl d(n + 1, 0); // d[i] = number of 2 till i-1 in b
    fo(i, n)
    {
        if (a[i] == 2)
            d[i + 1] = d[i] + 1;
        else
            d[i + 1] = d[i];
    }
    debug(d);
    ll q;
    cin >> q;
    ll l, r;
    ll ans;
    while (q--)
    {
        cin >> l >> r;
        debug(l);
        debug(r);
        ans = c[r] - c[l - 1] + d[r] - d[l - 1];
        l--, r--;
        if (r - l < 3)
        {
            ans = 0;
            fo1(i, l, r + 1)
            {
                if (a[i] == 1)
                {
                    ans++;
                }
            }
            if (r - l == 2 && b[l] == 1 && b[r] == 1 && a[l + 1] == 2)
            {
                ans++;
            }
        }
        else
        {
            if (a[l] == 2)
            {
                ans--;
            }
            if (a[r] == 2)
            {
                ans--;
            }
            if (b[l] == 2 && a[l + 1] == 2)
            {
                ans--;
            }
            if (b[r] == 2 && a[r - 1] == 2)
            {
                ans--;
            }
        }
        debug(ans);
        cout << ans << endl;
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
