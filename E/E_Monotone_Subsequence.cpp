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
#define TEST 0
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
constexpr int INF = 1e18;
vi perm;
int N;
vi query_test(vector<int>& ind) {
  if (ind.size() == 0) return {};
  vi ans;
  ans.pb(ind[0]);
  for (auto& i : ind) {
    if (perm[i] > perm[ans.back()]) ans.pb(i);
  }
  return ans;
}
bool check_answer(vi& ans) {
  if ((int)ans.size() != N + 1) {
    cout << "Wrong Size" << endl;
    return false;
  }
  // check monotonicity
  bool possible1 = true, possible2 = true;
  fo(i, ans.size() - 1) {
    if (perm[ans[i]] >= perm[ans[i + 1]]) {
      possible1 = false;
      break;
    }
  }
  fo(i, ans.size() - 1) {
    if (perm[ans[i]] <= perm[ans[i + 1]]) {
      possible2 = false;
      break;
    }
  }
  if (!possible1 && !possible2) {
    cout << "Not Monotonic" << endl;
    return false;
  } else {
    cout << "Correct Answer" << endl;
    return true;
  }
}
vi query(vector<int>& ind) {
  if (TEST) {
    return query_test(ind);
  }
  cout << "? " << ind.size() << " ";
  for (auto& x : ind) cout << x + 1 << " ";
  cout << endl;
  int sz;
  cin >> sz;
  vi res(sz);
  read(res, sz);
  for (auto& x : res) x--;
  return res;
};

vi query(set<int>& ind) {
  vi v;
  for (auto& x : ind) v.pb(x);
  return query(v);
};

void answer(vi ans) {
  while (ans.size() > N + 1) ans.pop_back();
  if (TEST) {
    check_answer(ans);
    return;
  }
  assert((int)ans.size() == N + 1);
  cout << "! ";
  for (auto& x : ans) cout << x + 1 << " ";
  cout << endl;
};
vector<int> MonotoneSubsequence(const vector<int>& a, bool increasing = true) {
  int n = a.size();

  // For LDS, negate values so problem reduces to LIS
  vector<int> b(n);
  for (int i = 0; i < n; i++)
    b[i] = increasing ? a[i] : -a[i];

  vector<int> d;              // current candidate tail values
  vector<int> pos;            // indices of tails
  vector<int> parent(n, -1);  // parent links for reconstruction

  for (int i = 0; i < n; i++) {
    int x = b[i];

    // strict increasing subsequence ⇒ use lower_bound
    int j = lower_bound(d.begin(), d.end(), x) - d.begin();

    if (j == (int)d.size()) {
      d.push_back(x);
      pos.push_back(i);
    } else {
      d[j] = x;
      pos[j] = i;
    }

    if (j > 0) parent[i] = pos[j - 1];
  }

  // reconstruct subsequence
  vector<int> indices;
  int idx = pos.back();
  while (idx != -1) {
    indices.push_back(idx);
    idx = parent[idx];
  }
  reverse(indices.begin(), indices.end());

  return indices;
}
void solve() {
  int n;
  if (!TEST) {
    cin >> N;
  }
  n = N * N + 1;
  if (N == 1) {
    vi a = {0, 1};
    answer(a);
    return;
  }
  set<int> s;
  fo(i, n) s.insert(i);
  vi a(n, -1);
  int mx = n;
  fo(i, N) {
    auto v = query(s);
    if (v.size() >= N + 1) {
      answer(v);
      return;
    }
    for (auto x : v) {
      s.erase(x);
    }
    for (int i = v.size() - 1; i >= 0; i--) {
      a[v[i]] = mx--;
    }
  }
  fo(i, n) if (a[i] == -1) a[i] = 0;
  // auto v1 = MonotoneSubsequence(a, true);
  auto ans = MonotoneSubsequence(a, false);
  answer(ans);
  debug(a);
}

signed main() {
  fastio;
  //   Error_file("0_Error.txt");
  int testCases = 1;
  cin >> testCases;

  if (TEST) {
    int n;
    cin >> n;
    N = n;
    n = n * n + 1;
    perm.resize(n);
    read(perm, n);
    // check permutation
    vi check(n + 1, 0);
    for (auto& x : perm) {
      if (x < 1 || x > n) {
        cout << "Invalid Permutation" << endl;
        return 0;
      }
      check[x]++;
      if (check[x] > 1) {
        cout << "Invalid Permutation" << endl;
        return 0;
      }
    }
  }
  fo(tt, testCases) {
    solve();
  }
}
