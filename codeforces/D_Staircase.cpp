// Solution by Abhi Jain aka Lucifer aka abhijain565aj
// Mera solution kyun dekh rha?

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

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
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testCases = 1;
    cin >> testCases;
    fo(t, testCases)
    {
        int n;
        cin >> n;
        vi a(n);
        fo(i, n)
        {
            cin >> a[i];
        }
        vector<pii> b;
        int j = 0;
        int oldBroken = false;
        fo(i, n)
        {
            if (oldBroken)
            {
                if (a[i])
                {
                    b.back().S++;
                }
                else
                {
                    oldBroken = false;
                }
            }
            else
            {
                if (a[i])
                {
                    b.pb({i, 1});
                    oldBroken = true;
                }
            }
        }
        ll ans = 0;
        for (auto x : b)
        {
            if (x.S & 1)
            {
                int exc_i = x.F;
                int max = 0;
                for (int i = x.F; i < x.F + x.S; i += 2)
                {
                    if (max < a[i])
                    {
                        max = a[i];
                        exc_i = i;
                    }
                }
                for (int i = x.F; i < x.F + x.S; i++)
                {
                    if (i != exc_i)
                    {
                        ans += 2 * (a[i] + a[i + 1]);
                        i++;
                    }
                }
                ans += a[exc_i];
            }
            else
            {
                fo(i, x.S)
                {
                    ans += 2 * (a[x.F + i] + a[x.F + i + 1]);
                    i++;
                }
            }
        }
        cout << ans << endl;
    }
}
