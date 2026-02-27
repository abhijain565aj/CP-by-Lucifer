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
        cin >> n;
        vector<ll> arr(n);
        fo(i, n)
        {
            cin >> arr[i];
        }
        int a = pow(2,31)-1;
        int l = 0; 
        int r =n-1;
        sort(arr.begin(), arr.end());
        int ans = n;
        while(l<r){
            if(arr[l]+arr[r]==a){
                ans--;
                l++;
                r--;
            }
            else if(arr[l]+arr[r]<a){
                l++;
            }
            else{
                r--;
            }
        }
        cout << ans << endl;
    }
}