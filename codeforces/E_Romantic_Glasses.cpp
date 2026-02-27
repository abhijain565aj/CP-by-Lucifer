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
        cin >>n;
        ll arr[n];
        ll sum[n];
        fo(i,n){
            cin>>arr[i];
            sum[i]=(i-2>=0)?sum[i-2]+arr[i]:arr[i];
        }
        
    }
}