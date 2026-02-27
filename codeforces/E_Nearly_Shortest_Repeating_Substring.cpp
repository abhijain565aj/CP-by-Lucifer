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
int comp(string &s, int k, string &s2, int a)
{
    int count = 0;
    fo(i, a)
    {
        if (s[i + k] != s2[i])
        {
            count++;
        }
        if (count > 1)
        {
            return 2;
        }
    }
    if (count == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool check(int a, int n, string &s)
{
    if (n % a != 0)
        return false;
    else
    {
        int count = 0;
        string s1 = s.substr(0, a);
        for (int i = a; i < n; i = i + a)
        {
            count += comp(s, i, s1, a);
            if (count >= 2)
            {
                break;
            }
        }
        if (count <= 1)
        {
            return true;
        }
        else
        {
            count = 0;
            string s2 = s.substr(n - a, a);
            for (int i = 0; i < n; i = i + a)
            {
                count += comp(s, i, s2, a);
                if (count >= 2)
                {
                    break;
                }
            }
            if (count <= 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
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
        string s;
        cin >> s;
        fo(i, n)
        {
            if (check(i + 1, n, s))
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }
}
