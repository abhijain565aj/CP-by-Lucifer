// Solution by Abhi Jain aka Lucifer aka abhijain565aj
// Mera solution kyun dekh rha?

#include <bits/stdc++.h>

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
using namespace std;

int M(int a, int b, vvi &v, vi &num, vi &sum, int n, vector<bool> &B)
{
    // cout << "Yes" << a << " " << b << endl;
    if (v[a][b] != 0)
    {
        // cout << "Ans" << a << " " << b << " " << v[a][b] << endl;
        return v[a][b];
    }
    if (a == b)
    {
        v[a][b] = max(num[a], 1);
        if (num[a] == 0)
        {
            B[a] = true;
        }
        else
        {
            B[a] = false;
        }
        // cout << "Ans" << a << " " << b << " " << v[a][b] << endl;
        return v[a][b];
    }
    int m = 0;
    fo1(i, a, b + 1)
    {
        int m2 = max(sum[i] - sum[a] + num[a], (i - a + 1) * (i - a + 1));
        int oldm = m;
        m = max(m, m2 + ((i < n - 1) ? M(i + 1, n - 1, v, num, sum, n, B) : 0));
        if (oldm != m)
        {
            if (sum[i] - sum[a] + num[a] >= (i - a + 1) * (i - a + 1))
            {
                fo1(j, a, i + 1)
                {
                    B[j] = false;
                }
            }
            else
            {
                fo1(j, a, i + 1)
                {
                    B[j] = true;
                }
            }
        }
        // cout << i << " " << m << endl;
    }
    v[a][b] = m;
    // cout << "Ans" << a << " " << b << " " << v[a][b] << endl;
    return m;
}
void answerPush(int a, int b, vector<pii> &ans)
{
    if (a + 1 != b)
    {
        for (int i = a; i <= b; i++)
        {
            ans.pb({a, i});
        }
        ans.pb({a + 1, b});
        answerPush(a + 1, b, ans);
    }
    else
    {
        ans.pb({a, a});
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testCases = 1;
    // cin >> testCases;
    fo(t, testCases)
    {
        int n;
        cin >> n;
        vi num(n);
        fo(i, n)
        {
            cin >> num[i];
        }
        vi sum(n, 0);
        sum[0] = num[0];
        fo1(i, 1, n)
        {
            sum[i] = sum[i - 1] + num[i];
        }
        vvi v(n, vi(n, 0));
        vector<bool> B(n, false);
        int val = M(0, n - 1, v, num, sum, n, B);
        fo(i, n)
        {
            cout << B[i] << " ";
        }
        L;
        vi ones;
        fo(i, n)
        {
            if ((B[i] && i == 0) || (B[i] && i == n - 1) || (B[i] && (!B[i - 1] || !B[1 + 1])))
            {
                ones.pb(i + 1);
            }
        }
        // for (auto x : ones)
        // {
        //     cout << x << " ";
        // }
        vector<pii> ans;
        for (int i = 0; i < ones.size(); i += 2)
        {
            fo1(j, ones[i] - 1, ones[i + 1])
            {
                if (num[j] == 0)
                {
                    ans.pb({j + 1, j + 1});
                }
            }
            ans.pb({ones[i], ones[i + 1]});
            answerPush(ones[i], ones[i + 1], ans);
            ans.pb({ones[i], ones[i + 1]});
        }
        cout << val << " " << ans.size() << "\n";
        for (auto x : ans)
        {
            cout << x.F << " " << x.S << "\n";
        }
    }
}
