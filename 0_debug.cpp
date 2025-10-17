#pragma once
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define F first
#define S second
#ifndef ONLINE_JUDGE

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", _print(__VA_ARGS__)

#define Test(tt) \
  cerr << "----------------------------\n" + ((tt != 0) ? ("Case #" + to_string(tt) + ": \n") : "");

#define Error_file(x) freopen(x, "w", stderr);
#endif

bool color_enabled = false;
int __index__ = 0;
string reset_color = "\033[0m";
vector<string> __colors__ = {
    "\033[1;31m",  // Red
    "\033[1;32m",  // Green
    "\033[1;33m",  // Yellow
    "\033[1;34m",  // Blue
    "\033[1;35m",  // Magenta
    "\033[1;36m",  // Cyan
};
#define set_color(os) \
  if (color_enabled) os << __colors__[__index__];
#define reset_color(os) \
  if (color_enabled) os << reset_color;

#define increment_color(os)                        \
  __index__ = (__index__ + 1) % __colors__.size(); \
  if (color_enabled) os << __colors__[__index__];
#define decrement_color(os)                                            \
  __index__ = (__index__ - 1 + __colors__.size()) % __colors__.size(); \
  if (color_enabled) os << __colors__[__index__];
string space = "";
#define arr_print(os, a)           \
  set_color(os);                   \
  os << "\n" + space + "[ ";       \
  space.push_back(' ');            \
  increment_color(os);             \
  reset_color(os);                 \
  for (auto i : a) os << i << " "; \
  decrement_color(os);             \
  set_color(os);                   \
  space.pop_back();                \
  os << "]";                       \
  reset_color(os);                 \
  return os;

template <typename T, typename V>
ostream& operator<<(ostream& os, const pair<T, V>& p);
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& p);
template <typename T>
ostream& operator<<(ostream& os, const deque<T>& p);
template <typename T>
ostream& operator<<(ostream& os, const set<T>& p);
template <typename T>
ostream& operator<<(ostream& os, const unordered_set<T>& p);
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& p);
template <typename T>
ostream& operator<<(ostream& os, const unordered_multiset<T>& p);
template <typename T, typename V>
ostream& operator<<(ostream& os, const map<T, V>& p);
template <typename T, typename V>
ostream& operator<<(ostream& os, const unordered_map<T, V>& p);
template <size_t S>
ostream& operator<<(ostream& os, const bitset<S>& p);
template <typename T, size_t S>
ostream& operator<<(ostream& os, const array<T, S>& p);

template <typename T, typename V>
ostream& operator<<(ostream& os, const pair<T, V>& p) {
  os << "(";
  increment_color(os);
  os << p.first << ", " << p.second;
  decrement_color(os);
  os << ")";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& p) { arr_print(os, p) }
template <typename T>
ostream& operator<<(ostream& os, const deque<T>& p) { arr_print(os, p) }
template <typename T>
ostream& operator<<(ostream& os, const set<T>& p) { arr_print(os, p) }
template <typename T>
ostream& operator<<(ostream& os, const unordered_set<T>& p) { arr_print(os, p) }
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& p) { arr_print(os, p) }
template <typename T>
ostream& operator<<(ostream& os, const unordered_multiset<T>& p) { arr_print(os, p) }
template <typename T, typename V>
ostream& operator<<(ostream& os, const map<T, V>& p) { arr_print(os, p) }
template <typename T, typename V>
ostream& operator<<(ostream& os, const unordered_map<T, V>& p) { arr_print(os, p) }
template <size_t S>
ostream& operator<<(ostream& os, const bitset<S>& p) {
  os << p.to_string();
  return os;
}
template <typename T, size_t S>
ostream& operator<<(ostream& os, const array<T, S>& p) { arr_print(os, p) }

inline void _print() { cerr << endl; }
template <typename T, typename... V>
void _print(const T& t, const V&... v) {
  cerr << t;
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}