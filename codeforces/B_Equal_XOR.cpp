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
        int n;
        int k;
        cin >> n >> k;
        k *= 2;
        int n1 = n * 2;
        int a[n1];
        fo(i, n1)
        {
            cin >> a[i];
        }
        int count[n + 1] = {0};
        fo(i, n)
        {
            count[a[i]]++;
        }
        int l[k] = {0};
        int r[k] = {0};
        int i = 1;
        int k2 = k;
        int k1 = k;
        while (i <= n && k > 1)
        {

            if (count[i] == 2)
            {
                l[--k] = i;
                l[--k] = i;
            }
            i++;
        }
        i = 1;
        while (k > 0)
        {
            if (count[i] == 1)
            {
                l[--k] = i;
                r[--k1] = i;
            }
            i++;
        }
        int j = 1;
        while (k1 > 0)
        {
            if (count[j] == 0)
            {
                r[--k1] = j;
                r[--k1] = j;
            }
            j++;
        }

        fo(i, k2)
        {
            cout << l[i] << " ";
        }
        L;
        fo(i, k2)
        {
            cout << r[i] << " ";
        }
        L;
    }
}
