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

using namespace std;
void dfs(int current, vector<vector<int>> &graph, vector<bool> &visited, int pathLength, int &maxLength, int n)
{
    visited[current] = true;
    pathLength++;
    maxLength = max(maxLength, pathLength);
    if (maxLength == n)
    {
        return;
    }

    for (int neighbor : graph[current])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, graph, visited, pathLength, maxLength, n);
        }
    }

    visited[current] = false; // Backtrack
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
        string g[n];
        string w[n];
        fo(i, n)
        {
            cin >> g[i] >> w[i];
        }
        vvi adj(n);
        fo(i, n)
        {
            fo1(j, i + 1, n)
            {
                if (g[i] == g[j] || w[i] == w[j])
                {
                    adj[i].pb(j);
                    adj[j].pb(i);
                }
            }
        }
        // fo(i, n)
        // {
        //     for (auto x : adj[i])
        //     {
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }
        int maxPathSize = 0;
        for (int i = 0; i < n; ++i)
        {
            vector<bool> visited(n, false);
            int pathLength = 0;
            dfs(i, adj, visited, pathLength, maxPathSize, n);
        }
        int ans = n - maxPathSize;
        cout << ans << endl;
    }
}
