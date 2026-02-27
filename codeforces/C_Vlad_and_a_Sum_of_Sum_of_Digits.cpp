#include <bits/stdc++.h>

using ll = long long int;
#define fo(i, n) for (int i = 0; i < n; i++)
#define pb push_back
using namespace std;
ll summ(ll n)
{
        return (n * (n + 1)) / 2;
}
int main()
{
    int testCases;
    cin >> testCases;

    fo(t, testCases)
    {
        ll n;
        cin >> n;
        ll sum= 0;
        ll prod = 1;
        ll prev = 0;
        while(n!=0)
        {
            sum += ((n/10)*summ(9)+summ(n%10))*prod;
            sum -= (n%10)*prev;
            prev += (9 - n%10)*prod;
            n = n/10;
            prod *= 10;
        }
        cout << sum << endl;
    }
}