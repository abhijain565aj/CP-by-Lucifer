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
        int n, c, d;
        cin >> n >> c >> d;
        vi arr(n * n);
        fo(i, n * n)
        {
            cin >> arr[i];
        }
        sortall(arr);
        vvi ans(n, vi(n));
        ans[0][0] = arr[0];
        fo1(i, 1, n)
        {
            ans[0][i] = ans[0][i - 1] + d;
        }
        fo(i, n)
        {
            fo1(j, 1, n)
            {
                ans[j][i] = ans[j - 1][i] + c;
            }
        }
        vi ans2(n * n);
        fo(i, n * n)
        {
            ans2[i] = ans[i / n][i % n];
        }
        sortall(ans2);
        if (ans2 == arr)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}
