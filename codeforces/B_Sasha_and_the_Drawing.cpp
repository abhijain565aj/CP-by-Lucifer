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
        int k;
        cin>>n>>k;
        if(k==4*n-2){
            cout<<2*n;
        }
        else if(k==4*n-1){
            cout<<2*n-1;
        }
        else{
            cout<<k/2+k%2;
        }
        cout<<endl;
    }
}