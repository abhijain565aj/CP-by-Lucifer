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
        int arr[n];
        fo(i, n)
        {
            cin >> arr[i];
        }
        int current = -1;
        int leftmostPair[n];
        fo(i,n){
            leftmostPair[i] = current;
            if(arr[i]!=arr[i+1]){
                current = i;
            }
        }
        int q;
        cin >> q;

        fo(i, q)
        {
            int l, r;
            cin >> l >> r;
            int i1 = -1;
            int j1 = -1;
            if(leftmostPair[r-1]>=l-1){
                i1 = leftmostPair[r-1]+1;
                j1 = leftmostPair[r-1]+2;
            }
            cout << i1 << " " << j1 << endl;
        }
        cout << endl;
    }
    
}
