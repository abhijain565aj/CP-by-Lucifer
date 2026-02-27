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
#else
#define debug(...)
#define Test(tt)
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

void solve() {
  auto send_query = [&](vi& query) -> vi {
    auto cp = query;
    sortall(cp);
    cp.erase(unique(all(cp)), cp.end());
    int sz = cp.size();
    map<int, int> rename;
    cout << sz << endl;
    for (auto x : query)
      if (!rename.count(x)) rename[x] = rename.size() + 1;
    for (auto& x : query) cout << rename[x] << " ";
    cout << endl;
    vi ret(query.size());
    fo(i, sz) {
      int size;
      cin >> size;
      int x;
      fo(j, size) cin >> x, ret[x - 1] = size;
    }
    return ret;
  };

  int n;
  cin >> n;
  int x;
  for (x = 20; x >= 0; x--) {
    if (x * (x - 1) / 2 < n)
      break;
  }
  vector<int> sz(x);
  for (int i = 0; i < x; i++) {
    sz[i] = x - i;
  }
  int curr_sum = x * (x + 1) / 2;
  if (curr_sum != n) sz.erase(find(sz.begin(), sz.end(), curr_sum - n));

  vector<int> query1;
  for (auto s : sz) {
    fo(i, s) query1.pb(s);
  }
  reverse(all(query1));
  auto result1 = send_query(query1);

  vvi temp(sz.size());
  fo(i, (int)sz.size()) {
    fo(j, (int)sz[i]) {
      temp[j % sz.size()].pb(sz[i]);
    }
  }
  vi query2;
  for (auto& v : temp) {
    for (auto& x : v) query2.pb(x);
  }
  reverse(all(query2));
  auto result2 = send_query(query2);
  debug(query1, query2);
  debug(result1, result2);
  map<pii, vi> mp_mine, mp_their;
  fo(i, n) {
    mp_mine[{query1[i], query2[i]}].pb(i);
    mp_their[{result1[i], result2[i]}].pb(i);
  }
  debug(mp_mine, mp_their);
  vi answer(n, -1);
  // debug(mp_mine, mp_their);
  for (auto [key, v1] : mp_mine) {
    if (v1.size() > 1) continue;
    answer[mp_their[key][0]] = v1[0];
  }

  debug(answer);
  // debug(query1, query2);
  vi rev_ans(n, -1);
  fo(i, n) if (answer[i] != -1) rev_ans[answer[i]] = i;
  vvi query3;
  fo(i, n) if (rev_ans[i] == -1) {
    query3.pb({i});
  }
  int j = 0;
  fo(i, n) if (rev_ans[i] != -1) {
    if (j < query3.size()) {
      query3[j++].pb(i);
    } else {
      query3.pb({i});
    }
  }
  debug(query3);
  vi flat_query3(n);
  int cnt = 1;
  for (auto& v : query3) {
    for (auto& x : v) flat_query3[x] = cnt;
    cnt++;
  }
  map<int, int> query_pair;
  for (auto v : query3) {
    if (v.size() == 2) {
      query_pair[v[0]] = v[1];
      query_pair[v[1]] = v[0];
    }
  }
  cout << query3.size() << endl;
  for (auto& x : flat_query3) cout << x << " ";
  cout << endl;
  fo(i, query3.size()) {
    int size;
    cin >> size;
    vi temp(size);
    fo(j, size) cin >> temp[j];
    debug(temp);
    if (size == 1) continue;
    int x = temp[0];
    int y = temp[1];
    debug(x, y);
    if (answer[x - 1] != -1) swap(x, y);
    answer[x - 1] = query_pair[answer[y - 1]];
    // debug(sz, query1);
    debug(answer);
  }
  // for (auto x : answer) cout << x + 1 << " ";
  fo(i, n) rev_ans[answer[i]] = i + 1;
  for (auto x : rev_ans) cout << x << " ";
  cout << endl;
}
signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1;
  // cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
