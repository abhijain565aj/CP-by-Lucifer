// Solution by Abhi Jain aka Lucifer aka abhijain565aj
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> // find_by_order, order_of_key

#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "./0_debug.cpp"
#else
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

#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pll pair<ll, ll>
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

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define read(a, n) for (int i = 0; i < n; ++i) cin >> a[i];
#define print_space(a, n) for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');

struct SegmentTreeData {
    ll sum, pref, suff, ans;
};
SegmentTreeData Tree[900000];

SegmentTreeData combine(SegmentTreeData left, SegmentTreeData right) {
    SegmentTreeData result;
    result.sum = left.sum + right.sum;
    result.pref = max(left.pref, left.sum + right.pref);
    result.suff = max(right.suff, right.sum + left.suff);
    result.ans = max({left.ans, right.ans, left.suff + right.pref});
    return result;
}

SegmentTreeData makeData(ll val) {
    SegmentTreeData result;
    result.sum = val;
    result.pref = result.suff = result.ans = max(0ll, val);
    return result;
}

void buildTree(ll arr[], ll node, ll start, ll end) {
    if (start == end) {
        Tree[node] = makeData(arr[start]);
    } else {
        ll mid = (start + end) / 2;
        buildTree(arr, 2 * node + 1, start, mid);
        buildTree(arr, 2 * node + 2, mid + 1, end);
        Tree[node] = combine(Tree[2 * node + 1], Tree[2 * node + 2]);
    }
}

void updateTree(ll node, ll start, ll end, ll pos, ll newValue) {
    if (start == end) {
        Tree[node] = makeData(newValue);
    } else {
        ll mid = (start + end) / 2;
        if (pos <= mid)
            updateTree(2 * node + 1, start, mid, pos, newValue);
        else
            updateTree(2 * node + 2, mid + 1, end, pos, newValue);
        Tree[node] = combine(Tree[2 * node + 1], Tree[2 * node + 2]);
    }
}

SegmentTreeData queryTree(ll node, ll start, ll end, ll left, ll right) {
    if (left > right)
        return makeData(0);
    if (left == start && right == end)
        return Tree[node];
    ll mid = (start + end) / 2;
    return combine(
        queryTree(2 * node + 1, start, mid, left, min(right, mid)),
        queryTree(2 * node + 2, mid + 1, end, max(left, mid + 1), right)
    );
}

void solve() {
    ll n;
    cin >> n;
    ll arr[n];
    read(arr, n);
    buildTree(arr, 0, 0, n - 1);
    ll q;
    cin >> q;
    while (q--) {
        ll type, b, c;
        cin >> type >> b >> c;
        if (type == 1) {
            updateTree(0, 0, n - 1, b - 1, c);
        } else {
            cout << queryTree(0, 0, n - 1, b - 1, c - 1).ans << endl;
        }
    }
}

int main() {
    fastio;
    Error_file("0_Error.txt");
    int testCases = 1;
    cin >> testCases;
    fo(tt, testCases) {
        test(tt + 1);
        solve();
    }
    test(0);
}
