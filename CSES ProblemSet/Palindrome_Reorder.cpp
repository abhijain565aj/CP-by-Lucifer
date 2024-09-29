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
    // cin >> testCases;
    fo(t, testCases)
    {
        string s;
        cin >> s;
        vi a(26, 0);
        int n = s.size();
        fo(i, n)
        {
            a[s[i] - 'A']++;
        }
        int oddc = 0;
        int oddi = 0;
        fo(i, 26)
        {
            if (a[i] & 1)
            {
                oddc++;
                oddi = i;
                a[i]--;
            }
        }
        if (oddc <= 1)
        {
            if (oddc == 1)
            {
                s[n / 2] = 'A' + oddi;
            }
            int pt = 0;
            fo(i, 26)
            {
                fo(j, a[i] / 2)
                {
                    s[pt] = 'A' + i;
                    s[n - 1 - pt] = 'A' + i;
                    pt++;
                }
            }
            cout << s;
        }
        else
        {
            cout << "NO SOLUTION\n";
        }
    }
}
