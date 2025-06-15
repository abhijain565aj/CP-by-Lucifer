// Solution by Abhi Jain aka Lucifer aka abhijain565aj
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
template<class T>
using ordered_multiset =  tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order, order_of_key

// #define ONLINE_JUDGE
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
// a.resize(unique(all(a)) - a.begin());  -> unque element me convert karta hai

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define read(a, n) for (int i = 0; i < n; ++i) cin >> a[i];
#define print_space(a, n) for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? '\n' : ' ');
#include <bits/stdc++.h>
using namespace std;

// disjoint set union
struct DSU
{
    vector<int> parent, size; // parent of each node and size of each component
    int components;  
    multiset<int> sizes;         // number of connected components
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        components = n;
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            sizes.insert(1);
        }
    }
    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); // path compression
    }
    void unite(int x, int y)
    {
        x = find(x); // find the parent of x
        y = find(y); // find the parent of y
        if (x != y)  // if x and y are not in the same component
        {
            if (size[x] < size[y])
            {
                swap(x, y);
            }
            sizes.erase(sizes.find(size[x]));
            sizes.erase(sizes.find(size[y]));
            sizes.insert(size[x] + size[y]);
            parent[y] = x;
            size[x] += size[y];
            components--;
        }
    }
    int largestComponentSize() // get the size of the largest component
    {
        if (sizes.empty()) return 0;
        return *sizes.rbegin(); // return the largest size from the multiset
    }
    bool same(int x, int y) // check if x and y are in the same component
    {
        return find(x) == find(y);
    }
    int getSize(int x) // get the size of the component of x
    {
        return size[find(x)];
    }
    int getComponents() // get the number of connected components
    {
        return components;
    }
};

int main()
{
    fastio; Error_file("0_Error.txt");
    int n,m;
    cin >> n >> m;
    DSU dsu(n);
    fo(i,m){
        int a,b;
        cin >> a >> b;
        dsu.unite(a - 1, b - 1);
        cout<<dsu.getComponents() << " " << dsu.largestComponentSize() << endl;
    }
}
