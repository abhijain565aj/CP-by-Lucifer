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
void solve()
{
    ll n;
    cin >> n;
    vl a(n);
    read(a, n);
    vl count(n + 1);
    vl ans;
    multiset<ll> s;
    set<ll> ins;
    queue<ll> q;
    vi maxindex(n + 1, -1);
    fo(i, n)
    {
        maxindex[a[i]] = i;
    }
    set<ll> order;
    fo(i, n)
    {
        if (maxindex[a[i]] == i)
            order.insert(i);
    }
    ll maxsize = order.size();
    fo(i, n)
    {
        if (ins.find(a[i]) == ins.end())
        {
            q.push(a[i]);
            s.insert(a[i]);
        }
        if (order.find(i) != order.end())
        {
            order.erase(i);
            if (s.find(a[i]) == s.end() && order.size() > 0)
            {
                continue;
            }
            ll removed;
            debug(a[i]);
            debug(s);
            debug(ins);
            debug(ans);

            while (true)
            {
                debug(s);
                if (s.empty())
                    break;
                if (ins.size() % 2 != 0)
                {
                    removed = *s.begin();
                    s.erase(removed);
                    ins.insert(removed);
                    ans.pb(removed);
                    debug(removed);
                    debug(s);
                    while (!q.empty() && q.front() != removed)
                    {
                        auto f = q.front();
                        auto it = s.find(f);
                        if (it != s.end())
                            s.erase(it);
                        q.pop();
                    }
                    if (q.front() == removed)
                        q.pop();
                }
                else
                {
                    removed = *s.rbegin();
                    s.erase(removed);
                    ins.insert(removed);
                    ans.pb(removed);
                    debug(removed);
                    debug(s);
                    while (!q.empty() && q.front() != removed)
                    {
                        auto f = q.front();
                        auto it = s.find(f);
                        if (it != s.end())
                            s.erase(it);
                        q.pop();
                    }
                    if (q.front() == removed)
                        q.pop();
                }
                debug2(removed, a[i]);
                if (removed == a[i] || ans.size() >= maxsize)
                    break;
            }
        }
    }
    cout << ans.size() << endl;
    print_space(ans, ans.size());
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
