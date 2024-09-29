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
vl pow2(21);
void pre()
{
    pow2[0] = 1;
    fo1(i, 1, 21)
    {
        pow2[i] = pow2[i - 1] * 2;
    }
}
void solve()
{
    ll n;
    cin >> n;
    ll q;
    cin >> q;
    vl parent(n + 1, -1);
    parent[1] = -1;
    fo1(i, 2, n + 1)
    {
        cin >> parent[i];
    }
    vl perm(n + 1);
    fo1(i, 1, n + 1)
    {
        cin >> perm[i];
    }
    ll k = 0;
    ll n1 = n;
    while (n1)
    {
        n1 /= 2;
        k++;
    }
    ll a = 1;
    vl depth(n + 1, -1);
    depth[1] = 0;
    fo1(i, 2, n + 1)
    {
        ll p = parent[i];
        depth[i] = depth[p] + 1;
    }
    map<ll, ll> mp;
    fo1(i, 1, n + 1)
    {
        mp[perm[i + 1]] = i;
    }

    function<bool(ll)>
        check = [&](ll u) -> bool
    {
        if (u == 1)
            return perm[u] == 1;
        else
        {
            if (check(parent[u]))
                return (mp[u] == mp[parent[u]] + 1) || (mp[u] == mp[parent[u]] + pow2[k - depth[u]]);
            else
                return false;
        }
    };

    set<ll> s;
    fo1(i, 1, n + 1)
    {
        if (!check(i))
        {
            s.insert(i);
        }
    }
    function<void(ll)> checkChilds = [&](ll ind)
    {
        if (ind * 2 > n)
        {
            return;
        }
        debug(ind);
        ll ch1 = ind * 2;
        ll ch2 = ind * 2 + 1;
        if ((mp[ch1] - mp[ind] == 1) || (mp[ch1] == mp[ind] + pow2[k - depth[ind] - 1]))
        {
            s.erase(ch1);
            checkChilds(ch1);
        }
        else
        {
            s.insert(ch1);
        }
        if ((mp[ch2] - mp[ind] == 1) || (mp[ch2] == mp[ind] + pow2[k - depth[ind] - 1]))
        {
            s.erase(ch2);
            checkChilds(ch2);
        }
        else
        {
            s.insert(ch2);
        }
    };

    while (q--)
    {
        ll u, v;
        cin >> u >> v;
        swap(perm[u], perm[v]);
        swap(mp[perm[u]], mp[perm[v]]);
        debug(mp);
        debug(perm);
        debug(s);
        if (check(perm[u]))
        {
            s.erase(perm[u]);
            checkChilds(perm[u]);
        }
        else
        {
            s.insert(perm[u]);
            // checkChilds(perm[u]);
        }
        if (check(perm[v]))
        {
            s.erase(perm[v]);
            checkChilds(perm[v]);
        }
        else
        {
            s.insert(perm[v]);
            // checkChilds(perm[u]);
        }
        debug(s);
        YN(s.empty());
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
    pre();
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
