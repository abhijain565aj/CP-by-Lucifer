#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int long long
void solve();
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int testCases = 1;
  cin >> testCases;
  for (int tt = 1; tt <= testCases; tt++) {
    solve();
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> val(n);
  for (int i = 0; i < n; i++) cin >> val[i];
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  int ans = m;
  vector<int> pq;
  for (int i = n - 1; i >= 0; i--) {
    for (auto x : a[i]) pq.push_back(x);
    sort(pq.begin(), pq.end());
    reverse(pq.begin(), pq.end());
    pq.resize(m);
    vector<int> pref(m + 1, 0);
    for (int i = 0; i < m; i++)
      pref[i + 1] = pref[i] + pq[i];
    for (int j = 0; j <= m; j++) {
      if (pref[j] >= val[i]) ans = min(ans, j);
    }
  }
  cout << ans << endl;
}