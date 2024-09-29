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
        sort(arr, arr + n);
        int max  = 2*(arr[n-2]+arr[n-1]-arr[0]-arr[1]);
        cout<<max<<endl;
    }
}