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
        string s;
        cin >> s;
        int map = 0;
        int pie = 0;
        int mapie = 0;
        fo(i, n)
        {
            if (i + 2 < n && s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p')
            {
                map++;
                if (i + 4 < n && s[i + 3] == 'i' && s[i + 4] == 'e')
                {
                    mapie++;
                }
            }
            else if (i + 2 < n && s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'e')
            {
                pie++;
            }
        }
        cout << map + pie - mapie << endl;
    }
}
