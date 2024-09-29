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
        int arr[n];
        fo(i, n){
            cin>>arr[i];
        }
        bool same = false;
        if(arr[0]==arr[n-1]){
            same = true;
        }
        int left = 0;
        fo(i,n){
            if(arr[i]!=arr[0]){
                break;
            }
            left++;
        }
        int right = 0;
        for(int i = n-1;i>=0;i--){
            if(arr[i]!=arr[n-1]){
                break;  
            }
            right++;
        }
        if(same)
        {
            int ans = n-left-right;
            ans = (ans>0)?ans:0;
            cout<<ans<<endl;
        }
        else{
            cout<<n-max(left,right)<<endl;
        }
    }
}