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
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testCases = 1;
    cin >> testCases;
    fo(t, testCases)
    {
        ll n, k, Pb, Ps;
        cin >> n >> k >> Pb >> Ps;
        // cout << n << k << Pb << Ps << endl;
        vl p(n + 1);
        vl a(n + 1);
        fo(i, n)
        {
            cin >> p[i + 1];
        }
        fo(i, n)
        {
            cin >> a[i + 1];
        }
        fo(i, n)
        {
            if (p[i + 1] == Pb)
            {
                Pb = i + 1;
                break;
            }
        }
        fo(i, n)
        {
            if (p[i + 1] == Ps)
            {
                Ps = i + 1;
                break;
            }
        }
        ll scoreB = 0;
        ll currentSumB = 0;
        ll scoreS = 0;
        ll currentSumS = 0;
        // cout << Pb << " " << Ps << endl;
        for (ll i = 0; i < min(n, k); i++)
        {
            // cout << Pb << " " << Ps << scoreB << " " << scoreC << endl;
            scoreB = max(scoreB, currentSumB + (k - i) * a[p[Pb]]);
            scoreS = max(scoreS, currentSumS + (k - i) * a[p[Ps]]);
            currentSumB += a[p[Pb]];
            currentSumS += a[p[Ps]];
            Pb = p[Pb];
            Ps = p[Ps];
            // cout << scoreB << " " << scoreS << endl;
        }
        if (scoreB > scoreS)
        {
            cout << "Bodya\n";
        }
        else if (scoreB < scoreS)
        {
            cout << "Sasha\n";
        }
        else
        {
            cout << "Draw\n";
        }
    }
}
