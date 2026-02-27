// Solution by Abhi Jain aka Lucifer aka abhijain565aj
// Mera solution kyun dekh rha?

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

using ll = long long int;
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define L cout << "\n"

#define fo(i, n) for (int i = 0; i < n; i++)
#define re(i, n) for (int i = n - 1; i >= 0; i--)
#define fo1(i, a, b) for (int i = a; i < b; i++)
#define re1(i, a, b) for (int i = a; i >= b; i--)

#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define F first
#define S second
#define pb push_back
// a.resize(unique(all(a)) - a.begin());  -> unque element me convert karta hai

const ll MOD = 1e9 + 7;

ll add(ll a, ll b)
{
    return (a + b) % MOD;
}

ll sub(ll a, ll b)
{
    return (a - b + MOD) % MOD;
}

ll mul(ll a, ll b)
{
    return (1LL * a * b) % MOD;
}

ll power(ll x, ll y)
{
    ll res = 1;
    x = x % MOD;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

ll modInverse(ll a)
{
    return power(a, MOD - 2);
}

ll nCr(ll n, ll r)
{
    if (r == 0 || r == n)
        return 1;
    ll fact[n + 1];
    fact[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        fact[i] = mul(fact[i - 1], i);
    }
    return mul(fact[n], mul(modInverse(fact[r]), modInverse(fact[n - r])));
}

int main()
{
    ll n, k;
    cin >> n >> k;
    ll i = 0;
    vi answers(n + 1, 0);
    ll c1, c2;
    if (i + k <= n)
    {
        c1 = nCr(n - 2, k - 2);
        c2 = nCr(n - 1, k - 1);
    }
    fo1(i, 1, n)
    {
        ll ans = 0;
        if (i + k <= n)
        {
            c1 = mul(c1, n - i - k + 1);
            c1 = mul(c1, modInverse(n - i - 1));
            c2 = mul(c2, n - i - k + 1);
            c2 = mul(c2, modInverse(n - i));
            if (n - i >= k)
            {
                // ans += (n - i - 1) * nCr(n - i - 2, k - 2);
                ans += mul(n - i - 1, c1);
            }
            if (i == 0)
            {
                ans = 0;
            }
            else
            {
                // ans += 2 * nCr(n - i - 1, k - 1);
                ans += mul(2, c2);
            }
        }
        ans = ans % MOD;
        answers[i] = ans;
    }
    answers[0] = nCr(2 * n - 2, k);
    fo(i, n)
    {
        answers[0] -= answers[i + 1];
    }
    answers[0] = (answers[0] + MOD) % MOD;
    for (auto x : answers)
    {
        cout << x << " ";
    }
    cout << endl;
}