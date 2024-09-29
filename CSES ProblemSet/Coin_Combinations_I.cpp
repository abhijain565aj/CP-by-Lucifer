// Solution by Abhi Jain aka Lucifer aka abhijain565aj
// Mera solution kyun dekh rha?

#include <bits/stdc++.h>

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

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testCases = 1;
    // cin >> testCases;
    fo(t, testCases)
    {
        ll a = 1000000007;
        int n;
        int x;
        cin >> n >> x;
        vl coins(n, 0);
        fo(i, n)
        {
            cin >> coins[i];
        }
        vl dp(x + 1, 0);
        dp[0] = 1;
        fo(i, x + 1)
        {
            fo(j, n)
            {
                if (i - coins[j] >= 0)
                {
                    dp[i] += dp[i - coins[j]];
                }
            }
            // cout << dp[i] << " ";
            dp[i] %= a;
        }
        cout << dp[x] % a << endl;
    }
}
