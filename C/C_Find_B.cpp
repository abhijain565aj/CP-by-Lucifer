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
        int q;
        cin>>q;
        ll a[n];
        ll sum[n];
        int nu[n]={0};
        fo(i,n){
            cin>>a[i];
            sum[i]=a[i]+((i>0)?sum[i-1]:0);
            nu[i]=((i>0)?nu[i-1]:0)+((a[i]==1)?1:0);
        }

        fo(i,q){
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            int size  = r-l+1;
            ll s = sum[r]-((l>0)?sum[l-1]:0);
            int n1 = nu[r]-((l>0)?nu[l-1]:0);
            if(size == 1){
                cout<<"NO"<<endl;
            }
            else if(size + n1 > s){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }
    }
}