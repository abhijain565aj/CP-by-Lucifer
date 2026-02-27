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
        int n, m, k;
        cin >> n >> m >> k;
        int a[n];
        fo(i, n)
        {
            cin >> a[i];
        }
        int b[m];
        fo(i, m)
        {
            cin >> b[i];
        }
        int c[k + 1];
        fo(i, k + 1){
            c[i]=0;
        }
        fo(i, n)
        {
            if (a[i] <= k && (c[a[i]]==0 || c[a[i]]==2))
            {
                c[a[i]]++;
            }
        }
        fo(i, m)
        {
            if (b[i] <= k && (c[b[i]]==0 || c[b[i]]==1))
            {
                c[b[i]] += 2;
            }
        }
        int arr[4];
        fo(i,4){
            arr[i]=0;
        }
        fo(i,k){
            arr[c[i+1]]++;
        }
        if(arr[0]!=0){
            cout<<"NO"<<endl;
        }
        else if(arr[1]+arr[3]>=arr[2]&&arr[2]+arr[3]>=arr[1]){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
}