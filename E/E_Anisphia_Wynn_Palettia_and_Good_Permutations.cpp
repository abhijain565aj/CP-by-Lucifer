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

#define fo(i, n) for (ll i = 0; i < n; i++)
#define re(i, n) for (decltype(n) i = n - 1; i >= 0; i--)
#define fo1(i, a, b) for (ll i = a; i < b; i++)
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
constexpr int N = 2e5 + 10;
constexpr int INF = 1e18;

vi prime(N, 0);
vi primes;
void solve() {
  int n;
  cin >> n;
  map<int, vi> mp;
  for (int i = 1; i <= n; i++) {
    mp[prime[i]].pb(i);
  }
  int ind = 0;
  for (; ind < (int)primes.size(); ind++)
    if (primes[ind] * primes[ind + 1] > n) break;

  debug(ind);
  vi ans;
  for (int i = 1; i < ind; i++) {
    int v = primes[i] * primes[i + 1];
    auto& vec = mp[primes[i]];
    vec.erase(find(all(vec), v));
    vec.pb(v);
    ans.insert(ans.end(), all(vec));
    mp[primes[i]].clear();
  }
  ans.insert(ans.end(), all(mp[primes[ind]]));
  mp[primes[ind]].clear();

  vi rem;
  for (auto& [it, v] : mp) {
    rem.insert(rem.end(), all(v));
  }
  // interleave ans and rem
  int i = 0;
  for (; 2 * i + 1 < (int)ans.size() && i < (int)rem.size(); i++) {
    cout << rem[i] << " " << ans[2 * i] << " " << ans[2 * i + 1] << " ";
  }
  for (int j = 2 * i; j < (int)ans.size(); j++) cout << ans[j] << " ";
  for (int j = i; j < (int)rem.size(); j++) cout << rem[j] << " ";
  cout << endl;
}

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1000;
  cin >> testCases;
  prime[0] = -1, prime[1] = 1;
  fo1(i, 2, N) {
    if (prime[i] == 0) {
      for (int j = i; j < N; j += i) {
        if (prime[j] == 0) prime[j] = i;
      }
    }
  }
  fo(i, N) if (prime[i] == i) primes.pb(i);
  fo(tt, testCases) {
    Test(tt + 1);
    solve();
  }
}
