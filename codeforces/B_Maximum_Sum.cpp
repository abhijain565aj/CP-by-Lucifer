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
        ll g = 1000000007;
        ll n;
        cin >> n;
        ll k;
        cin >> k;
        vl a(n);
        ll netSum = 0;
        fo(i, n)
        {
            cin >> a[i];
            netSum = (netSum + a[i]) % g;
            netSum = (netSum + g) % g;
        }
        ll maxSum = 0;
        ll currentSum = 0;
        fo(i, n)
        {
            currentSum = max(a[i], a[i] + currentSum);
            maxSum = max(maxSum, currentSum);
        }
        ll m = maxSum;
        fo(i, k)
        {
            maxSum = (maxSum * 2) % g;
        }
        // cout << maxSum << " " << netSum << " " << m << " " << g << endl;
        ll ans = (maxSum % g + netSum % g - m % g + 2 * g) % g;
        cout << ans << endl;
    }
}
