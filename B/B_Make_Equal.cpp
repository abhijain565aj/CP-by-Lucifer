#include <bits/stdc++.h>

using ll = long long int;
#define fo(i, n) for (int i = 0; i < n; i++)
#define pb push_back
using namespace std;
int main()
{
    int testCases;
    cin >> testCases;
    fo(t, testCases)
    {
        int n;
        cin >> n;
        ll arr[n];
        ll sum[n];
        fo(i, n)
        {
            cin >> arr[i];
            sum[i] = arr[i] + ((i > 0) ? sum[i - 1] : 0);
        }
        ll ans = sum[n - 1] / n;
        bool possible = true;
        ;
        fo(i, n)
        {
            if (sum[i] < ans * (i+1))
            {
                possible = false;
                break;
            }
        }
        if (possible)
        {
                cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}