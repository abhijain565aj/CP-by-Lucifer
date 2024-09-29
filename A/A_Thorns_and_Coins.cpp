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
        cin >> n;
        char arr[n];
        arr[0] = '.';
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int current_max = 0;
        int maximum = 0;
        fo(i,n){
            if(arr[i] == '@'){
                current_max++;;
            }
            else if(arr[i] == '*'){
                if(i+1<n && arr[i+1] == '*'){
                    break;
                }
            }
            
        }
        cout<<current_max<<endl;
    }
}