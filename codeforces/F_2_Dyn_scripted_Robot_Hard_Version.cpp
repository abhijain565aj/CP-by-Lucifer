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
// Modular Arithmetic
ll mod(ll a, ll m = MOD)
{
    return (a % m + m) % m;
}
ll add(ll a, ll b, ll m = MOD)
{
    return mod(a + b, m);
}
ll sub(ll a, ll b, ll m = MOD)
{
    return mod(a - b, m);
}
ll mul(ll a, ll b, ll m = MOD)
{
    return mod(a * b, m);
}
ll power(ll a, ll b, ll m = MOD)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = mul(res, a, m);
        a = mul(a, a, m);
        b >>= 1;
    }
    return res;
}
ll inv(ll a, ll m = MOD)
{
    return power(a, m - 2, m);
}
ll div(ll a, ll b, ll m = MOD)
{
    return mul(a, inv(b, m), m);
}
ll abinv(ll a, ll b, ll m = MOD)
{
    return mul(a, inv(b % m, m), m);
}
void solve()
{
    ll n, k, w, h;
    cin >> n >> k >> w >> h;
    string s;
    cin >> s;
    ll xsum = 0, ysum = 0;
    w = 2 * w;
    h = 2 * h;
    map<pll, ll> mp;
    fo(i, n)
    {
        if (s[i] == 'L' || s[i] == 'R')
        {
            xsum += (s[i] == 'L') ? -1 : 1;
        }
        else
        {
            ysum += (s[i] == 'U') ? 1 : -1;
        }
        xsum = (xsum + w) % w;
        ysum = (ysum + h) % h;
        pll p = {xsum, ysum};
        mp[p]++;
    }
    debug(mp);
    debug2(xsum, ysum);
    ll answer = 0;
    for (auto [p, v] : mp)
    {
        debug(p);
        ll X = w - p.F;
        ll Y = h - p.S;
        // i*xsum = x mod w;, i*ysum = y mod h;
        ll gcd1 = __gcd(xsum, w);
        if (X % gcd1 != 0)
            continue;
        ll gcd2 = __gcd(ysum, h);
        if (Y % gcd2 != 0)
            continue;
        gcd1 = max(gcd1, 1LL);
        gcd2 = max(gcd2, 1LL);
        debug2(gcd1, gcd2);
        debug2(X, Y);
        X = X / gcd1;
        Y = Y / gcd2;
        ll h1 = h / gcd2, w1 = w / gcd1;
        ll ans1 = (xsum) ? abinv(X, xsum / gcd1, w1) : 0;
        ll ans2 = (ysum) ? abinv(Y, ysum / gcd2, h1) : 0;
        //i = ans1 modw1, i = ans2 mod h1;
        ll a = mul(ans1, ans2);
        answer += max(k * v - (a * v) / (h1 * w1), 0LL);
        debug2(ans1, ans2);
        debug(answer);
        cerr << endl;
    }
    cout << answer << endl;
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
