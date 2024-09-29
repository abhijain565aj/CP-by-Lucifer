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
    // cin >> testCases;
    fo(t, testCases)
    {
        int n;
        cin >> n;
        vi a1;
        vi a2;
        if (n % 4 == 1 || n % 4 == 2)
        {
            cout << "NO";
            continue;
        }
        else if (n % 4 == 3)
        {
            a1.pb(1);
            a2.pb(3);
            a1.pb(2);
            fo1(i, 4, n + 1)
            {
                a1.pb(i);
                a1.pb(i + 3);
                a2.pb(i + 1);
                a2.pb(i + 2);
                i += 3;
            }
        }
        else
        {
            fo1(i, 1, n)
            {
                a1.pb(i);
                a1.pb(i + 3);
                a2.pb(i + 1);
                a2.pb(i + 2);
                i += 3;
            }
        }
        cout << "YES\n";
        cout << a1.size() << endl;
        for (auto x : a1)
            cout << x << " ";
        cout << endl;
        cout << a2.size() << endl;
        for (auto x : a2)
            cout << x << " ";
        cout << endl;
    }
}
