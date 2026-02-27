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
        int n, k;
        cin >> n >> k;
        int b = n;
        fo(i, k)
        {
            if (b == 1)
            {
                b = 0;
            }
            b = b / 2 + b % 2;
        }
        if (b == 0)
        {
            cout << "-1" << endl;
        }
        else
        {
            vi a(n,0);
            int num = 1;
            int inc = 2;
            fo(i, k - 1)
            {
                int insert = inc / 2;
                while (insert < n)
                {
                    a[insert] = num;
                    num++;
                    insert += inc;
                }
                inc *= 2;
            }
            fo(i, n)
            {
                if (a[i] == 0)
                {
                    a[i] = num;
                    num++;
                }
            }
            fo(i, n)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
}
