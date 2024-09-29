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
int index(char a)
{
    return (a - 'a') + 1;
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
        int answer = abs(index(s[0]) - index(s[n - 1]));
        vi jumps;
        if (index(s[0]) > index(s[n - 1]))
        {
            for (int i = index(s[0]); i >= index(s[n - 1]); i--)
            {
                fo(j, n)
                {
                    if (index(s[j]) == i)
                    {
                        jumps.pb(j + 1);
                    }
                }
            }
        }
        else
        {
            for (int i = index(s[0]); i <= index(s[n - 1]); i++)
            {
                fo(j, n)
                {
                    if (index(s[j]) == i)
                    {
                        jumps.pb(j + 1);
                    }
                }
            }
        }
        cout << answer << " " << jumps.size() << "\n";
        for (auto j : jumps)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
