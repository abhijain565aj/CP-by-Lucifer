// Solution by Abhi Jain aka Lucifer aka abhijain565aj
// Mera solution kyun dekh rha?

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testCases = 1;
    cin >> testCases;
    fo(t, testCases)
    {
        int size;
        cin >> size;
        string s;
        cin >> s;
        int n = 0, d = 0;
        int e = 0, w = 0;
        fo(i, size)
        {
            if (s[i] == 'S')
                d++;
            else if (s[i] == 'N')
                n++;
            else if (s[i] == 'E')
                e++;
            else
                w++;
        }
        int x = (n - d) / 2;
        int y = (e - w) / 2;
        if ((abs(n - d) & 1) || (abs(e - w) & 1))
        {
            cout << "NO\n";
        }
        else if (x == 0 && y == 0 && n <= 1 && e <= 1 && n != e)
        {
            cout << "NO\n";
        }
        else
        {
            string ans = "";
            for (auto c : s)
            {
                if (c == 'S')
                {
                    if (x < 0)
                    {
                        ans += 'R';
                        x++;
                    }
                    else
                    {
                        ans += 'H';
                    }
                }
                else if (c == 'N')
                {
                    if (x > 0)
                    {
                        ans += 'R';
                        x--;
                    }
                    else
                    {
                        ans += 'H';
                    }
                }
                else if (c == 'W')
                {
                    if (y < 0)
                    {
                        ans += 'R';
                        y++;
                    }
                    else
                    {
                        ans += 'H';
                    }
                }
                else if (c == 'E')
                {
                    if (y > 0)
                    {
                        ans += 'R';
                        y--;
                    }
                    else
                    {
                        ans += 'H';
                    }
                }
            }
            x = abs(n - d);
            y = abs(e - w);
            if (x == 0 && y == 0)
            {
                if (n >= 1)
                {
                    ans[s.find("N")] = 'R';
                    ans[s.find("S")] = 'R';
                }
                else
                {
                    ans[s.find("E")] = 'R';
                    ans[s.find("W")] = 'R';
                }
            }
            cout << ans << endl;
        }
    }
}
