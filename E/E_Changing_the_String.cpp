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
#define A 'a'
#define B 'b'
#define C 'c'
void solve()
{
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    map<pair<char, char>, set<int>> mp;
    fo(i,q){
        char q1, q2;
        cin >> q1 >> q2;
        mp[{q1, q2}].insert(i);
    }
    for(auto &x:s){
        if(x==B){
            if(mp[{B,A}].size()){
                x = A;
                auto it = mp[{B,A}].begin();
                mp[{B,A}].erase(it);
            }
            else if(mp[{B,C}].size()){
                auto it = *mp[{B,C}].begin();
                auto it2 = mp[{C,A}].lower_bound(it);
                if(it2 != mp[{C,A}].end()){
                    x = A;
                    mp[{B,C}].erase(it);
                    mp[{C,A}].erase(it2);
                }
            }
        }
        else if(x==C){
            if(mp[{C,A}].size()){
                x = A;
                auto it = mp[{C,A}].begin();
                mp[{C,A}].erase(it);
            }
            else if(mp[{C,B}].size()){
                auto it = *mp[{C,B}].begin();
                auto it2 = mp[{B,A}].lower_bound(it);
                if(it2 != mp[{B,A}].end()){
                    x = A;
                    mp[{C,B}].erase(it);
                    mp[{B,A}].erase(it2);
                }
                else if(mp[{C,B}].size()){
                    x = B;
                    mp[{C,B}].erase(*mp[{C,B}].rbegin());
                }
            }
        }
    }
    debug(mp);
    cout << s << endl;
}

int main()
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
}
