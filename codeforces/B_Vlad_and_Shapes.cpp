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
        char arr[n][n];
        int sq[n]={0};
        fo(i,n)
        {
            fo(j,n){
                cin>>arr[i][j];
                if(arr[i][j]=='1') sq[i]++;
            }
        }
        bool square = true;
        int first =0;
        fo(i,n){
            if(sq[i]!=0&&!first) {
                first = sq[i];
            }

            else if(first && sq[i]!=0){
                if(sq[i]==first){
                    square = false;
                    break;
                }
                else{
                    square = true;
                    break;
                }
            }
        }
        if(!square) cout<<"SQUARE";
        else cout<<"TRIANGLE";
        cout<<endl;
    }
}