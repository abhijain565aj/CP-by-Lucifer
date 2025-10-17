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
#define TEST 1
#else
#define debug(...)
#define Test(tt)
#define Error_file(x)
#define TEST 0
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
vi test = {1, 4, 3, 4, 5, 1, 2, 3, 5};  // for testing purpose only
void solve() {
  int n;
  if (TEST) {
    n = (test.size() + 1) / 2;
  } else {
    cin >> n;
  }

  vi a(2 * n - 1);
  fo(i, 2 * n - 1) a[i] = i + 1;
  int cnt = 4 * n + 2 * ceil(log2(n));

  map<int, vi> mp;
  for (int i = 1; i <= n; i++) mp[i] = a;

  auto seed = random_device{}();
  shuffle(a.begin(), a.end(), mt19937(seed));
  auto query = [&](int x, vi& b) {
    sortall(b);
    cnt--;
    cout << "? " << x << " " << b.size() << " ";
    for (auto x : b) cout << x << " ";
    cout << endl;
    int a1 = 0;
    if (TEST) {
      for (int i : b) {
        if (test[i - 1] == x) a1 = 1;
      }
    } else {
      cin >> a1;
    }
    debug(a1);
    return a1;
  };

  auto ask = [&](int x) -> bool {
    vi L, R;
    vi b = mp[x];
    if (mp[x].size() <= 1) return false;
    // shuffle(b.begin(), b.end(), mt19937(seed));
    int half = b.size() / 2;
    L.assign(b.begin(), b.begin() + half);
    R.assign(b.begin() + half, b.end());

    if (L.empty() || R.empty()) return false;
    if (cnt == 0) return false;

    int a1 = query(x, L);
    if (a1 == 0) {
      mp[x] = R;
      return false;
    } else {
      mp[x] = L;
    }
    if (cnt == 0) return false;
    int a2 = query(x, R);
    cnt--;
    return a1 && a2;
  };

  vi b;
  fo(i, n) b.pb(i + 1);
  shuffle(b.begin(), b.end(), mt19937(seed));
  for (auto x : b) {
    while (!ask(x) && cnt > 0) {
      if (mp[x].size() == 1) {
        cout << "! " << x << endl;
        return;
      }
    }
  }
  cout << "! " << -1 << endl;
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
