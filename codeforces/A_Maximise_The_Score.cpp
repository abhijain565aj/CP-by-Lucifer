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
        cin>>n;
        vector<ll> arr(2*n);
        fo(i,2*n){
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        ll sum=0;
        fo(i,n){
            sum +=arr[2*i];
        }
        cout<<sum<<endl;
    }
}