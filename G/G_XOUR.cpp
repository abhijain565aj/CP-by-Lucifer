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
        ll n;
        cin >> n;
        vl a(n);
        map<ll, vector<int>> mp;
        fo(i, n)
        {
            cin >> a[i];
            int rem = a[i] % 4;
            if (mp.count(a[i] >> 2) == 0)
            {
                mp[a[i] >> 2] = vector<int>(4, 0);
            }
            mp[a[i] >> 2][rem]++;
        }
        // for (auto x : mp)
        // {
        //     cout << x.first << " ";
        //     for (auto y : x.second)
        //     {
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }
        fo(i, n)
        {
            int a1 = a[i] >> 2;
            auto m1 = mp[a1];
            int val = 0;
            fo(i, 4)
            {
                if (m1[i])
                {
                    mp[a1][i]--;
                    val = i;
                    break;
                }
            }

            cout << a1 * 4 + val << " ";
        }
        cout << endl;
    }
}
