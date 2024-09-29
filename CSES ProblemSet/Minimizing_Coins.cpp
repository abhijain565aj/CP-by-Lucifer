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
        ll n;
        ll x;
        cin >> n >> x;
        vl c(n, 0);
        fo(i, n)
        {
            cin >> c[i];
        }
        vl dp(x + 1, 10e9);
        dp[0] = 0;
        fo(i, x + 1)
        {
            fo(j, n)
            {
                if (i - c[j] >= 0)
                {
                    dp[i] = min(dp[i], 1 + dp[i - c[j]]);
                }
            }
        }
        if (dp[x] == 10e9)
        {
            dp[x] = -1;
        }
        cout << dp[x] << endl;
    }
}
