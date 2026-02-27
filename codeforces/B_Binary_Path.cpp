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
        string a[2];
        cin>>a[0]>>a[1];
        vector<short> down(n,-1);
        down[n-1] = 0;
        for(int i = n-2;i>=0;i--){
            if(a[1][i]<a[0][i+1]){
                down[i] = 0;
            }
            else if(a[1][i]==a[0][i+1] && down[i+1]!=-1){
                down[i] = 1;
            }
        }
        int count = 1;
        int d = false;
        // fo(i,n){
        //     cout<<down[i];
        // }
        // cout<<endl;
        fo(i,n){
            if(down[i]==-1&&!d){
                cout<<a[0][i];

            }
            else if(down[i]!=-1&&!d){
                cout<<a[0][i];
                cout<<a[1][i];
                for (int j = i;j<n;j++){
                    if(down[j]==1){
                        count++;
                    }
                    else if(down[j]==1){
                        count++;
                        break;
                    }
                    else{
                        break;
                    }
                }
                d = true;
            }
            else{
                cout<<a[1][i];
            }
        }
        cout<<endl;
        cout<<count<<endl;
    }
}