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
        ll n;
        cin>>n;
        ll arr[n];
        ll sum = 0;
        fo(i,n){
            cin>>arr[i];
            sum += arr[i];
        }
        ll dec = sqrt(sum);
        if(dec*dec == sum){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}