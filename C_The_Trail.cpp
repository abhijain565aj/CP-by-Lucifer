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
#include "./0_debug.cpp"
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
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vvl a(n, vl(m, 0)), b(n, vl(m, 0));
    fo(i, n) fo(j, m) cin >> a[i][j];
    vl sum_c(m, 0), sum_r(n, 0);
    vl count_c(m, 0), count_r(n, 0);
    fo(i, n) fo(j, m)
    {
        sum_r[i] += a[i][j];
        sum_c[j] += a[i][j];
    }
    ll x = 0, y = 0;
    b[x][y] = 1;
    count_r[x]++;
    count_c[y]++;
    pll ans = {1, (s[0] == 'D') ? sum_r[x] : sum_c[y]};
    fo(i, s.size() - 1)
    {
        if (s[i] == 'D')
            x++;
        else if (s[i] == 'R')
            y++;
        if (s[i + 1] == 'D')
        {
            a[x][y] = ans.S - sum_r[x];
            b[x][y] = ans.F - count_r[x];
            sum_c[y] += a[x][y];
            count_c[y] += b[x][y];
        }
        else if (s[i + 1] == 'R')
        {
            a[x][y] = ans.S - sum_c[y];
            b[x][y] = ans.F - count_c[y];
            sum_r[x] += a[x][y];
            count_r[x] += b[x][y];
        }
    }
    debug(a);
    debug(b);
    ll a1, b1, a2, b2;
    a1 = ans.S - sum_r[n - 1];
    b1 = ans.F - count_r[n - 1];
    a2 = ans.S - sum_c[m - 1];
    b2 = ans.F - count_c[m - 1];
    ll X = 0;
    if (b1 != b2)
    {
        X = (a1 - a2) / (b2 - b1);
    }
    fo(i, n) fo(j, m) a[i][j] += b[i][j] * X;
    int ans_sum = 0;
    fo(i, n) ans_sum += a[i][0];
    fo(i, n) ans_sum -= a[i][m - 1];
    a[n - 1][m - 1] = ans_sum;
    fo(i, n)
    {
        fo(j, m) cout << a[i][j] << ' ';
        cout << endl;
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
    freopen("0_Error.txt", "w", stderr);
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
