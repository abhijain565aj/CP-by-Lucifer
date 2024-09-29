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
        int start = 1, end = (n/2)*2;
        fo(i,n){
            if(i%2==0){
                arr[i]=start;
                start = start +2;
            }
            else{
                arr[i]=end;
                end = end - 2;
            }
            
        }
        fo(i,n){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}