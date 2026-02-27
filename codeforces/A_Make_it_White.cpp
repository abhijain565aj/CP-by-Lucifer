#include <iostream>
#include<string>

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
        string arr;
        cin>>arr;
        int left_p, right_p;
        for (int i=0;i<n;i++){
            if (arr[i]=='B'){
                left_p = i;
                break;
            }
        }
        for(int i=n-1; i>=0;i--){
            if (arr[i]=='B'){
                right_p = i;
                break;
            }
        }
        cout<<right_p-left_p+1<<endl;
    }
}