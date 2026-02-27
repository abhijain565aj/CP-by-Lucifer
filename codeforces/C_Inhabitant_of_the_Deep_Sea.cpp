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
        ll n, k;
        cin >> n >> k;
        vl arr(n);
        fo(i, n)
        {
            cin >> arr[i];
        }
        int f = 0;
        int l = n - 1;
        int ans = 0;
        while (k > 0 && ans != n)
        {
            if (l == f)
            {
                if (arr[f] <= k)
                {
                    ans++;
                }
                break;
            }
            if (k == 2 * arr[f] - 1 && arr[l] >= arr[f] && f != l)
            {
                ans++;
                break;
            }
            else if (k < 2 * min(arr[f], arr[l]))
            {
                break;
            }
            if (arr[f] < arr[l])
            {

                k -= 2 * arr[f];
                arr[l] = arr[l] - arr[f];
                ans++;
                f++;
            }
            else if (arr[f] > arr[l])
            {
                k -= 2 * arr[l];
                arr[f] = arr[f] - arr[l];
                ans++;
                l--;
            }
            else
            {
                k -= 2 * arr[f];
                ans += 2;
                f++;
                l--;
            }
        }
        cout << ans << endl;
    }
}
