// Solution by Abhi Jain aka Lucifer aka abhijain565aj
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
// find_by_order, order_of_key

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "./0_debug.cpp"
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define test(tt)
#define Error_file(x)
#endif

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

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define read(a, n) for (int i = 0; i < n; ++i) cin >> a[i];
#define print_space(a, n) for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');

string path;
v(vb) visited(9, vb(9, false));
bool checkWall(int i, int j)
{
    bool r1 = visited[i][j - 1] && visited[i][j + 1] && !visited[i - 1][j] && !visited[i + 1][j];
    bool r2 = visited[i - 1][j] && visited[i + 1][j] && !visited[i][j - 1] && !visited[i][j + 1];
    return r1 || r2;
}
ll dp(int i, int j, int cnt)
{
    if (i == 7 && j == 1)
    {
        if (cnt == 48) return 1;
        else return 0;
    }
    if(checkWall(i,j)) return 0;
    visited[i][j] = true;
    int res = 0;
    if ((path[cnt] == '?' || path[cnt] == 'U') && !visited[i - 1][j]){
        res += dp(i - 1, j, cnt+1);
        visited[i - 1][j] = false;
    }
    if ((path[cnt] == '?' || path[cnt] == 'D') && !visited[i + 1][j]){
        res += dp(i + 1, j, cnt+1);
        visited[i + 1][j] = false;
    }
    if ((path[cnt] == '?' || path[cnt] == 'L') && !visited[i][j - 1]){
        res += dp(i, j - 1, cnt+1);
        visited[i][j - 1] = false;
    }
    if ((path[cnt] == '?' || path[cnt] == 'R') && !visited[i][j + 1]){
        res += dp(i, j + 1,cnt+1);
        visited[i][j + 1] = false;
    }
    return res;
}
int main()
{
    fastio; Error_file("0_Error.txt");
    cin >> path;
    fo(i,9) visited[i][0] = visited[i][8] = visited[0][i] = visited[8][i] = true;
    cout << dp(1, 1, 0);
}
