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
void solve(int n1, int n2, int n, vector<vi> &num, vector<vi> &p, vector<vi> &c)
{
    if (c[n1][n2] != 1)
    {
        c[n1][n2] = 1;
        p[n1][n2] = 1;
        if (n2 + 1 < n)
        {
            p[n1][n2 + 1] = 1;
            int n3 = n2 + 1 + num[n1][n2 + 1];
            solve(n1, n3, n, num, p, c);
        }
        if (n2 - 1 >= 0)
        {
            p[n1][n2 - 1] = 1;
            int n3 = n2 - 1 + num[n1][n2 - 1];
            solve(n1, n2 - 1 + num[n1][n2 - 1], n, num, p, c);
        }
        int n4 = (n1 + 1) % 2;
        int n3 = n2 + num[n4][n2];
        p[n4][n2] = 1;
        solve(n4, n3, n, num, p, c);
    }
    return;
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
        string s1;
        string s2;
        cin >> s1 >> s2;
        vvi num(2, vi(n, 0));
        fo(i, n)
        {
            if (s1[i] == '>')
            {
                num[0][i] = 1;
            }
            else
            {
                num[0][i] = -1;
            }
            if (s2[i] == '<')
            {
                num[1][i] = -1;
            }
            else
            {
                num[1][i] = 1;
            }
        }

        vvi p(2, vi(n, 0));
        vvi c(2, vi(n, 0));
        solve(0, 0, n, num, p, c);
        if (p[1][n - 1] == 1)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}
