// Solution by Abhi Jain for the problem https://codeforces.com/contest/2271/problem/F
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
// find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#include "./Templates/DEBUG.cpp"
#define local true
#else
#define debug(...)
#define Test(tt)
#define Error_file(x)
#define local false
#endif

#define int long long

#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vvi vector<vi>
#define pii pair<int, int>
#define v(x) vector<x>

#define fo(i, n) for (int i = 0; i < n; i++)
#define re(i, n) for (int i = n - 1; i >= 0; i--)

#define YN(possible) cout << ((possible) ? "YES" : "NO") << endl;
#define all(x) (x).begin(), (x).end()
#define sortall(x) sort(all(x))
#define F first
#define S second
#define pb push_back

#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

#define read(a, n) \
  for (int i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) \
  for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');

void file(string s = "") {
  if (local) {
    // freopen("error.txt", "w", stderr);
    // freopen("output.txt", "w", stdout);
    // freopen(("input" + s + ".txt").c_str(), "r", stdin);
    return;
  }
}

constexpr int MOD = 1000000007;
constexpr int N = 1e5 + 1;
constexpr int INF = 1e18;

void solve();
void precompute();

signed main() {
  fastio;
  file();
  precompute();

  int testCases = 1;
  cin >> testCases;

  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}

void precompute() {
}

void solve() {
    int n;
    cin >> n;

    vi a(n);
    read(a, n);

    stack<int> st;
    vi diff(n + 1, 0); // mark beautiful intervals
    fo(i, n) {
        while (!st.empty() && a[st.top()] < a[i])
            st.pop();

        if (!st.empty() && a[st.top()] == a[i]) {
            int l = st.top();
            diff[l]++;
            diff[i + 1]--;
        }
        st.push(i);
    }

    int cur = 0, L = -1, R = -1;
    fo(i, n) {
        cur += diff[i];
        if (cur == 0) {
            if (L == -1) L = i;
            R = i;
        }
    }

    if (L == -1) {
      // pehle se beautiful
      cout << 0 << '\n';
        return;
    }

    // [L, r].
    int mx = -1;
    for (int r = L + 1; r < n; r++) {
        if (r >= R && a[r] > mx) {
            cout << 1 << '\n';
            cout << L + 1 << ' ' << a[r] << '\n';
            return;
        }
        mx = max(mx, a[r]);
    }

    // [l, R].
    mx = -1;
    for (int l = R - 1; l >= 0; l--) {
        if (l <= L && a[l] > mx) {
            cout << 1 << '\n';
            cout << R + 1 << ' ' << a[l] << '\n';
            return;
        }

        mx = max(mx, a[l]);
    }

    // beech me something big
    int maxVal = *max_element(a.begin() + L, a.begin() + R + 1);
    int p = -1, cnt = 0;
    for (int i = L; i <= R; i++) {
        if (a[i] == maxVal) {
            p = i;
            cnt++;
        }
    }

    if (cnt == 1) {
        // a[i] > (i, p).
        vector<pii> left;
        mx = -1;
        for (int i = p - 1; i >= 0; i--) {
            if (i <= L && a[i] > mx)
                left.pb({a[i], i});
            mx = max(mx, a[i]);
        }

        // a[i] > (p, i).
        vector<pii> right;
        mx = -1;
        for (int i = p + 1; i < n; i++) {
            if (i >= R && a[i] > mx)
                right.pb({a[i], i});
            mx = max(mx, a[i]);
        }

        int i = 0, j = 0;
        while (i < (int)left.size() && j < (int)right.size()) {
            if (left[i].F == right[j].F) {
                cout << 1 << '\n';
                cout << p + 1 << ' ' << left[i].F << '\n';
                return;
            }
            if (left[i].F < right[j].F)
                i++;
            else
                j++;
        }
    }

    // 2 me humesha
    int MX = 1e9;
    vector<pii> ops;
    if (a[0] != 1e9)
        ops.pb({0, MX});
    if (a[n - 1] != 1e9)
        ops.pb({n - 1, MX});
    cout << ops.size() << '\n';
    for (auto [i, x] : ops)
        cout << i + 1 << ' ' << x << '\n';

}
