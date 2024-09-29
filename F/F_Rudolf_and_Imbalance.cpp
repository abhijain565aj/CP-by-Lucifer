// Solution by Abhi Jain aka Lucifer aka abhijain565aj
// Mera solution kyun dekh rha?

#include <bits/stdc++.h>

using ll = long long int;
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define L cout << "\n"

#define fo(i, n) for (int i = 0; i < n; i++)
#define re(i, n) for (int i = n - 1; i >= 0; i--)
#define fo1(i, a, b) for (int i = a; i < b; i++)
#define fo2(i, a, b) for (int i = a; i >= b; i--)

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
        vl a(n);
        vi d(m);
        vi f(k);
        fo(i, n)
        {
            cin >> a[i];
        }
        fo(i, m)
        {
            cin >> d[i];
        }
        fo(i, k)
        {
            cin >> f[i];
        }
        ll max1 = 0, max2 = 0;
        int p=0;
        fo(i, n - 1)
        {
            if (a[i + 1] - a[i] > max1)
            {
                max2 = max1;
                max1 = a[i + 1] - a[i];
                p = i;
            }
            else if (a[i + 1] - a[i] > max2)
            {
                max2 = a[i + 1] - a[i];
            }
        }
        // cout << max1 << " " << max2;
        sortall(d);
        sortall(f);
        int cen = (a[p] + a[p + 1]) / 2;
        // cout << cen << " ";
        int mink = INT_MAX;
        int ans;
        fo(i, m)
        {
            int ser = cen - d[i];
            vi::iterator it = lower_bound(all(f), ser);
            // cout << k << " ";
            if (it != f.end())
            {
                if (mink > *it - ser)
                {
                    mink = *it - ser;
                    ans = mink + cen;
                }
            }
            if (it != f.begin())
            {
                it--;
                // cout << k << " ";
                if (mink > ser - *it)
                {
                    mink = ser - *it;
                    ans = cen - mink;
                }
            }
            // cout << mink << "\n";
        }
        // cout << mink << " ";
        if (ans < a[p + 1] && a[p] < ans)
        {
            cout << max(max2, max(ans - a[p], a[p + 1] - ans)) << "\n";
        }
        else
        {
            cout << max1 << "\n";
        }
    }
}
