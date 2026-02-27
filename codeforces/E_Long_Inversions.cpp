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
        int n;
        cin >> n;
        vi a(n, 0);
        char c;
        fo(i, n)
        {
            cin >> c;
            a[i] = c - '0';
        }
        int k = 2;
        for (k = 2; k <= n; k++)
        {
            int inv = 0;
            int cc = 0;
            int nc = 0;
            fo(i, n)
            {
                if (a[i] == c)
                {
                    inv++;
                    cc = 1 ^ cc;
                    nc = 0;
                }
                else
                {
                    nc++;
                }
                if (nc == k)
                {
                    cc = 1 ^ cc;
                    nc = 0;
                }
            }
            if (nc != k)
            {
                break;
            }
        }
        cout << endl;
    }
}
