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
        int n;
        cin >> n;
        vvi a(3, vi(n));
        vi b(n + 1, 0); // change size to n+1
        vi c(n + 1, 0); // change size to n+1
        fo(i, 3)
        {
            fo(j, n)
            {
                cin >> a[i][j];
                if (a[i][j] > 0 && a[i][j] < n + 1) // check if index is valid
                {
                    b[a[i][j]]++;
                }
                else if (a[i][j] < 0 && a[i][j] > -n - 1) // check if index is valid
                {
                    c[-a[i][j]]++; // use -a[i][j] as index
                }
            }
        }
        int sum = 0;
        fo(i, n)
        {
            sum += max(b[i + 1], c[i + 1]); // change to i+1
        }
        if (sum >= 2 * n)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n"; // add missing code
        }
    }
    return 0;
}
