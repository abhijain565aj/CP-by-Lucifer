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
        int r;
        cin >> n >> r;
        ll arr[n];
        fo(i, n)
        {
            cin >> arr[i];
        }
        char c[n];
        fo(i, n)
        {
            cin >> c[i];
        }
        vector<ll> pairs;
        int left =0;
        int right=n-1;
        fo(i,n){
            if(c[i]=='L'){
                pairs.pb(arr[left]);
                left++;
            }
            else{
                pairs.pb(arr[right]);
                right--;
            }
        }
        ll prod[n];
        prod[n-1]=pairs[n-1]%r;
        for(int i=n-2; i>=0; i--){
            prod[i]=(prod[i+1]*pairs[i])%r;
        }
        fo(i, n)
        {
            cout << prod[i] << " ";
        }
        cout << endl;
        
    }
}