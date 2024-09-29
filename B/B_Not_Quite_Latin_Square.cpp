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
        string a[3];
        fo(i,3){
            cin>>a[i];
        }
        char c = 3*('A' +'B' +'C')+'?'- (a[0][0]+a[1][0]+a[2][0]+a[0][1]+a[1][1]+a[2][1]+a[0][2]+a[1][2]+a[2][2]);
        cout<<c<<endl;
    }
}