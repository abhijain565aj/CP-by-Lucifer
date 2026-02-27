#include <iostream>
// #include<string>
// #include<algorithm>
// #include<cmath>
// #include<vector>
// #include <bits/stdc++.h>

using ll = long long int;
#define fo(i, n) for (int i = 0; i < n; i++)
#define swap(a, b) \
    {              \
        a ^= b;    \
        b ^= a;    \
        a ^= b;    \
    }

#define pb push_back
using namespace std;
int main()
{
    int testCases;
    cin >> testCases;
    fo(t, testCases)
    {
        int x;
        int n;
        cin >> x >> n;
        int m = x / n;
        int n_copy = n;
        while (!(x % m == 0 && x / m >= n_copy))
        {
            m = min(m-1,x/n);
            n++;
        }
        cout << m << endl;
    }
}