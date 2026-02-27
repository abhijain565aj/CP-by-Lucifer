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
        ll min, max;
        fo(i,n){
            ll a;
            cin>>a;
            if(i==0){
                min=a;
                max=a;
            }
            else if(a>max){
                max =a;
            }
            else if(a<min){
                min =a;
            }

        }
        cout<<max-min<<endl;
    }
}