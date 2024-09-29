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
        vector<pll> a(n);
        fo(i, n)
        {
            cin >> a[i].F;
            a[i].S = i;
        }
        sortall(a);
        vl a1(n);
        vl sum(n);
        sum[0] = a[0].F;
        fo1(i, 1, n)
        {
            sum[i] = sum[i - 1] + a[i].F;
        }
        fo(i, n)
        {
            a1[i] = a[i].F - ((i > 0) ? sum[i - 1] : 0);
        }
        vi q;
        vi answer(n);
        fo1(i, 1, n + 1)
        {
            if (a1[i] <= 0 && i != n)
            {
                q.pb(a[i - 1].S);
            }
            else
            {
                answer[a[i - 1].S] = i - 1;
                for (auto x : q)
                {
                    answer[x] = i - 1;
                }
                q.clear();
            }
        }
        fo(i, n)
        {
            cout << answer[i] << " ";
        }
        L;
    }
}
