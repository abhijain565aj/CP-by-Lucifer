#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define MOD = 1000000007
ll MOD = 1000000007;

// Modular Arithmetic
ll mod(ll a, ll m = MOD)
{
    return (a % m + m) % m;
}
ll add(ll a, ll b, ll m = MOD)
{
    return mod(a + b, m);
}
ll sub(ll a, ll b, ll m = MOD)
{
    return mod(a - b, m);
}
ll mul(ll a, ll b, ll m = MOD)
{
    return mod(a * b, m);
}
ll power(ll a, ll b, ll m = MOD)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = mul(res, a, m);
        a = mul(a, a, m);
        b >>= 1;
    }
    return res;
}
ll inv(ll a, ll m = MOD)
{
    return power(a, m - 2, m);
}
ll div(ll a, ll b, ll m = MOD)
{
    return mul(a, inv(b, m), m);
}

int main(){
    cout << inv(1892, 26);
}