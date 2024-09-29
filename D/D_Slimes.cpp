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
        ll a[n];
        fo(i, n)
        {
            cin >> a[i];
        }
        fo(i, n)
        {
            int turn = 0;
            ll leftS = 0;
            ll vleftS = 0;
            ll vrightS = 0;
            ll rightS = 0;
            ll leftM = 0;
            ll rightM = 0;
            while (true)
            {
                turn++;
                if (i - turn >= 0)
                {
                    leftS += a[i - turn];
                    if (a[i-turn] < vleftS || a[i-turn] > leftM)
                    {
                        vleftS = leftS;
                    }
                    leftM = max(a[i - turn], leftM);
                    if (vleftS > a[i])
                    {
                        cout << turn << " ";
                        break;
                    }
                }
                if (i + turn < n)
                {
                    rightS += a[i + turn];
                    if (a[i+turn] < rightS || a[i+turn] > rightM)
                    {
                        vrightS = rightS;
                    }
                    rightM = max(a[i + turn], rightM);
                    if (vrightS > a[i])
                    {
                        cout << turn << " ";
                        break;
                    }
                }
                if (i - turn < 0 && i + turn >= n){
                    cout << "-1 ";
                    break;
                }
            }
        }
        cout << endl;

    }
}