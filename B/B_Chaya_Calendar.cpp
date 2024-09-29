#include <bits/stdc++.h>

using ll = long long int;
#define fo(i, n) for (int i = 0; i < n; i++)
#define pb push_back
using namespace std;
// int gcd(int a, int b){
//     while (b != 0) {
//         int temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }
// int lcm(int a, int b){
//     return a * b / gcd(a, b);
// }
int main()
{
    int testCases;
    cin >> testCases;
    fo(t, testCases)
    {
        int n;
        cin >> n;
        int a[n];
        fo(i,n){
            cin>>a[i];
        }
        ll ans = 0;
        for(int i=0;i<n;i++){
            ans += a[i] - ans%a[i];
        }
        cout<<ans<<endl;
    }
}