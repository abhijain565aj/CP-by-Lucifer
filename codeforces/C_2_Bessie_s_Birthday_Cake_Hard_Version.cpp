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
        ll n;
        cin >> n;
        ll x, y;
        cin >> x >> y;
        vi a(x);
        fo(i, x)
        {
            cin >> a[i];
        }
        sortall(a);
        ll ans = x - 2;
        vi diff;
        fo(i, x - 1)
        {
            if (a[(i + 1)] - a[i] == 2)
            {
                ans++;
            }
            else if (a[(i + 1)] - a[i] > 2)
            {
                diff.pb(a[i + 1] - a[i] - 1);
            }
        }
        if (n - a[x - 1] + a[0] == 2)
        {
            ans++;
        }
        else
        {
            diff.pb(n - a[x - 1] + a[0] - 1);
        }

        sort(all(diff));
        for (auto x : diff)
        {
            if (y >= x / 2 && x & 1)
            {
                y = y - x / 2;
                ans = ans + x;
            }
        }
        ans += 2 * y;
        ans = min(n - 2, ans);
        cout << ans << "\n";
    }
}
