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
  int n;
  cin >> n;
  vi a(n);
  a[0] = 1;
  // 1 3 5 2 4 6 8 10 7 9
  // 0 modulo 5 done
  // 1 modulo 5 done
  // 2 modulo 5 = 11, 9 , 12
  // 3 modulo 5 11, 13, 9, 12
  // 4 modulo 5 12 14 11 13

  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (n <= 3) {
    cout << "NO SOLUTION\n";
    return 0;
  }
  fo(i, n / 5) {
    vi arr = {1, 3, 5, 2, 4};
    fo(j, 5) a[i * 5 + j] = arr[j] + i * 5;
  }
  if (n % 5 == 1) {
    a.back() = n;
  } else if (n % 5 == 2) {
    a[n - 1] = n;
    a[n - 2] = n - 3;
    a[n - 3] = n - 1;
  } else if (n % 5 == 3) {
    a[n - 1] = n - 1;
    a[n - 2] = n - 4;
    a[n - 3] = n;
    a[n - 4] = n - 2;
  } else if (n % 5 == 4) {
    a[n - 1] = n - 1;
    a[n - 2] = n - 3;
    a[n - 3] = n;
    a[n - 4] = n - 2;
  }
  print(a, n);
}
