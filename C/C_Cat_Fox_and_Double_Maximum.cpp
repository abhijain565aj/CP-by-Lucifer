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
        vi a(n);
        int onew = 0;
        fo(i, n)
        {
            cin >> a[i];
            if (a[i] == 1)
            {
                onew = i;
            }
        }
        vi b(n, 0);
        set<int> s;
        fo(i, n)
        {
            s.insert(i + 1);
        }
        for (int i = 1 + onew & 1; i < n - 1; i += 2)
        {
            b[i] = n + 2 - a[i];
            s.erase(n + 2 - a[i]);
        }
        vector<pii> v;
        fo(i, n)
        {
            if (b[i] == 0)
            {
                v.pb({a[i], i});
            }
        }
        sort(v.rbegin(), v.rend());
        for (auto x : v)
        {
            b[x.S] = *s.begin();
            s.erase(s.begin());
        }
        for (auto x : b)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
