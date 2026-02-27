#include <iostream>
// #include<string>
#include<algorithm>
// #include<cmath>
// #include<vector>
// #include <bits/stdc++.h>

using ll = long long int;
#define fo(i, n) for (int i = 0; i < n; i++)
#define swap(a, b) { a ^= b; b ^= a; a ^= b; }

#define pb push_back
using namespace std;
struct sum{
    int summ;
    int index;
};
bool compare(sum &a, sum &b){
    return a.summ < b. summ;
}
int main()
{
    int testCases;
    cin >> testCases;
    fo(t, testCases)
    {
        int n;
        cin >> n;
        int a[n];
        int b[n];
        fo(i,n){
            cin >> a[i];
        }
        fo(i,n){
            cin >> b[i];
        }
        sum Arr[n];
        fo(i,n){
            Arr[i].summ = a[i]+b[i];
            Arr[i].index = i;
        }
        sort(Arr, Arr+n, compare);
        fo(i,n){
            cout<<a[Arr[i].index]<<" ";
        }
        cout<<endl;
        fo(i,n){
            cout<<b[Arr[i].index]<<" ";
        }
        cout<<endl;
    }
}