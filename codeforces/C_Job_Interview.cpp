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
        int n, m;
        cin >> n >> m;
        vvl a(n + m + 1, vl(4, 0));
        fo(i, n + m + 1)
        {
            cin >> a[i][2];
        }
        fo(i, n + m + 1)
        {
            cin >> a[i][3];
            if (a[i][2] > a[i][3])
            {
                a[i][0] = 1;
            }
            else if (a[i][2] < a[i][3])
            {
                a[i][0] = -1;
            }
            else
            {
                a[i][0] = 0;
            }
            a[i][1] = i * a[i][0] * (-1);
        }
        sortall(a);
        fo(i, n + m + 1)
        {
            a[i][1] = abs(a[i][1]);
        }
        vl ans(n + m + 1, 0);
        ll sum_p = 0;
        ll sum_t = 0;
        fo1(i, m + 1, n + m + 1)
        {
            sum_p += a[i][2];
        }
        fo1(i, 1, m + 1)
        {
            sum_t += a[i][3];
        }
        ll score = sum_p + sum_t;
        fo(i, m)
        {
            ans[a[i][1]] = score;
            score -= a[i + 1][3];
            score += a[i][3];
        }
        fo1(i, m, n + m)
        {
            ans[a[i][1]] = score;
            score -= a[i + 1][2];
            score += a[i][2];
        }
        // for (auto x : a)
        // {
        //     cout << x[0] << " ";
        //     cout << x[1] << " ";
        //     cout << x[2] << " ";
        //     cout << x[3] << " ";
        //     cout << ans[x[1]];
        //     L;
        // }
        ans[a[n + m][1]] = score;
        for (auto x : ans)
        {
            cout << x << " ";
        }
        L;
    }
}
