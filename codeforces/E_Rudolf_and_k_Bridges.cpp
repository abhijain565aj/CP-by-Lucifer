// Solution by Abhi Jain aka Lucifer aka abhijain565aj
// Mera solution kyun dekh rha?

#include <bits/stdc++.h>

using ll = long long int;
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define L cout << "\n"

#define fo(i, n) for (int i = 0; i < n; i++)
#define re(i, n) for (int i = n - 1; i >= 0; i--)
#define fo1(i, a, b) for (int i = a; i < b; i++)
#define fo2(i, a, b) for (int i = a; i >= b; i--)

#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define F first
#define S second
#define pb push_back

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testCases = 1;
    cin >> testCases;
    fo(t, testCases)
    {
        ll n, m, k, d;
        cin >> n >> m >> k >> d;
        vl river(m);
        vl cost(n);
        fo(i, n)
        {
            fo(j, m)
            {
                cin >> river[j];
                river[j]++;
            }
            vl p(m);
            vector<pli> v;
            int cp = 0;
            fo(j, m)
            {
                p[j] = river[j] + ((cp < v.size()) ? v[cp].first : 0);
                // cout << river[j] << " " << p[j] << " ";
                while (cp < v.size() && v.back().first > p[j])
                {
                    v.pop_back();
                }
                v.pb({p[j], j});
                while (cp < v.size() && v[cp].second < j - d)
                {
                    cp++;
                }
                // cout << " " << cp << " : [";
                // for (auto x : v)
                // cout << x.first << " ";
                // cout << "]\n";
            }
            // cout << endl;
            cost[i] = p[m - 1];
            // cout << cost[i] << " ";
        }
        vl sum(n);
        fo(i, n)
        {
            sum[i] = cost[i] + ((i > 0) ? sum[i - 1] : 0);
        }
        ll minSum = INT64_MAX;
        fo(i, n - k + 1)
        {
            minSum = min(minSum, sum[i + k - 1] - ((i > 0) ? sum[i - 1] : 0));
        }
        cout << minSum << endl;
    }
}
