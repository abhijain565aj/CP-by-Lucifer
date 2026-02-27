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
void solve()
{
    int n;
    cin >> n;
    v(set<int>) multiple(n+1),factors(n+1);
    for(int i=2;i<=n;i++) {
        for(int j=i;j<=n;j+=i) {
            multiple[i].insert(j);
            factors[j].insert(i);
        }
    }
    vi a(n);
    fo(i,n) a[i] = i+1;
    // vi xtra;
    // fo1(i,1,n) {
    //     if(a[i]!=i+1) continue;
    //     else {
    //         int val = i+1;    
    //         int r = *multiple[val].rbegin();
    //         if(r==val){
    //             xtra.pb(val);
    //             continue;
    //         }
    //         swap(a[i], a[r-1]);
    //         for(auto f : factors[r]) {
    //             multiple[f].erase(r);
    //         }
    //     }
    // }
    for(auto x : a) {
        for(auto f : factors[x]) {
            if(__gcd(a[f-1],x)!=1 && f-1!=x){
                swap(a[f-1], a[x-1]);
                break;
            }
        }
    }
    print_space(a, n);
}

int main()
{
    fastio; Error_file("0_Error.txt");

    int testCases = 1;
    cin >> testCases;
    fo(tt, testCases){
        test(tt + 1);
        solve();
    }
    test(0);
}
