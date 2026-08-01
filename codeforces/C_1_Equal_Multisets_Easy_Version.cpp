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
#include "./DEBUG.cpp"
#define local true
#else
#define debug(...)
#define Test(tt)
#define Error_file(x)
#define local false
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

#define fo(i, n) for (int i = 0; i < n; i++)
#define re(i, n) for (int i = n - 1; i >= 0; i--)
#define loop(i, a, b) for (int i = a; (a >= b) ? i >= b : i <= b; (a >= b) ? i-- : i++)

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
  int n, k;
  cin >> n >> k;

  vi a(n), b(n);
  read(a, n);
  read(b, n);

  multiset<int> curr_a, curr_b, minus;
  int cnt = 0, mc = 0;
  auto add = [&](int i) {
    if (curr_b.find(a[i]) != curr_b.end()) {
      curr_b.erase(curr_b.find(a[i]));
    } else {
      curr_a.insert(a[i]);
    }
    if (b[i] != -1) {
      if (curr_a.find(b[i]) != curr_a.end()) {
        curr_a.erase(curr_a.find(b[i]));
      } else {
        curr_b.insert(b[i]);
      }
    } else
      mc++;
  };
  // for (int i = 0; i < k - 1; i++) {
  //   add(i);
  // }
  // debug(curr_a, curr_b);
  // for (int i = k - 1; i < n; i++) {
  //   add(i);

  //   if ((int)curr_b.size() > cnt || (int)curr_a.size() > mc) {
  //     cout << "NO" << endl;
  //     return;
  //   }

  //   while ((int)curr_a.size() > 0) {
  //     minus.insert(*curr_a.begin());
  //     curr_a.erase(curr_a.begin());
  //     mc--;
  //   }

  //   if (minus.find(a[i - k + 1]) != minus.end()) {
  //     curr_b.insert(a[i - k + 1]);
  //     minus.erase(minus.find(a[i - k + 1]));
  //     mc++;
  //   }

  //   if (b[i - k + 1] == -1) {
  //     cnt++;
  //     mc--;
  //   } else if (curr_b.find(b[i - k + 1]) != curr_b.end()) {
  //     curr_b.erase(curr_b.find(b[i - k + 1]));
  //   }
  // }
  // cout << "YES" << endl;
  fo(i, n) if (i >= k || i < n - k) {
    if (a[i] != b[i] && b[i] != -1) {
      cout << "NO" << endl;
      return;
    }
  }
  else {
    add(i);
  }
  if ((int)curr_a.size() > mc) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  return;
}
