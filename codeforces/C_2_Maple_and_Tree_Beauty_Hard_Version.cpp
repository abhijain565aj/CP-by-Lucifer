// Solution by Abhi Jain aka Lucifer aka abhijain565aj
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifndef ONLINE_JUDGE
#include "./0_debug.cpp"
#else
#define debug(...)
#define Test(tt)
#define Error_file(x)
#endif

#define int long long
typedef long long ll;
typedef long double ld;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define fo(i, n) for (decltype(n) i = 0; i < n; i++)
#define fo1(i, a, b) for (decltype(b) i = a; i < b; i++)

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

constexpr int MOD = 1000000007;
constexpr int MAXN = 100000 + 5;  // adjust depending on problem constraints
constexpr int INF = 1e18;

// ---- Global bitset ----
bitset<MAXN> Sum;

void solve() {
    int n, k;
    cin >> n >> k;
    vi p(n);
    for (int i = 0; i < n - 1; i++) cin >> p[i];
    vvi adj(n);
    fo(i, n - 1) {
        p[i]--;
        adj[p[i]].push_back(i + 1);
    }

    vi dis(n, -1);
    dis[0] = 0;
    auto dfs = [&](auto&& self, int u) -> void {
        for (auto v : adj[u]) {
            dis[v] = dis[u] + 1;
            self(self, v);
        }
    };
    dfs(dfs, 0);

    int maxAns = n;
    fo(i, n) if (adj[i].empty()) maxAns = min(maxAns, dis[i] + 1);

    vi level(maxAns, 0);
    int margin = 0;
    fo(i, n) {
        if (dis[i] < maxAns)
            level[dis[i]]++;
        else
            margin++;
    }

    // ---- Reset bitset up to n ----
    Sum.reset();   // O(MAXN / word_size), very fast
    Sum[0] = 1;

    // ---- Subset sum via bitset ----
    fo(i, maxAns) {
        if (level[i] > 0) Sum |= (Sum << level[i]);
    }

    // ---- Query interval ----
    for (int i = k; i >= max(0LL, k - margin); i--) {
        if (Sum[i]) {
            cout << maxAns << "\n";
            return;
        }
    }
    cout << maxAns - 1 << "\n";
}

signed main() {
    fastio;
    int testCases;
    cin >> testCases;
    fo(tt, testCases) {
        Test(tt + 1);
        solve();
    }
}
