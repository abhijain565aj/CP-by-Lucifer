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
int up(int n)
{
    return n / 2 + n % 2;
}
float abso(float x)
{
    if (x < 0)
    {
        return x * (-1);
    }
    else
        return x;
}
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
        vi a(n + 1, 0);
        fo1(i, 1, n + 1)
        {
            char c;
            cin >> c;
            if (c == '1')
                a[i] = 1;
        }
        // L;
        vi leftc(n + 1, 0);
        vi rightc(n + 1, 0);
        vector<float> perfect;
        fo1(i, 1, n + 1)
        {
            leftc[i] = leftc[i - 1] + ((a[i] == 0) ? 1 : 0);
            rightc[i] = rightc[i - 1] + ((a[i] == 1) ? 1 : 0);
            // cout << leftc[i] << " " << rightc[i] << endl;
        }
        fo1(i, 0, n + 1)
        {
            int sl = leftc[i];
            int sr = rightc[n] - rightc[i];
            int left = up(i);
            int right = up(n - i);
            // cout << sl << " " << sr << " " << left << " " << right << endl;
            if (sl >= left and sr >= right)
            {
                perfect.pb(i);
            }
        }
        float cent = float(n) / 2;
        float min = -10e7;
        for (auto x : perfect)
        {
            x = x - cent;
            // cout << x << " ";
            if (abso(x) < abso(min))
            {
                min = x;
            }
        }
        // cout << min << " " << cent;
        cout << min + cent << endl;
    }
}
