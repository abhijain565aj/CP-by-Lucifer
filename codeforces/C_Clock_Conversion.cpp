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
        string s;
        cin >> s;
        int hr = (s[0] - '0') * 10 + (s[1] - '0');
        if (hr >= 12)
        {
            hr = hr - 12;
            s[0] = '0' + hr / 10;
            s[1] = '0' + hr % 10;
            s = s + " PM";
        }
        else
        {
            s = s + " AM";
        }
        if (s[0] == '0' and s[1] == '0')
        {
            s[0] = '1';
            s[1] = '2';
        }
        cout << s << endl;
    }
}
