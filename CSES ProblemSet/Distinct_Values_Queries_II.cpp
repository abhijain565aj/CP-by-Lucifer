// Solution by Abhi Jain aka Lucifer aka abhijain565aj
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

using namespace std;
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "./DEBUG.cpp"
#define local true
#else
#define debug(...)
#define Test(tt)
#define Error_file(x)
#define local false
#endif

#define int long long
#define vi vector<int>

#define fo(i, n) for (int i = 0; i < n; i++)
#define re(i, n) for (int i = n - 1; i >= 0; i--)
#define loop(i, a, b) for (int i = a; (a >= b) ? i >= b : i <= b; (a >= b) ? i-- : i++)

#define YN(possible) cout << ((possible) ? "YES" : "NO") << endl;
#define all(x) (x).begin(), (x).end()
#define sortall(x) sort(all(x))
#define pb push_back
// a.resize(unique(all(a)) - a.begin());

#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

#define read(a, n) \
  for (int i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) \
  for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');

constexpr int MOD = 1000000007;
constexpr int N = 1e5 + 1;
constexpr int INF = 1e18;

void solve();

signed main() {
  fastio;
  int testCases = 1;
  // cin >> testCases;

  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}

template <typename T>
struct SegmentTree {
  vector<T> tree;
  int n;
  int default_value;
  function<T(T, T)> merge;
  SegmentTree(
      int n,
      int default_value = 0,
      function<T(T, T)> merge = [](T l, T r) { return l + r; }) {
    this->n = n;
    this->default_value = default_value;
    this->merge = merge;
    tree.resize(4 * n);
  }
  void build(vector<T>& a) {
    buildp(a, 1, 0, n - 1);
  }
  T query(int l, int r) {
    return queryp(1, 0, n - 1, l, r);
  }
  void update(int pos, T new_val) {
    updatep(1, 0, n - 1, pos, new_val);
  }

  void buildp(vector<T>& a, int v, int tl, int tr) {
    if (tl == tr) {
      tree[v] = a[tl];
    } else {
      int tm = (tl + tr) / 2;
      buildp(a, v * 2, tl, tm);
      buildp(a, v * 2 + 1, tm + 1, tr);
      tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
  }
  T queryp(int v, int tl, int tr, int l, int r) {
    if (l > r) {
      return default_value;
    }
    if (l == tl && r == tr) {
      return tree[v];
    }
    int tm = (tl + tr) / 2;
    return merge(queryp(v * 2, tl, tm, l, min(r, tm)), queryp(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
  void updatep(int v, int tl, int tr, int pos, T new_val) {
    if (tl == tr) {
      tree[v] = new_val;
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm) {
        updatep(v * 2, tl, tm, pos, new_val);
      } else {
        updatep(v * 2 + 1, tm + 1, tr, pos, new_val);
      }
      tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
  }
};

void solve() {
  int n, q;
  cin >> n >> q;
  vi a(n);
  read(a, n);
  map<int, set<int>> mp;
  vi nxt(n, n), prev(n, -1);
  re(i, n) {
    if (mp[a[i]].size()) {
      int mx = *mp[a[i]].begin();
      nxt[i] = mx;
      prev[mx] = i;
    }
    mp[a[i]].insert(i);
  }
  // debug(nxt, prev);
  SegmentTree<int> st(n, INF, [](int u, int v) {
    return min(u, v);
  });
  st.build(nxt);
  while (q--) {
    int t;
    cin >> t;
    if (t == 2) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      YN(st.query(u, v) > v);
    } else {
      int k, x;
      cin >> k >> x;
      k--;
      debug(k, a[k], nxt[k], prev[k]);
      if (nxt[k] != n && prev[k] != -1) {
        nxt[prev[k]] = nxt[k];
        st.update(prev[k], nxt[k]);
        prev[nxt[k]] = prev[k];
      } else if (nxt[k] == n && prev[k] != -1) {
        nxt[prev[k]] = n;
        st.update(prev[k], n);
      } else if (prev[k] == -1 && nxt[k] != n) {
        prev[nxt[k]] = -1;
      }
      nxt[k] = n;
      st.update(k, n);
      prev[k] = -1;

      mp[a[k]].erase(k);
      a[k] = x;

      auto it = mp[x].lower_bound(k);
      if (it != mp[x].end()) {
        nxt[k] = *it;
        prev[*it] = k;
        st.update(k, *it);
      }

      if (it != mp[x].begin()) {
        it--;
        nxt[*it] = k;
        prev[k] = *it;
        st.update(*it, k);
      }
      mp[a[k]].insert(k);
      debug(k, x, nxt[k], prev[k]);
    }
  }
}
