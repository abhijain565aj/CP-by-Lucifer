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
        int arr[n];
        ll x,y;
        cin>>x,y;
        fo(i,n){
            cin>>arr[i];
        }
        int xmod[x]={0};
        int ymod[y]={0};
        fo(i,n){
            xmod[arr[i]%x]++;
            ymod[arr[i]%y]++;
        }
        ll ans=0;
        fo(i,x){
            
        }
    }
}