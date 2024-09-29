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
int cmp(string &s, int n1, int n2, int n)
{
    fo1(i, n1, n2)
    {
        if (n2 - n1 + i < n && s[i] != s[n2 - n1 + i] && s[i] != '?' && s[n2 - n1 + i] != '?')
        {
            // cout << i;
            return 0;
        }
        else if (n2 - n1 + i >= n)
        {
            return 0;
        }
    }
    return (n2 - n1) * 2;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testCases = 1;
    cin >> testCases;
    fo(t, testCases)
    {
        string s;
        cin >> s;
        int n = s.size();
        int csize = 0;
        int maxsize = 0;

        fo(i, n)
        {
            int m = maxsize / 2;
            cout << i << " " << i + m + 1 << "\n";
            fo1(j, i + m + 1, n + 1 - maxsize / 2)
            {
                csize = cmp(s, i, j, n);
                maxsize = max(maxsize, csize);
            }
        }
        // cout << cmp(s, 2, 4, n) << endl;
        cout << maxsize << endl;
    }
}
