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
        ll n;
        cin >> n;
        ll digit = 1;
        ll sub = 9;
        while (n - sub * digit > 0)
        {
            n -= sub * digit;
            digit++;
            sub *= 10;
        }
        ll digit_n = n % digit;
        n /= digit;
        ll p = 1;
        fo1(i, 1, digit)
        {
            p *= 10;
        }
        n += p - 1;
        ll ans;
        if (digit_n == 0)
        {
            ans = n % 10;
        }
        else
        {
            n += 1;
            re1(i, digit, digit_n + 1)
            {
                n /= 10;
            }
            ans = n % 10;
        }
        cout << ans << endl;
    }
}
