#include <iostream>
// #include<string>
// #include<algorithm>
// #include<cmath>
// #include<vector>
// #include <bits/stdc++.h>

using ll = long long int;
#define fo(i, n) for (int i = 0; i < n; i++)
#define swap(a, b) { a ^= b; b ^= a; a ^= b; }

#define pb push_back
using namespace std;
int main()
{
    int testCases;
    cin >> testCases;
    fo(t, testCases)
    {
        int n;
        int m;
        cin >> n >> m;
        int rows = m/2;
        cout<<n*rows<<endl;
    }
}