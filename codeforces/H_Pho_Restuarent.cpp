#include <bits/stdc++.h>

using ll = long long int;
#define fo(i, n) for (int i = 0; i < n; i++)
#define pb push_back
using namespace std;
int main()
{
    int n;
    cin >> n;
    string arr[n];
    int num1[n] = {0};
    int num0[n] = {0};
    fo(i, n)
    {
        cin >> arr[i];
        for (int j = 0; arr[i][j] != '\0'; j++)
        {
            if (arr[i][j] == '1')
            {
                num1[i]++;
            }
            else
            {
                num0[i]++;
            }
        }
    }
    int ans = 0;
    fo(i, n)
        ans += min(num1[i], num0[i]);
    int m = INT_MAX;
    fo(i, n)
        m = min(m, num0[i] - num1[i]);
    if (m > 0)
        ans += m;
    int m1 = INT_MAX;
    fo(i, n)
        m1 = min(m1, num1[i] - num0[i]);
    if (m1 > 0)
        ans += m1;
    cout << ans << endl;
}