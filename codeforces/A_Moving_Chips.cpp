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
        bool arr[n];
        int start = false;
        int next=0; int prev=0;
        int ans1;
        fo(i,n){
            cin>>arr[i];
            if(arr[i]==1){
                start = true;
                prev= next;
            }
            if(start){
                if(arr[i] == 0){
                    next++;
                } 
            }
        }
        cout<<prev<<endl;
    }
}