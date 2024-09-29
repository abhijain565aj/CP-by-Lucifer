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
        string s1, s2;
        cin >> s1 >> s2;
        int s1_val = 0;
        int n = s1.size();
        fo(i, n)
        {
            if (s1[i] == 'X')
            {
                s1_val += 1;
            }
            else if (s1[i] == 'L')
            {
                s1_val += 2;
            }
            else if (s1[i] == 'S')
            {
                s1_val *= -1;
                s1_val -= 1;
            }
        }
        int s2_val = 0;
        n = s2.size();
        fo(i, n)
        {
            if (s2[i] == 'X')
            {
                s2_val += 1;
            }
            else if (s2[i] == 'L')
            {
                s2_val += 2;
            }
            else if (s2[i] == 'S')
            {
                s2_val *= -1;
                s2_val -= 1;
            }
        }
        if (s1_val < s2_val)
        {
            cout << "<\n";
        }
        else if (s1_val > s2_val)
        {
            cout << ">\n";
        }
        else
        {
            cout << "=\n";
        }
    }
}
