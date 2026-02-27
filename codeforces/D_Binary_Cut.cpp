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
        string s;
        cin >> s;
        int n = s.size();
        bool lasto = false;
        bool lastz = false;
        bool o1 = false;
        int ans = 0;
        fo(i, n)
        {
            if (s[i] == '1' && lasto == false)
            {
                lasto = true;
                lastz = false;
                ans++;
            }
            else if (s[i] == '0' && lastz == false)
            {
                lastz = true;
                lasto = false;

                ans++;
            }
            if (i + 1 < n && s[i] == '0' && s[i + 1] == '1' && o1 == false)
            {
                o1 = true;
                ans--;
            }
        }
        cout << ans << endl;
    }
}
