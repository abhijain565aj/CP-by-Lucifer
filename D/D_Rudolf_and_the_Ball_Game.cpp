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
// void unique(vector<int> &vec)
// {
//     set<int> set(all(vec));
//     vi unique(all(set));
//     fo(i, set.size())
//     {
//     }
//     return unique;
// }
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testCases = 1;
    cin >> testCases;

    fo(t, testCases)
    {
        int n, m, x;
        cin >> n >> m >> x;
        vi players;
        players.pb(x - 1);
        int dis;
        char turn;
        fo(i, m)
        {
            cin >> dis >> turn;
            if (turn == '0')
            {
                int p = players.size();
                fo(i, p)
                {
                    players[i] = (players[i] + dis) % n;
                }
            }
            else if (turn == '1')
            {
                int p = players.size();
                fo(i, p)
                {
                    players[i] = (players[i] - dis + n) % n;
                }
            }
            else if (turn == '?')
            {
                int p = players.size();
                fo(i, p)
                {
                    int m = (players[i] - dis + n) % n;
                    players.pb(m);
                }
                fo(i, p)
                {
                    players[i] = (players[i] + dis) % n;
                }
            }
            if (i % 5 == 0 || i == m - 1)
            {
                sort(all(players));
                auto x = unique(all(players));
                players.resize(distance(players.begin(), x));
            }
        }
        cout << players.size() << "\n";
        for (auto x : players)
        {
            cout << x + 1 << " ";
        }
        cout << "\n";
    }
}
