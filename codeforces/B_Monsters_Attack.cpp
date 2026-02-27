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
        ll k;
        cin>>n>>k;
        vector<ll> health(n,0);
        vector<ll> monster(n,0);
        fo(i,n){
            cin>>health[i];
        }
        bool kill  =true;
        fo(i,n){
            int x;
            cin>>x;
            monster[abs(x)-1] += health[i];
        }
        vector<ll>sum(n,0);
        fo(i,n){
            sum[i] = monster[i] + ((i!=0)?sum[i-1]:0);
        }
        // fo(i,n){
        //     cout<<sum[i]<<" ";
        // }
        fo(i,n){
            if(sum[i]>(i+1)*k){
                kill = false;
                break;
            }
        }
        if(kill){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}