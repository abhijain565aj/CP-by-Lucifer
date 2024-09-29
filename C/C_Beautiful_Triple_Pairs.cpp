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
ll count(vector<tuple<ll, ll, ll>> &b)
{
    sortall(b);
    vvl ans;
    ll n = b.size();
    ans.pb({1});
    fo1(i, 1, n)
    {
        if (get<0>(b[i]) == get<0>(b[i - 1]) && get<1>(b[i]) == get<1>(b[i - 1]))
        {
            if (get<2>(b[i]) == get<2>(b[i - 1]))
            {
                ans.back().back()++;
            }
            else
            {
                ans.back().pb(1);
            }
        }
        else
        {
            ans.pb({1});
        }
    }
    
    ll answer = 0;
    for (auto x : ans)
    {
        ll sum = 0;
        for (auto y : x)
        {
            sum += y;
        }
        answer += (sum * (sum - 1)) / 2;
        for (auto y : x)
        {
            answer -= (y * (y - 1)) / 2;
        }
    }
    return answer;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testCases = 1;
    cin >> testCases;
    fo(t, testCases)
    {
        int n;
        cin >> n;
        vl a(n);
        fo(i, n)
        {
            cin >> a[i];
        }
        ll answer = 0;
        vector<tuple<ll, ll, ll>> b;
        fo(i, n - 2)
        {
            b.pb({a[i], a[i + 1], a[i + 2]});
        }
        answer += count(b);
        fo(i, n - 2)
        {
            b[i] = {a[i + 2], a[i + 1], a[i]};
        }
        answer += count(b);
        fo(i, n - 2)
        {
            b[i] = {a[i], a[i + 2], a[i + 1]};
        }
        answer += count(b);
        cout << answer;
        L;
    }
}
