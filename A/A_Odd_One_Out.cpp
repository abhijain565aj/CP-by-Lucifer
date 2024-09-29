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
        int a;
        int b;
        int c;
        cin>>a>>b>>c;
        int d = a^b^c;
        cout<<d<<endl;
    }
}