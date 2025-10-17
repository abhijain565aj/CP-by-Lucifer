#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream& operator<<(ostream& os, const T_container& v) {
  os << '{';
  string sep;
  for (const T& x : v) os << sep << x, sep = ", ";
  return os << '}';
}
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
istream& operator>>(istream& is, T_container& v) {
  for (T& x : v) is >> x;
  return is;
}

#define MOD 1000000007

void yn(bool possible) {
  cout << ((possible) ? "Yes" : "No") << "\n";
}

auto max(auto x, auto y) { return x > y ? x : y; }
auto min(auto x, auto y) { return x < y ? x : y; }

#define print(n) cout << (n) << "\n"

template <typename T>

void read(T a[], int n, int offset = 0) {
  for (int i = 0; i < n; i++) {
    cin >> a[i + offset];
  }
}

template <typename T>

void read(std::vector<T>& a, int n, int offset = 0) {
  for (int i = 0; i < n; i++) {
    cin >> a[i + offset];
  }
}

#define read_2d(a, n, m)        \
  for (int i = 0; i < n; i++)   \
    for (int j = 0; j < m; j++) \
      cin >> a[i][j];

#define read_pair(a, n)       \
  for (int i = 0; i < n; i++) \
    cin >> a[i].first >> a[i].second;

typedef long long ll;
#define int long long
ll determinant(vector<vector<ll>> a) {
  int n = a.size();
  if (n == 1) return a[0][0];
  ll det = 0;
  for (int col = 0; col < n; ++col) {
    vector<vector<ll>> submatrix(n - 1, vector<ll>(n - 1));
    for (int i = 1; i < n; ++i) {
      int sub_col = 0;
      for (int j = 0; j < n; ++j) {
        if (j == col) continue;
        submatrix[i - 1][sub_col++] = a[i][j];
      }
    }
    det += (col % 2 == 0 ? 1 : -1) * a[0][col] * determinant(submatrix);
  }
  return det;
}

// Check if tetrahedron with given 6 sides has positive volume
bool hasPositiveVolume(const vector<ll>& s) {
  // for (auto x : s)
  //   cout << x << ' ';
  // s = {a, b, c, d, e, f}
  vector<vector<ll>> M(5, vector<ll>(5, 1));

  M[0][0] = 0;
  M[1][1] = 0;
  M[1][2] = s[0] * s[0];
  M[1][3] = s[1] * s[1];
  M[1][4] = s[2] * s[2];
  M[2][1] = s[0] * s[0];
  M[2][2] = 0;
  M[2][3] = s[3] * s[3];
  M[2][4] = s[4] * s[4];
  M[3][1] = s[1] * s[1];
  M[3][2] = s[3] * s[3];
  M[3][3] = 0;
  M[3][4] = s[5] * s[5];
  M[4][1] = s[2] * s[2];
  M[4][2] = s[4] * s[4];
  M[4][3] = s[5] * s[5];
  M[4][4] = 0;
  ll det = determinant(M);
  // cerr << "Determinant: " << det << "\n";
  return det > 0;
}

pair<int, int> check_common(map<int, vector<int>>& x, map<int, vector<int>>& y, int i, int j) {
  for (auto& it : x) {
    if (y.find(it.first) != y.end()) {
      auto& v1 = it.second;
      auto& v2 = y[it.first];
      if (v1.size() < v2.size()) {
        for (auto& idx1 : v1) {
          if (idx1 == i || idx1 == j)
            continue;
          for (auto& idx2 : v2) {
            if (idx2 != i && idx2 != j && idx1 != idx2)
              return {idx1, idx2};
          }
        }
      } else {
        for (auto& idx2 : v2) {
          if (idx2 == i || idx2 == j)
            continue;
          for (auto& idx1 : v1) {
            if (idx1 != i && idx1 != j && idx1 != idx2)
              return {idx1, idx2};
          }
        }
      }
    }
  }
  return {-1, -1};
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(3));
  map<vector<int>, map<int, vector<int>>> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    sort(a[i].begin(), a[i].end());
    mp[{a[i][0], a[i][1]}][a[i][2]].push_back(i);
    mp[{a[i][0], a[i][2]}][a[i][1]].push_back(i);
    mp[{a[i][1], a[i][2]}][a[i][0]].push_back(i);
  }
  for (auto& it : mp)
    for (auto& it2 : it.second)
      sort(it2.second.begin(), it2.second.end());
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int idx1 = 0; idx1 <= 2; idx1++) {
        for (int idx2 = 0; idx2 <= 2; idx2++) {
          if (a[i][idx1] == a[j][idx2]) {
            vector<int> key1, key2;
            for (int k = 0; k <= 2; k++) {
              if (k != idx1)
                key1.push_back(a[i][k]);
              if (k != idx2)
                key2.push_back(a[j][k]);
            }
            auto& x = mp[key1];
            auto& y = mp[key2];
            pair<int, int> c = check_common(x, y, i, j);
            if (c.first != -1 && hasPositiveVolume({a[i][idx1], key1[0], key1[1], key2[1], key2[0], a[j][idx2]})) {
              cout << "Yes\n";
              cout << i + 1 << " " << j + 1 << " " << c.first + 1 << " " << c.second + 1 << "\n";
              return;
            }
          }
        }
      }
    }
  }
  print("No");
}
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  solve();
}