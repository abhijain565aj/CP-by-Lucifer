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
        ll k;
        cin>>n>>k;
        vector<int> a;
        while(n!=0){
            a.pb(n/2+n%2);
            n=n/2;
        }
        int n1=0;
        int i = 0;
        while(k>0){
            k = k-a[i];
            i++;
        }
        i--;
        k = k+a[i];
        ll ab = 2*k-1;
        fo(j,i){
            ab = ab*2;
        }
        cout<<ab;
        cout<<endl;
    }
}