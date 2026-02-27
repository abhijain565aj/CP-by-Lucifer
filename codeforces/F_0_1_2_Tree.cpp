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
        int a, b, c;
        cin >> a >> b >> c;
        if (c == a + 1)
        {
            int n = 0;
            int p = 1;
            while (a - p > 0)
            {
                a = a - p;
                p = p * 2;
                n++;
            }
            int height = n;
            int rem = p - a;
            if (rem >= b)
            {
                c = c + b - rem;
                rem = b;
                b = 0;
            }
            else
            {
                b = b - rem;
            }
            int slots = a * 2 + rem * 1;
            // cout << height << " " << a << " " << b << " " << c << " " << rem << " " << slots << endl;
            if (b + c != 0)
            {
                height = height + (b + c) / slots;
                if ((b + c) % slots != 0)
                {
                    height++;
                }
            }
            cout << height;
        }
        else
        {
            cout << -1;
        }
        cout << endl;
    }
}
