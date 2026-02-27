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
        ll n, m;
        cin >> n >> m;
        ll r[4];
        cout << "? 1 1" << endl;
        cin >> r[0];

        ll c1, c2, r1, r2;

        r2 = min(r[0] + 1, m);
        r1 = r[0] + 2 - r2;

        c1 = min(r[0] + 1, n);
        c2 = r[0] + 2 - c1;

        cout << "? " << r1 << " " << r2 << endl;
        cin >> r[1];

        ll min = r[1] / 2;
        cout << "? " << r1 + min << " " << r2 - min << endl;
        cin >> r[2];
        
        if (r[2] == 0)
        {
            cout << "! " << r1 + min << " " << r2 - min << endl;
        }
        else
        {
            cout << "? " << c1 << " " << c2 << endl;
            cin >> r[3];
            ll min = r[3] / 2;
            cout << "! " << c1 - min << " " << c2 + min << endl;
        }
    }
}