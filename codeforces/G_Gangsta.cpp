// Solution by Abhi Jain aka Lucifer aka abhijain565aj
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
<<<<<<< HEAD
=======

>>>>>>> 3dfbb67 (cm commits)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;
<<<<<<< HEAD

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
template<class T>
using ordered_multiset =  tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;
=======
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
>>>>>>> 3dfbb67 (cm commits)
// find_by_order, order_of_key

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "./0_debug.cpp"
#else
<<<<<<< HEAD
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define test(tt)
#define Error_file(x)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define MOD 1000000007
#define INF 1e18
=======
#define debug(...)
#define Test(tt)
#define Error_file(x)
#endif

#define int long long
typedef long long ll;
typedef long double ld;
>>>>>>> 3dfbb67 (cm commits)

#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
<<<<<<< HEAD
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pll pair<ll, ll>
=======
#define vvi vector<vi>
#define pii pair<int, int>
>>>>>>> 3dfbb67 (cm commits)
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
<<<<<<< HEAD
// a.resize(unique(all(a)) - a.begin());  -> unque element me convert karta hai

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define read(a, n) for (int i = 0; i < n; ++i) cin >> a[i];
#define print_space(a, n) for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');
#define int ll
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi a(n);
    fo(i,n) s[i] = s[i]-'0';
    vi sum(n);
    sum[0] = 2*s[0]-1;
    fo1(i,1,n) sum[i] = sum[i-1] + (2*s[i]-1);
    ordered_set<pll> st;
    ll ans = 0;
    st.insert({0, -1});
    fo(i,n){
        if(s[i]==1) ans += st.order_of_key(make_pair(sum[i], +INF));
        else ans += st.size()-st.order_of_key(make_pair(sum[i], -INF));
        st.insert(make_pair(sum[i], i));
        debug3(i, sum[i], ans);
    }
    cout << ans << endl;
}

signed main()
{
    fastio; 
    // Error_file("0_Error.txt");
    int testCases = 1;
    cin >> testCases;
    fo(tt, testCases){
        test(tt + 1);
        solve();
    }
    test(0);
=======
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
  int n;
  cin >> n;
  string s;
  cin >> s;
  int lhs = (n * (n + 1) * (n + 2)) / 6;
  debug(lhs);
  vi diff(n);
  fo(i, n) diff[i] = ((s[i] == '1') ? 1 : -1) + (i > 0 ? diff[i - 1] : 0);
  debug(diff);
  sortall(diff);
  vi pref(n);
  fo(i, n) pref[i] = (i > 0 ? pref[i - 1] : 0) + diff[i];
  debug(diff, pref);
  int rhs = 0;
  fo(i, n) {
    rhs += (diff[i] * (i + 1) - pref[i]);
    rhs += abs(diff[i]) * 2;
    rhs += (pref[n - 1] - pref[i] - diff[i] * (n - i - 1));
  }
  cout << (lhs * 2 + rhs) / 4 << endl;
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
>>>>>>> 3dfbb67 (cm commits)
}
