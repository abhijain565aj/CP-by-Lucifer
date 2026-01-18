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

vi brute(int n, int k) {
  vector<int> a(k), best(k);
  long long mxsum = -1;

  function<void(int, int)> dfs = [&](int idx, int cur_xor) {
    if (idx == k - 1) {
      int last = cur_xor ^ n;
      if (last < 0 || last > n) return;

      a[idx] = last;

      long long sum = 0;
      for (int i = 0; i < k; i++) sum += a[i];

      if (sum > mxsum) {
        mxsum = sum;
        best = a;
      }
      return;
    }

    for (int x = 0; x <= n; x++) {
      a[idx] = x;
      dfs(idx + 1, cur_xor ^ x);
    }
  };

  dfs(0, 0);
  return best;
}

void solve1() {
  int n, k;
  cin >> n >> k;
  debug(brute(n, k));
  vi a(k, n);
  if (k % 2 == 0) {
    int cnt = 31 - __builtin_clz(n);
    a.back() = (1 << cnt) - 1;
    a[k - 2] = n ^ a.back();
    cnt--;
    while (a[k - 2] > n) {
      int v = 1 << cnt;
      if (a[k - 2] & v) {
        a[k - 2] ^= v;
        a.back() ^= v;
      }
      cnt--;
    }
  }
  print_space(a, k);
}

void solve() {
  int n, k;
  cin >> n >> k;

  // k odd → all n is optimal
  if (k & 1) {
    vi a(k, n);
    print_space(a, k);
    return;
  }

  // k even → optimize using 4 numbers
  vi a(k, 0);
  int use = min(4LL, k);

  // brute-inspired bit redistribution
  for (int bit = 0; bit <= 30; bit++) {
    int want = (n >> bit) & 1;

    int cnt = use;
    if ((cnt & 1) != want) cnt--;

    for (int i = 0; i < cnt; i++) {
      if ((a[i] | (1LL << bit)) <= n)
        a[i] |= (1LL << bit);
    }
  }

  // fix XOR if needed
  int cur = 0;
  for (int i = 0; i < use; i++) cur ^= a[i];
  a[0] ^= (cur ^ n);

  print_space(a, k);
}

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1000;
  cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    solve1();
  }
}
