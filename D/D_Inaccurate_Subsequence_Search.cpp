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
        int n, m, k;
        cin >> n >> m >> k;
        vi a(n);
        vi b(m);
        fo(i, n)
        {
            cin >> a[i];
        }
        fo(i, m)
        {
            cin >> b[i];
        }
        sortall(b);
        vector<bool> v(n, false);
        map<int, int> mp;
        fo(i, m)
        {
            if (mp.find(b[i]) == mp.end())
                mp[b[i]] = 1;
            else
            {
                mp[b[i]]++;
            }
        }
        // for (auto i : mp)
        // {
        //     cout << i.F << " " << i.S << endl;
        // }
        fo(i, n)
        {
            auto c = lower_bound(all(b), a[i]);
            if (c != b.end() && *c == a[i])
            {
                v[i] = true;
            }
        }
        vi dp(n - m + 1, 0);
        fo(i, m)
        {
            if (v[i])
            {
                mp[a[i]]--;
                if (mp[a[i]] >= 0)
                    dp[0]++;
            }
        }
        fo(i, n - m)
        {
            dp[i + 1] = dp[i];
            if (v[i])
            {
                mp[a[i]]++;
                if (mp[a[i]] > 0)
                    dp[i + 1]--;
            }
            if (v[i + m])
            {
                mp[a[i + m]]--;
                if (mp[a[i + m]] >= 0)
                    dp[i + 1]++;
            }
        }
        int ans = 0;
        // fo(i, n - m + 1)
        // {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        fo(i, n - m + 1)
        {
            if (dp[i] >= k)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
}
