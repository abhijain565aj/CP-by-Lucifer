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
ll funx(ll i, vl &p, ll m, ll sum, ll n)
{
    if (i == n)
    {
        return m;
    }
    else
    {
        ll a1 = funx(i + 1, p, m, sum, n);
        ll a2 = funx(i + 1, p, m - 2 * p[i], sum - p[i], n);
        ll ans = min(abs(a1), abs(a2));
        // if (ans == 0)
        // {
        //     cout << i << " " << m << " " << sum << " " << taken << "\n";
        // }
        return ans;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testCases = 1;
    // cin >> testCases;
    fo(t, testCases)
    {
        ll n;
        cin >> n;
        vl p(n);
        ll sum = 0;
        fo(i, n)
        {
            cin >> p[i];
            sum += p[i];
        }
        // cout << sum << endl;
        cout << funx(0, p, sum, sum, p.size());
    }
}
