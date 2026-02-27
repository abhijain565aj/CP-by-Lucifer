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
        fo(i, n)
        {
            cin >> a[i];
        }
        bool possible = true;
        int max = 0;
        fo(i, n)
        {
            if (max > a[i])
            {
                possible = false;
                break;
            }
            else if (a[i] % 10 == 0)
            {
                max = a[i];
            }
            else if (a[i] % 10 != 0)
            {
                if (a[i] / 10 > a[i] % 10 || max > a[i] / 10)
                {
                    max = a[i];
                }
                else if (max <= a[i] / 10)
                {
                    max = a[i] % 10;
                }
                else
                {
                    possible = false;
                    break;
                }
            }
        }
        if (possible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
