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

void solve(int n, int k);

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1;
  cin >> testCases;
  fo(tt, testCases) {
    Test(tt + 1);
    int n, k;
    cin >> n >> k;
    // fo(i, 20) fo(k, 2 * i)
    solve(n, k);
  }
}
#define Yes \
  cout << "YES\n";
#define No \
  cout << "NO\n";

int count_moves(const vector<int>& a) {
  int m = a.size();  // = 2n
  vector<bool> alive(m, true);
  vector<bool> seen(m, false);  // flipped in previous turns

  int alive_cnt = m;
  int turns = 0;

  while (alive_cnt > 0) {
    turns++;

    // 1) Two previously flipped equal cards
    bool done = false;
    for (int i = 0; i < m && !done; i++) {
      if (!alive[i] || !seen[i]) continue;
      for (int j = i + 1; j < m; j++) {
        if (alive[j] && seen[j] && a[i] == a[j]) {
          alive[i] = alive[j] = false;
          alive_cnt -= 2;
          done = true;
          break;
        }
      }
    }
    if (done) continue;

    // 2) Flip first never-flipped alive card
    int first = -1;
    for (int i = 0; i < m; i++) {
      if (alive[i] && !seen[i]) {
        first = i;
        break;
      }
    }

    int x = a[first];

    // 3) Match with previously flipped card
    int match = -1;
    for (int i = 0; i < m; i++) {
      if (alive[i] && seen[i] && a[i] == x) {
        match = i;
        break;
      }
    }

    if (match != -1) {
      alive[first] = alive[match] = false;
      alive_cnt -= 2;
      continue;
    }

    // 4) Flip second never-flipped alive card
    int second = -1;
    for (int i = first + 1; i < m; i++) {
      if (alive[i] && !seen[i]) {
        second = i;
        break;
      }
    }

    // If first and second match → discard immediately
    if (a[first] == a[second]) {
      alive[first] = alive[second] = false;
      alive_cnt -= 2;
    } else {
      // end of turn → now they become previously flipped
      seen[first] = true;
      seen[second] = true;
    }
  }
  debug(a, turns);
  return turns;
}
void solve(int n, int k) {
  if (k < n) {
    No;
    return;
  }
  debug(n, k);
  if (n == 1) {
    if (k == 1) {
      Yes;
      cout << "1 1\n";
    } else {
      No;
    }
    return;
  }
  if (n == 2) {
    if (k == 2) {
      Yes;
      cout << "1 1 2 2\n";
    } else if (k == 3) {
      Yes;
      cout << "1 2 1 2\n";
    } else {
      No;
    }
    return;
  }

  if (n == 3) {
    if (k >= 3 && k <= 5) {
      Yes;
      if (k == 3) {
        cout << "1 1 2 2 3 3\n";
      } else if (k == 4) {
        cout << "1 2 1 2 3 3\n";
      } else {
        cout << "1 2 3 1 2 3\n";
      }
    } else {
      No;
    }
    return;
  }
  if (k == n) {
    Yes;
    for (int i = 1; i <= n; i++) {
      cout << i << ' ' << i << ' ';
    }
    cout << endl;
    return;
  }
  k -= n;
  int mx = n - 1;
  if (k > mx) {
    No;
    return;
  }
  vi ans;
  int formation = (k + 1);
  debug(formation);
  ans.pb(1);
  ans.pb(2);
  for (int i = 3; i <= formation; i++) {
    ans.pb(i);
    ans.pb(i - 2);
  }
  ans.pb(formation - 1);
  ans.pb(formation);
  for (int i = formation + 1; i <= n; i++) {
    ans.pb(i);
    ans.pb(i);
  }
  Yes;
  print_space(ans, 2 * n);
  // assert(count_moves(ans) == k + n);
}
