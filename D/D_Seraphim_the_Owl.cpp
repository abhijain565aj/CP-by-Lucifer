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
    cin >> testCases;
    fo(t, testCases)
    {
        int n, m;
        cin >> n >> m;
        vl a(n);
        vl b(n);
        fo(i, n)
        {
            cin >> a[i];
        }
        fo(i, n)
        {
            cin >> b[i];
        }
        vl bsum(n, 0);
        re(i, n)
        {
            bsum[i] = b[i] + ((i != n - 1) ? bsum[i + 1] : 0);
        }
        // fo(i, n)
        // {
        //     cout << bsum[i] << " ";
        // }
        // L;
        vl dp(n);
        vector<ll> cp;
        fo(i, n)
        {
            if (a[i] < b[i])
            {
                cp.pb(i);
            }
        }
        // for (auto x : cp)
        // {
        //     cout << x << " ";
        // }
        // L;
        dp[n - 1] = a[n - 1];
        re1(i, n - 2, 0)
        {
            // cout << i << " he\n";
            auto j = lower_bound(all(cp), i + 1);
            // cout << *j << " \n";
            dp[i] = a[i] + bsum[i + 1];
            if (j != cp.end())
            {
                // cout << "Ya" << *j << "\n";
                dp[i] += dp[*j] - bsum[*j];
            }
        }
        // fo(i, n)
        // {
        //     cout << dp[i] << " ";
        // }
        // L;
        ll ans = dp[m - 1];
        fo(i, m)
        {
            if (ans > dp[i])
            {
                ans = dp[i];
            }
        }
        cout << ans << "\n";
    }
}
