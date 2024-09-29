// Solution by Abhi Jain aka Lucifer aka abhijain565aj
// Mera solution kyun dekh rha?? ... (｡◕‿‿◕｡)

// Template maine nhi banaya he pura, codeforces pe dusro k solutions se inspired template he ...
// Kudos to them ❤

#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> // find_by_order, order_of_key

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
#define nextL cout << "\n"

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
// a.resize(unique(all(a)) - a.begin());  -> unque element me convert karta hai

#define read(a, n)              \
    for (int i = 0; i < n; ++i) \
        cin >> a[i];
#define print_space(a, n)         \
    for (int i = 0; i < n; ++i)   \
        if (i == n - 1)           \
            cout << a[i] << "\n"; \
        else                      \
            cout << a[i] << ' ';
#ifndef ONLINE_JUDGE
#include "D:/CodeForces/0_debug.cpp"
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define test(tt)
#define printTC(tc)
#endif

// min_max functions
template <typename T>
T max3(T a, T b, T c)
{
    return max(a, max(b, c));
}
template <typename T>
T max4(T a, T b, T c, T d)
{
    return max(max(a, d), max(b, c));
}
template <typename T>
T min3(T a, T b, T c)
{
    return min(a, min(b, c));
}
template <typename T>
T min4(T a, T b, T c, T d)
{
    return min(min(a, d), min(b, c));
}

/*
|     /\     |  _ \  | |  | | |_   _| ( )          / ____|  / __ \  |  __ \  |  ____| |
|    /  \    | |_) | | |__| |   | |   |/   ___    | |      | |  | | | |  | | | |__    |
|   / /\ \   |  _ <  |  __  |   | |       / __|   | |      | |  | | | |  | | |  __|   |
|  / ____ \  | |_) | | |  | |  _| |_      \__ \   | |____  | |__| | | |__| | | |____  |
| /_/    \_\ |____/  |_|  |_| |_____|     |___/    \_____|  \____/  |_____/  |______| |
*/
struct LazySegmentTree
{
    vector<ll> tree; // segment tree
    vector<ll> lazy; // lazy tree
    ll n;            // size of the array
    // lazy tree is used to store the pending updates
    LazySegmentTree(ll n)
    {
        this->n = n;
        tree.resize(4 * n); // size of the segment tree is 4 times the size of the array
        lazy.resize(4 * n); // size of the lazy tree is 4 times the size of the array
    }
    void build(vector<ll> &a)
    {
        buildp(a, 1, 0, n - 1);
    }
    ll sum(ll l, ll r)
    {
        return sump(1, 0, n - 1, l, r);
    }
    void update(ll l, ll r, ll val)
    {
        updatep(1, 0, n - 1, l, r, val);
    }
    ll operation(ll l, ll r)
    {
        return l + r;
        // sum, // max, // min, // gcd, // lcm, // xor, // or, // and, // product,
        // change the operation according to the query
    }

    void buildp(vector<ll> &a, ll v, ll tl, ll tr)
    {
        // a is the array, v is the index of the node, tl and tr are the range of the node

        if (tl == tr) // if the node is a leaf node
        {
            tree[v] = a[tl]; // store the value of the array in the node
        }
        else
        {
            ll tm = (tl + tr) / 2;                             // find the middle of the range
            buildp(a, v * 2, tl, tm);                          // build the left subtree
            buildp(a, v * 2 + 1, tm + 1, tr);                  // build the right subtree
            tree[v] = operation(tree[v * 2], tree[v * 2 + 1]); // merge the left and right subtree
        }
    }
    ll sump(ll v, ll tl, ll tr, ll l, ll r)
    {
        // v is the index of the node, tl and tr are the range of the node, l and r are the range of the query
        if (l > r)
        {
            return 0;
        }
        if (l == tl && r == tr)
        {
            return tree[v];
        }
        push(v);
        ll tm = (tl + tr) / 2;
        return operation(sump(v * 2, tl, tm, l, min(r, tm)), sump(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)); // merge the left and right subtree
    }
    void push(ll v) // push the pending updates to the children
    {
        tree[v * 2] += lazy[v];
        lazy[v * 2] += lazy[v];
        tree[v * 2 + 1] += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }
    // using push function in the updatep function
    void updatep(ll v, ll tl, ll tr, ll l, ll r, ll val)
    {
        if (l > r)
        {
            return;
        }
        if (l == tl && r == tr)
        {
            tree[v] += val;
            lazy[v] += val;
        }
        else
        {
            ll tm = (tl + tr) / 2;
            push(v);
            updatep(v * 2, tl, tm, l, min(r, tm), val);
            updatep(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
            tree[v] = operation(tree[v * 2], tree[v * 2 + 1]);
        }
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vl a(n);
    read(a, n);
    LazySegmentTree st(n);
    st.build(a);
    while (q--)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            st.update(l - 1, r - 1, v);
        }
        else
        {
            int l;
            cin >> l;
            cout << st.sum(l - 1, l - 1) << endl;
        }
    }
}
/*
|   _____    ____    _____    ______     ______   _   _   _____     _____
|  / ____|  / __ \  |  __ \  |  ____|   |  ____| | \ | | |  __ \   / ____| |
| | |      | |  | | | |  | | | |__      | |__    |  \| | | |  | | | (___   |
| | |      | |  | | | |  | | |  __|     |  __|   | . ` | | |  | |  \___ \  |
| | |____  | |__| | | |__| | | |____    | |____  | |\  | | |__| |  ____) | |
|  \_____|  \____/  |_____/  |______|   |______| |_| \_| |_____/  |_____/  |
*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("D:/CodeForces/0_Error.txt", "w", stderr);
#endif
    int testCases = 1;
    // cin >> testCases;
    fo(tt, testCases)
    {
        test(tt + 1);
#ifndef ONLINE_JUDGE
        // printTC(tt + 1);
#endif
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "------------------------------------------\n";
#endif
}
