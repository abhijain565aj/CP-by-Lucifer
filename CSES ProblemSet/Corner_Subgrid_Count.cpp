// Solution by Abhi Jain aka Lucifer aka abhijain565aj
// #pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("popcnt")

#include <bits/stdc++.h>
using namespace std;

#define fastio             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

constexpr int N = 3000;
bitset<N> a[N];

signed main() {
  fastio;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  long long ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      long long c = (a[i] & a[j]).count();
      ans += (c * (c - 1)) / 2;
    }
  cout << ans << endl;
}
