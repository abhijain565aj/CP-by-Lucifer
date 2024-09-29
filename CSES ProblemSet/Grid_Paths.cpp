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
string path;
int ans;
int cnt;
v(vb) visited(7, vb(7, false));
bool check(int i, int j)
{
    return !(i < 0 || j < 0 || i >= 7 || j >= 7 || visited[i][j]);
}
bool checkWall(int i, int j)
{
    visited[i][j] = true;
    bool r1 = check(i, j - 1) && check(i, j + 1) && !check(i - 1, j) && !check(i + 1, j);
    bool r2 = check(i - 1, j) && check(i + 1, j) && !check(i, j - 1) && !check(i, j + 1);
    visited[i][j] = false;
    return r1 || r2;
}
int dp(int i, int j)
{
    if (i == 6 && j == 0)
    {
        if (cnt == 48)
            return 1;
        else
            return 0;
    }
    visited[i][j] = true;
    int res = 0;
    if ((path[cnt] == '?' || path[cnt] == 'U') && check(i - 1, j) && !checkWall(i - 1, j))
    {
        cnt++;
        res += dp(i - 1, j);
        visited[i - 1][j] = false;
        cnt--;
    }
    if ((path[cnt] == '?' || path[cnt] == 'D') && check(i + 1, j) && !checkWall(i + 1, j))
    {
        cnt++;
        res += dp(i + 1, j);
        visited[i + 1][j] = false;
        cnt--;
    }
    if ((path[cnt] == '?' || path[cnt] == 'L') && check(i, j - 1) && !checkWall(i, j - 1))
    {
        cnt++;
        res += dp(i, j - 1);
        visited[i][j - 1] = false;
        cnt--;
    }
    if ((path[cnt] == '?' || path[cnt] == 'R') && check(i, j + 1) && !checkWall(i, j + 1))
    {
        cnt++;
        res += dp(i, j + 1);
        visited[i][j + 1] = false;
        cnt--;
    }
    return res;
}
int main()
{
    cin >> path;
    ans = 0;
    cnt = 0;
    cout << dp(0, 0);
}
