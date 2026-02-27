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

signed main() {
  fastio;
  int n, m, q;
  cin >> n >> m >> q;
  vi a(n), b(m);
  read(a, n);
  read(b, m);
  int sumA = accumulate(all(a), 0LL);
  int sumB = accumulate(all(b), 0LL);
  fo(i, n) a[i] = sumA - a[i];
  fo(i, m) b[i] = sumB - b[i];
  unordered_map<int, int> freqA, freqB;
  fo(i, n) freqA[a[i]]++;
  fo(i, m) freqB[b[i]]++;
  while (q--) {
    int x;
    cin >> x;
    bool done = false;
    for (int i = 1; i <= sqrt(abs(x)); i++) {
      if (x % i == 0) {
        int f1 = i;
        int f2 = x / i;
        if ((freqA[f1] && freqB[f2]) || (freqA[f2] && freqB[f1])) {
          done = true;
          // cout << f1 << " " << f2 << "\n";
          cout << "YES\n";
          break;
        }
        f1 *= -1;
        f2 *= -1;
        if ((freqA[f1] && freqB[f2]) || (freqA[f2] && freqB[f1])) {
          done = true;
          // cout << f1 << " " << f2 << "\n";
          cout << "YES\n";
          break;
        }
      }
    }
    if (!done) cout << "NO\n";
  }
}
