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

#define int long long

#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define vb vector<bool>
#define pii pair<int, int>
#define v(x) vector<x>
#define read_array(a, n) \
  for (int i = 0; i < n; i++) cin >> a[i];
#define read(a, n) read_array(a, n)
#define ll long long

#define fo(i, n) for (int i = 0; i < n; i++)
#define re(i, n) for (int i = n - 1; i >= 0; i--)
#define loop(i, a, b) for (int i = a; (a >= b) ? i >= b : i <= b; (a >= b) ? i-- : i++)

#define YN(possible) cout << ((possible) ? "YES" : "NO") << endl;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define pb push_back
// a.resize(unique(all(a)) - a.begin());

// DEBUG TEMPLATE
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", _print(__VA_ARGS__)
#define local true
#else
#define debug(...)
#define local false
#endif

template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p);
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream& operator<<(ostream& os, const T_container& v) {
  os << '[';
  string sep;
  for (const T& x : v) os << sep << x, sep = ", ";
  return os << ']';
}
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }

inline void _print() { cerr << endl; }
template <typename T, typename... V>
void _print(const T& t, const V&... v) {
  cerr << t;
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}

void file(string s = "") {
  if (local) {
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
    freopen(("input" + s + ".txt").c_str(), "r", stdin);
  }
}

/// MATH
constexpr int MOD = 1000000007;
constexpr int N = 1e5 + 1;
constexpr int INF = 1e18;

int power(int a, int n) {
  int ans = 1;
  while (n) {
    if (n & 1) ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    n >>= 1;
  }
  return ans;
}

vi fac, fi, inv;

void precompute_fac(int n = 0) {
  if (n == 0) return;
  fac.resize(n);
  fi.resize(n);
  inv.resize(n);
  fac[0] = fac[1] = inv[1] = fi[0] = fi[1] = 1;
  loop(i, 2, n - 1) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    fi[i] = fi[i - 1] * inv[i] % MOD;
  }
}

int dp[51][51];

int nCr(int n, int r) {
  if (n < 0 || r < 0 || r > n) return 0;
  return dp[n][r];
}

vb prime;
void sieve(int n = 0) {
  if (n == 0) return;
  prime.resize(n, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i * i < n; i++) {
    if (!prime[i]) continue;
    for (int j = i * i; j < n; j += i) {
      prime[j] = false;
    }
  }
}

void solve();

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  dp[0][0] = 1;
  dp[1][0] = 1;
  dp[1][1] = 1;
  for (int i = 2 ; i <= 50 ; i++)
  {
    dp[i][0] = dp[i][i] = 1;
    for (int j = 1; j < i ; j++)
    {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    }
  }

  file();
  precompute_fac();
  sieve();

  int testCases = 1;
  fo(tt, testCases) {
    solve();
  }
}

template <typename T>
struct SegmentTree {
  vector<T> tree;
  ll n;
  SegmentTree(ll n) {
    this->n = n;
    tree.resize(4 * n);
  }
  T sum(ll l, ll r) {
    return sump(1, 0, n - 1, l, r);
  }
  void update(ll pos, T new_val) {
    updatep(1, 0, n - 1, pos, new_val);
  }
  T operation(T l, T r) {
    return l + r;
    // change this
  }

