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
        int arr[n];
        fo(i, n)
        {
            char c;
            cin >> c;
            arr[i] = c - '0';
        }
        fo(i, n)
        {
            arr[i] = arr[i] + ((i > 0) ? arr[i - 1] : 0);
        }
        int xtra = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (i != 0)
                arr[i - 1] += arr[i] / 10;
            else if (i == 0)
                xtra = arr[i] / 10;
            arr[i] = arr[i] % 10;
        }
        bool start = false;
        if (xtra)
        {
            cout << xtra;
            start = true;
        }
        fo(i, n)
        {
            if (arr[i] != 0 && !start)
                start = true;
            if (start)
                cout << arr[i];
        }
        cout << endl;
    }
}