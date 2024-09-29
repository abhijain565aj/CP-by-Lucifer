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
// Function to perform modular exponentiation
// It returns (base^exp) % mod
int n;
ll mod_exp(ll base, ll exp, ll mod = MOD)
{
    ll result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        { // If exp is odd
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

// Function to calculate pq^-1 % MOD
ll modDiv(ll p, ll q, ll mod = MOD)
{
    p = p % mod;
    ll q_inv = mod_exp(q, mod - 2); // Fermat's Little Theorem
    ll ans = (p * q_inv) % mod;
    return ans;
}

void solve()
{
    cin >> n;
    int k;
    cin >> k;
    vl a(n);
    read(a, n);
    if (n == k)
    {
        cout << accumulate(all(a), 0LL) % MOD << " " << 0 << endl;
        return;
    }
    ll specialSum = accumulate(a.begin(), a.begin() + k, 0LL);
    ll remainingSum = accumulate(a.begin() + k, a.end(), 0LL);
    ll n1 = n - k;
    if (n1 & 1)
    {
        ll a1 = modDiv(specialSum, 2LL);
        ll a2 = modDiv(remainingSum, n - k);
        ll ans1 = (a1 + a2 * (n1 / 2LL + n1 % 2LL)) % MOD;
        ll ans2 = (a1 + a2 * (n1 / 2LL)) % MOD;
        cout << ans1 << " " << ans2 << endl;
    }
    else
    {
        ll a1 = modDiv(remainingSum, 2LL);
        ll a2 = modDiv(specialSum, n1 + 1LL);
        ll ans1 = (a1 + a2 * (n1 / 2LL + 1LL)) % MOD;
        ll ans2 = (a1 + a2 * (n1 / 2LL)) % MOD;
        cout << ans1 << " " << ans2 << endl;
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