  T sump(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) {
      return 0;
    }
    if (l == tl && r == tr) {
      return tree[v];
    }
    ll tm = (tl + tr) / 2;
    return operation(sump(v * 2, tl, tm, l, min(r, tm)), sump(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
  void updatep(ll v, ll tl, ll tr, ll pos, T new_val) {
    if (tl == tr) {
      tree[v] += new_val;
    } else {
      ll tm = (tl + tr) / 2;
      if (pos <= tm) {
        updatep(v * 2, tl, tm, pos, new_val);
      } else {
        updatep(v * 2 + 1, tm + 1, tr, pos, new_val);
      }
      tree[v] = operation(tree[v * 2], tree[v * 2 + 1]);
    }
  }
};




void solve(){
    // int n, m; cin>>n>>m;
    // vector<int> boss(n);
    // vector<int> lowest_boss(n, 1e6+1);
    // vector<int> best_child_index(n, -1);
    // vector<int> highest_child(n, 0);
    // vector<int> second_highest_child(n, 0);
    // vector<int> ages(n);
    // for (int i = 0; i < n; i++){
    //     int u, v; cin>>u>>v;
    //     v--;
    //     boss[i]=v;
    //     ages[i]=u;
    // }
    // for (int i = 0; i < n; i++) {
    //   int u = i;
    //   int v = boss[i];
    //   lowest_boss[i] = ages[v];
    //   if (ages[i] > highest_child[v]) {
    //     best_child_index[v] = i;
    //     second_highest_child[v] = highest_child[v];
    //     highest_child[v] = ages[i];
    //   } else if (ages[i] > second_highest_child[v]) {
    //     second_highest_child[v] = ages[i];
    //   }
    // }
    // vector<ordered_set<pair<int, int>>> ls(n), rs(n);
    // vector<vector<pair<int, int>>> l_r_pairs(n);
    // deque<pair<int, int>> parties;
    // for (int i = 0; i < m; i++){
    //     int o, l, r;
    //     cin>>o>>l>>r;
    //     ls[o-1].insert({l,i});
    //     rs[o-1].insert({r,i});
    //     l_r_pairs[o-1].push_back({l,r});
    //     parties.pb({l,r});
    // }
    // vector<array<int, 2>> queries;
    // ordered_set<pair<int,int> > os;
    // vector<int> answer(n, 0);
    // for (int i = 0; i < n; i++) {
    //   queries.pb({ages[i], ages[boss[i]]});
    //   queries.pb({highest_child[i], ages[i]});
    //   queries.pb({highest_child[i], lowest_boss[i]});
    //   if (boss[i] != i) {
    //     answer[i] -= (ls[boss[i]].order_of_key({ages[i], MOD}) - ls[boss[i]].order_of_key({highest_child[i], MOD}));
    //   }
    //   if (best_child_index[i] != -1) {
    //     for (auto it : l_r_pairs[best_child_index[i]]) {
    //       int l = it.first;
    //       int r = it.second;
    //       if (l > second_highest_child[i] && r >= ages[i] && r < lowest_boss[i]) {
    //         answer[i]--;
    //       }
    //     }
    //   }
    //   for (int j = 0; j < ls[i].size(); j++) {
    //     int l = l_r_pairs[i][j].first, r = l_r_pairs[i][j].second;
    //     if (l > highest_child[i] && r < lowest_boss[i]) answer[i]++;
    //   }
    // }
    // sort(queries.begin(), queries.end());
    // map<array<int, 2>, int> answers;
    // sort(parties.begin(), parties.end());
    // ordered_set<pair<int, int>> r_seen_so_far;
    // int idx = 1;
    // for (auto query : queries) {
    //   while (!parties.empty() && parties.front().first <= query[0]){
    //     r_seen_so_far.insert({parties.front().second, idx++});
    //     parties.pop_front();
    //   }
    //   answers[query] = r_seen_so_far.size() - r_seen_so_far.order_of_key({query[1] - 1, MOD});
    // }
    // for (int i = 0; i < n; i++) {
    //   answer[i] += answers[{ages[i], ages[boss[i]]}];
    //   answer[i] += answers[{highest_child[i], ages[i]}];
    //   answer[i] -= answers[{highest_child[i], lowest_boss[i]}];
    //   // queries.pb({ages[i], ages[boss[i]]});
    //   // queries.pb({highest_child[i], ages[i]});
    //   // queries.pb({highest_child[i], lowest_boss[i]});
    // }
    // for (auto it: answer){
    //   cout << it << " ";
    // }

    int n, m;
    cin >> n >> m;

    vector<int> ages(n);
    vector<int> parent(n, -1);
    vector<vector<int>> children(n);
    for (int i = 0; i < n; i++) {
      cin >> ages[i] >> parent[i];
      parent[i]--;
      if (parent[i] != i)
      children[parent[i]].push_back(i);
    }
    vector<vector<int>> l_queries(n);
    vector<vector<int>> indices_used_for_insertion(n);

    int log = 17;
    vector<vector<int>> lifting_parent(log, vector<int>(n, 0));
    for (int i = 0; i < n; i++){
      lifting_parent[0][i] = parent[i];
    }
      for (int i = 1; i < log; i++) {
        for (int j = 0; j < n; j++){
          lifting_parent[i][j] = lifting_parent[i - 1][lifting_parent[i - 1][j]];
        }
      }

      

      for (int i = 0; i < m; i++) {
        int node, l, r;
        cin >> node >> l >> r;
        node--;
        int curr_node = node;
        for (int j = log - 1; j >= 0; j--) {
          if (ages[lifting_parent[j][curr_node]] <= r) {
            curr_node = lifting_parent[j][curr_node];
          }
        }
        debug(node, l, r, curr_node);
        l_queries[curr_node].push_back(l);
      }
    debug(l_queries);

    vector<int> answers(n);
    SegmentTree<int> seg(100010);
    function<void(int, int)> dfs = [&](int i, int parent) {
      for (auto it : l_queries[i]){
        seg.update(it, 1);
      }

      answers[i] = seg.sum(0, ages[i]);

      for (auto child : children[i]){
        if (child != parent && child != i){
          dfs(child, i);
        }
      }


      int idx = 0;
      for (auto it : l_queries[i]) {
        seg.update(it, -1);
      }
    };
    dfs(0, -1);
    for (auto it : answers)
      cout << it << " ";
}
