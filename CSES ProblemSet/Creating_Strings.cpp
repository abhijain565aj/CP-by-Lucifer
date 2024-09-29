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
void funx(vi &a, vector<string> &b, string add, int n)
{
    fo(i, 26)
    {
        if (a[i] > 0)
        {
            a[i]--;
            char c = 'a' + i;
            if (n == 1)
            {
                b.pb(add + c);
            }
            else
            {
                funx(a, b, add + c, n - 1);
            }
            a[i]++;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testCases = 1;
    // cin >> testCases;
    fo(t, testCases)
    {
        string s;
        cin >> s;
        int n = s.size();
        vi a(26, 0);
        fo(i, n)
        {
            a[s[i] - 'a']++;
        }
        vector<string> b;
        funx(a, b, "", n);
        cout << b.size() << "\n";
        for (auto x : b)
        {
            cout << x << "\n";
        }
    }
}
