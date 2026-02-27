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
        char c;
        string s;
        cin >> n >> c >> s;
        int currTime = 0;
        bool count = false;
        int maxTime = 0;
        fo(j, 2)
        {
            fo(i, n)
            {
                if (count)
                {
                    currTime++;
                }
                if (s[i] == c)
                {
                    count = true;
                }
                if (s[i] == 'g')
                {
                    maxTime = max(currTime, maxTime);
                    count = false;
                    currTime = 0;
                }
            }
        }
        cout << maxTime << "\n";
    }
}
