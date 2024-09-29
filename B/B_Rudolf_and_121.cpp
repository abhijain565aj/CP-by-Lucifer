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
        int n;
        cin >> n;
        vl a(n);
        fo(i, n)
        {
            cin >> a[i];
        }
        bool possible = true;
        fo(i, n - 2)
        {
            // cout << a[i] << " ";
            if (a[i] < 0)
            {
                possible = false;
                break;
            }
            a[i + 1] -= 2 * a[i];
            a[i + 2] -= a[i];
            a[i] = 0;
        }
        if (a[n - 1] != 0 || a[n - 2] != 0)
        {
            possible = false;
        }
        if (possible)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}
