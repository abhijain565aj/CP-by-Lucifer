// Solution by Abhi Jain aka Lucifer aka abhijain565aj
// Mera solution kyun dekh rha?

#include <bits/stdc++.h>

using ll = long long int;
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define L cout << "\n"

#define fo(i, n) for (int i = 0; i < n; i++)
#define re(i, n) for (int i = n - 1; i >= 0; i--)
#define fo1(i, a, b) for (int i = a; i <= b; i++)
#define fo2(i, a, b) for (int i = a; i >= b; i--)

#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define F first
#define S second
#define pb push_back

using namespace std;
ll pr(ll n)
{
    return (n) * (n + 1) / 2;
}
ll as(ll n, ll c)
{
    return ((n + 1) / 2 + (1 + n) % 2 + c - n + 1);
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
        ll c;
        cin >> n >> c;
        vl arr(n);
        fo(i, n)
        {
            cin >> arr[i];
        }
        ll pairs = pr(c + 1); // 0 included
        ll even = 0;
        ll odd = 0;
        fo(i, n)
        {
            pairs -= as(arr[i], c);
            // if (i < 10)
                // cout << pairs << " ";
            if (arr[i] & 1)
                odd++;
            else
                even++;
        }
        pairs += pr(even);
        pairs += pr(odd);
        cout << pairs << endl;
    }
}
