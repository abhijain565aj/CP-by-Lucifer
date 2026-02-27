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
        char arr[3];
        if (n / 26)
        {

            if (n == 27)
            {
                arr[2] = 'y';
                n = n - 25;
            }
            else if (n == 26)
            {
                arr[2] = 'x';
                n = n - 24;
            }
            else
            {
                arr[2] = 'z';
                n = n - 26;
            }
        }
        else
        {
            arr[0] = 'a';
            arr[1] = 'a';
            arr[2] = n - 3 + 'a';
        }
        if (n / 26)
        {
            if (n / 26 == 2)
            {
                arr[0] = 'z';
                arr[1] = 'z';
            }
            if (n % 26 != 0)
            {
                if (n % 26 != 0)
                {
                    arr[1] = 'z';
                    arr[0] = n % 26 + 'a'-1;
                }
            }
            else if (n/26 == 1)
            {
                arr[0] = 'a';
                arr[1] = 'y';
            }
        }
        else if (arr[0]!='a')
        {
            arr[0] = 'a';
            arr[1] = n - 2 + 'a';
        }
        fo(i, 3)
        {
            cout << arr[i];
        }
        cout << "\n";
    }
}