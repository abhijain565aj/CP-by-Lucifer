// Solution by Abhi Jain for the problem https://codeforces.com/contest/2284/problem/D
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "./Templates/DEBUG.cpp"
#define local true
#else
#define debug(...)
#define Test(tt)
#define local false
#endif

#define int long long

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define v(x) vector<x>

#define YN(possible) cout << ((possible) ? "YES" : "NO") << endl;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back

#define read(a, n) \
  for (int i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) \
  for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');

constexpr int MOD = 1000000007;
constexpr int N = 1e5 + 1;
constexpr int INF = 1e18;

void solvefirst();
void solvesecond();
void precompute();

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  precompute();

  string s;
  cin>>s;

  int _testCases = 1;
  cin >> _testCases;

  for(int _t=0; _t<_testCases; _t++) {
    Test(_t + 1);
    if(s=="first"){
      solvefirst();
    }else{
      solvesecond();
    }
  }
}

void precompute() {
}

void solvefirst() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int f0 = -1;

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0') f0 = i;
    }

    if (f0 == -1) {
        // All ones: make an odd cycle.
        cout << n << '\n';
        cout << "1 2\n";
        cout << "2 3\n";
        cout << "3 1\n";
        for (int i = 3; i < n; i++) {
            cout << 1 << " " << i + 1 << '\n';
        }
    } else {
        // Make a tree.
        // Odd distance from n -> 0
        // Even distance from n -> 1
        cout << n - 1 << '\n';
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') {
                cout << i + 1 << " " << n << '\n';
            } else {
                cout << f0 + 1 << " " << i + 1 << '\n';
            }
        }
    }
}

void solvesecond() {
    int n, m;
    cin >> n >> m;

    vvi adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        adj[u].pb(v);
        adj[v].pb(u);
    }
    // Check whether graph is bipartite and find coloring.
    vi color(n, -1);
    bool bipartite = true;
    queue<int> q;
    for (int src = 0; src < n; src++) {
        if (color[src] != -1) continue;

        color[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    q.push(v);
                } else if (color[v] == color[u]) {
                    bipartite = false;
                }
            }
        }
    }
    if (!bipartite) {
        cout << string(n - 1, '1') << '\n';
        return;
    }
    // Same color as n -> even distance -> 1
    // Different color from n -> odd distance -> 0
    string ans = "";
    for (int i = 0; i < n - 1; i++) {
        if (color[i] == color[n - 1]) {
            ans += '1';
        } else {
            ans += '0';
        }
    }
    cout << ans << '\n';
}
