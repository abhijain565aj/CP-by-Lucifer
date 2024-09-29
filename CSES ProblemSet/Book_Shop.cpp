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
    // cin >> testCases;
    fo(t, testCases)
    {
        int n;
        int x;
        cin >> n >> x;
        vi book(n, 0);
        vi pages(n, 0);
        fo(i, n)
        {
            cin >> book[i];
        }
        fo(i, n)
        {
            cin >> pages[i];
        }
        vi ans(x + 1, 0);
        vector<vector<bool>> check(x + 1, vector<bool>(n, false));
        int a = 0;
        fo(i, x + 1)
        {
            ans[i] = 0;
            fo(j, n)
            {
                if (i - book[j] >= 0 && !check[i - book[j]][j])
                {
                    if (ans[i] < pages[j] + ans[i - book[j]])
                    {
                        ans[i] = pages[j] + ans[i - book[j]];
                        check[i] = check[i - book[j]];
                        check[i][j] = true;
                    }
                }
            }
            a = max(a, ans[i]);
            // cout << ans[i] << " ";
        }
        cout << a << "\n";
    }
}
