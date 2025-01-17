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
#include "./0_debug.cpp"
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define test(tt)
#define printTC(tc)
#endif

/*
|     /\     |  _ \  | |  | | |_   _| ( )          / ____|  / __ \  |  __ \  |  ____| |
|    /  \    | |_) | | |__| |   | |   |/   ___    | |      | |  | | | |  | | | |__    |
|   / /\ \   |  _ <  |  __  |   | |       / __|   | |      | |  | | | |  | | |  __|   |
|  / ____ \  | |_) | | |  | |  _| |_      \__ \   | |____  | |__| | | |__| | | |____  |
| /_/    \_\ |____/  |_|  |_| |_____|     |___/    \_____|  \____/  |_____/  |______| |
*/
ll n;
vvl a;
vector<unordered_map<ll, ll>> dp;
vb good;
int total_good = 0;
ll dfs(ll node, ll parent)
{
    if (dp[parent].count(node))
        return dp[parent][node];
    else if (dp[node].count(parent))
    {
        dp[parent][node] = total_good - dp[node][parent];
        return dp[parent][node];
    }
    ll ans = 0;
    for (auto x : a[node])
    {
        if (x != parent)
        {
            ans += dfs(x, node);
        }
    }
    if (good[node])
        ans++;
    return dp[parent][node] = ans;
};
void solve()
{
    cin >> n;
    a.clear();
    a.resize(n);
    dp.clear();
    dp.resize(n);
    good.resize(n);
    fo(i, n - 1)
    {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        a[x].pb(y);
        a[y].pb(x);
    }
    debug(a);
    unordered_set<ll> leave;
    fo(i, n)
    {
        if (a[i].size() == 1)
            leave.insert(i);
    }
    ll lc = leave.size();
    ll ans = lc * (n - lc);
    debug(ans);
    vb leaf_connected(n, 0);
    for (auto x : leave)
    {
        for (auto y : a[x])
            leaf_connected[y] = true;
    }
    debug(leaf_connected);
    total_good = 0;
    fo(i, n)
    {
        if (leaf_connected[i] || a[i].size() == 1)
            good[i] = false;
        else
        {
            good[i] = true;
            total_good++;
        }
    }
    debug(good);
    fo(i, n)
    {
        if (a[i].size() > 1)
        {
            for (auto x : a[i])
            {
                if (leaf_connected[x])
                    ans += dfs(x, i);
            }
        }
    }
    debug(dp);
    cout << ans << endl;
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
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("./0_Error.txt", "w", stderr);
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
