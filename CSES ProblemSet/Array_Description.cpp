// Solution by Abhi Jain aka Lucifer aka abhijain565aj
// Mera solution kyun dekh rha?

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

using ll = long long int;
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define L cout << "\n"

#define fo(i, n) for (int i = 0; i < n; i++)
#define re(i, n) for (int i = n - 1; i >= 0; i--)
#define fo1(i, a, b) for (int i = a; i < b; i++)
#define re1(i, a, b) for (int i = a; i >= b; i--)

#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define F first
#define S second
#define pb push_back
#define MOD 1000000007
// a.resize(unique(all(a)) - a.begin());  -> unque element me convert karta hai

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testCases = 1;
    // cin >> testCases;
    fo(t, testCases)
    {
        int n, m;
        cin >> n >> m;
        vl a(n);
        fo(i, n)
        {
            cin >> a[i];
        }
        vvl dp(n, vl(m + 2, 0));
        if (a[0] == 0)
        {
            fo1(i, 1, m + 1)
            {
                dp[0][i] = 1;
            }
        }
        else
        {
            dp[0][a[0]] = 1;
        }
        fo1(i, 1, n)
        {
            if (a[i] != 0)
            {
                dp[i][a[i]] = (dp[i - 1][a[i] - 1] + dp[i - 1][a[i]] + dp[i - 1][a[i] + 1]) % MOD;
            }
            else
            {
                fo1(j, 1, m + 1)
                {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
                }
            }
        }
        // fo(i, n)
        // {
        //     fo(j, m + 2)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        ll ans = 0;
        fo(i, m + 1)
        {
            ans = (ans + dp[n - 1][i]) % MOD;
        }
        cout << ans;
    }
}
