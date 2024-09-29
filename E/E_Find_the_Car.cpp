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
        ll n, k, q;
        cin >> n >> k >> q;
        vl a(k + 1);
        vl b(k + 1);
        a[0] = 0;
        b[0] = 0;
        fo(i, k)
        {
            cin >> a[i + 1];
        }
        fo(i, k)
        {
            cin >> b[i + 1];
        }
        fo(i, q)
        {
            ll x;
            cin >> x;
            auto a1 = lower_bound(all(a), x);
            auto a2 = upper_bound(all(a), x);
            // need corresponding b values
            int index = a1 - a.begin();
            if (*a1 != x)
            {
                index--;
            }
            ll ex;
            if (index == k)
            {
                ex = 0;
            }
            else
            {

                ex = ((x - a[index]) * (b[index + 1] - b[index])) / (a[index + 1] - a[index]);
            }
            ll ans = b[index] + ex;
            cout << ans << " ";
        }
        cout << endl;
    }
}
