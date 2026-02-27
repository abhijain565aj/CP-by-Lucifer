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
// find_by_order, order_of_key

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "./0_debug.cpp"
#define local true
#else
#define debug(...)
#define Test(tt)
#define local false
#define Error_file(x)
#endif

#define int long long
typedef long long ll;
typedef long double ld;

#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vvi vector<vi>
#define pii pair<int, int>
#define v(x) vector<x>

#define fo(i, n) for (decltype(n) i = 0; i < n; i++)
#define re(i, n) for (decltype(n) i = n - 1; i >= 0; i--)
#define fo1(i, a, b) for (decltype(b) i = a; i < b; i++)
#define re1(i, a, b) for (decltype(a) i = a; i >= b; i--)

#define YN(possible) cout << ((possible) ? "YES" : "NO") << endl;
#define all(x) (x).begin(), (x).end()
#define sortall(x) sort(all(x))
#define F first
#define S second
#define pb push_back
// a.resize(unique(all(a)) - a.begin());

#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

#define read(a, n) \
  for (int i = 0; i < n; ++i) cin >> a[i];
#define print_space(a, n) \
  for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');

constexpr int MOD = 1000000007;
constexpr int N = 1e5 + 1;
constexpr int INF = 1e18;
int n;
vvi adj;
int x, y;
vi path(int l, int r) {
  vi par(n, -1);
  auto dfs = [&](auto&& self, int u, int p) -> void {
    par[u] = p;
    for (int v : adj[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };
  dfs(dfs, l, -1);
  vi path;
  path.pb(r);
  while (r != l) {
    r = par[r];
    path.pb(r);
  }
  return path;
}
int check(int l, int r) {
  auto p1 = path(l, r);
  auto p2 = path(x, y);
  debug(p1, p2);
  auto s1 = set<int>(all(p2));
  for (auto x : p1)
    if (s1.find(x) != s1.end()) {
      return 1;
    }
  return 0;
}

void solve() {
  cin >> n;
  if (local) {
    cin >> x >> y;
    x--, y--;
  }
  adj.clear();
  adj.resize(n);
  fo(i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  int qc = 0;
  auto ask = [&](int l, int r) -> int {
    debug(l, r);
    qc++;
    if (local && qc > 3) {
      cout << "Error: Too many queries!" << endl;
      exit(0);
    }
    if (local) {
      return check(l, r);
    }
    cout << "? " << l + 1 << ' ' << r + 1 << endl;
    cout.flush();
    int ans;
    cin >> ans;
    if (ans == -1) {
      exit(0);
      cout << "Error: Invalid query!" << endl;
    }
    return ans;
  };
  auto answer = [&](int i) {
    if (local) {
      if (check(i, i) == 0) {
        cout << "Error: Invalid answer!" << endl;
        exit(0);
      } else {
        cout << "Correct answer!" << endl;
        return;
      }
    }
    cout << "! " << i + 1 << endl;
    cout.flush();
  };
  int lp = 0, rp = 1;
  while (rp < n) {
    if (ask(lp, rp) == 0) {
      lp += 2;
      rp += 2;
    } else
      break;
  }
  debug(lp, rp);
  if (rp >= n) {
    answer(lp);
    return;
  }
  vi par(n, -1);
  auto dfs = [&](auto&& self, int u, int p) -> void {
    par[u] = p;
    for (int v : adj[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };
  dfs(dfs, lp, -1);
  int u = rp;
  vi path;
  path.pb(u);
  while (u != lp) {
    u = par[u];
    path.pb(u);
  }
  debug(path);
  vi npath;
  for (auto x : path)
    if (x >= lp) {
      npath.pb(x);
    }
  path = npath;
  if (path.size() == 1) {
    answer(path[0]);
    return;
  } else if (path.size() == 2) {
    if (ask(path[0], path[0])) {
      answer(path[0]);
    } else {
      answer(path[1]);
    }
    return;
  }
  int l = 1, r = path.size() - 2;
  while (l <= r) {
    if (ask(path[l], path[r])) {
      if (l == r) {
        answer(path[l]);
        return;
      }
      l++, r--;
    } else {
      l--, r++;
      if (ask(path[l], path[l])) {
        answer(path[l]);
      } else {
        answer(path[r]);
      }
      return;
    }
  }
  if (l == r) {
    debug("HI");
    answer(path[l]);
    return;
  } else if (l == r - 1) {
    if (ask(path[l], path[l])) {
      answer(path[l]);
    } else {
      answer(path[r]);
    }
    return;
  }
}

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1000;
  cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
