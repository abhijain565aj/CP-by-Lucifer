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
        ll k, x, a;
        cin >> k >> x >> a;

        ll sum = 0;
        ll current = 1;
        bool possible = true;
        fo(i, x)
        {

            sum = sum + current;
            if (current * k <= sum)
            {
                sum = sum - current;
                current = (sum) / (k - 1) + 1;
                sum = sum + current;
            }
            ll left = a - sum;
            if (left * (k - 1) <= sum)
            {
                possible = false;
                cout << "NO";
                break;
            }
        }

        if (possible)
        {
            cout << "YES";
        }
        cout << endl;
    }
}