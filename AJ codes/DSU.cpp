#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> parent, size;
  int components;
  DSU(int n) {
    parent.resize(n);
    size.resize(n, 1);
    components = n;
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }
  int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
  }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      if (size[x] < size[y])
        swap(x, y);
      parent[y] = x;
      size[x] += size[y];
      components--;
    }
  }
  inline bool same(int x, int y) {
    return find(x) == find(y);
  }
  inline int getSize(int x) {
    return size[find(x)];
  }
  inline int getComponents() {
    return components;
  }
};
