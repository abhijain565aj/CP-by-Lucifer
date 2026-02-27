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
        int count[200001];
        int ct[n];
        fo(i,200001){
            count[i]=0;
        }
        fo(i,n){
            ct[i]=0;
        }
        fo(i,n){
            cin>>arr[i];
            ct[i]=count[arr[i]];
            count[arr[i]]++;
        }
        fo(i,n){
            char b = 'a'+ct[i];
            cout<<b;
        }
        cout<<endl;
    }
}