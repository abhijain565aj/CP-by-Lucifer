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
// a.resize(unique(all(a)) - a.begin());  -> unque element me convert karta hai
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testCases = 1;
    cin >> testCases;
    fo(t, testCases)
    {
        ll r;
        ll ans = 4;
        cin >> r;
        ll R = r * r;
        ll R1 = (r + 1) * (r + 1);
        // cout << R << " " << R1 << endl;
        for (ll i = 1; i < r + 1; i++)
        {
            ll a = i * i;
            ll a1 = sqrt(R1 - a);
            ll a2 = sqrt(R - a);
            if (a2 * a2 == R - a && a2 != 0)
            {
                ans += 4;
            }
            if (a1 * a1 == R1 - a && a1 != 0)
            {
                ans -= 4;
            }
            // cout << a << " " << a1 << " " << a2 << endl;
            ans += (a1 - a2) * 4;
        }
        cout << ans << endl;
    }
}
