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
        int arr[5]={15,10,6,3,1};
        ll n;
        cin>>n;
        int coins=0;
        int i=0;
        int a[5]={0};
        while(n>0){
            a[i] = n/arr[i];
            coins += a[i];
            n = n%arr[i];
            i++;
        }
        // fo(i,5){
        //     cout<<a[i]<<" ";
        // }
        if(a[0]>0&&a[3]>0&&a[4]==2){
            coins -= 2;
        }
        else if(a[0]>0&&a[2]>0&&a[4]==2){
            coins--;
        }
        else if(a[1]>0&&a[4]==2){
            coins--;
        }
        cout<<coins<<endl;
    }
}