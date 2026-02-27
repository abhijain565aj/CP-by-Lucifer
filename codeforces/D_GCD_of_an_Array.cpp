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
constexpr int N = 2e5 + 1;
constexpr int INF = 1e18;

vvi pf(N);

signed main() {
  fastio;
  for (int i = 2; i < N; i++) {
    if (pf[i].empty()) {
      for (int j = i; j < N; j += i) {
        int j1 = j;
        while (j1 % i == 0) {
          j1 /= i;
          pf[j].pb(i);
        }
      }
    }
  }

  int n, q;
  cin >> n >> q;
  vi a(n);
  read(a, n);
  vector<map<int, int>> mp(n);
  fo(i, n) for (int p : pf[a[i]]) {
    mp[i][p]++;
  }
  map<int, int> mp_orig;
  map<int, multiset<int>> mp_set;
  map<int, int> mp_0cnt;
  mp_orig = mp[0];
  fo(i, n) for (auto& [p, c] : mp[i]) {
    mp_set[p].insert(c);
    mp_orig[p] = min(mp_orig[p], c);
    mp_0cnt[p]--;
  }
  int gcd = 1;
  for (auto& [p, c] : mp_0cnt) {
    c += n;
    if (c != 0) {
      mp_orig[p] = 0;
    }
    gcd *= pow(p, mp_orig[p]);
  }
  debug(mp_orig, mp_set, mp_0cnt);
  while (q--) {
    int i, x;
    cin >> i >> x;
    i--;
    for (int p : pf[x]) {
      int old_c = mp[i][p];
      if (old_c == 0) {
        if (mp_0cnt[p] == 0) {
          mp_0cnt[p] = n;
        }
        mp_0cnt[p]--;
      }
      auto ptr = mp_set[p].find(old_c);
      if (ptr != mp_set[p].end()) mp_set[p].erase(ptr);
      mp[i][p]++;
      mp_set[p].insert(mp[i][p]);

      int no = *mp_set[p].begin();
      if (no > mp_orig[p] && mp_0cnt[p] == 0) {
        gcd = (gcd * p) % MOD;
        mp_orig[p] = no;
      }
    }
    debug(mp_orig, mp_set, mp_0cnt);
    cout << gcd << endl;
  }
}
