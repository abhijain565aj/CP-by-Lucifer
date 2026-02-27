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
    int n, k;
    cin >> n >> k;
    string s,t;
    cin >> s >> t;
    char A = t[0], B = t[1];
    v(v(v(pii))) dp(n,v(v(pii))(n+1,v(pii)(k+1,{-1,-1})));
    // dp[i][j][k] = (max_ans, b's count) at index i, with j a's behin and k operations left
    auto fn = [&](auto&& fn, int ind, int cnt_a, int ops)->pii{
        if(ind == n) return {0, 0};
        if(dp[ind][cnt_a][ops].F != -1) return dp[ind][cnt_a][ops];
        auto& DP = dp[ind][cnt_a][ops];
        // debug3(ind, cnt_a, ops);
        auto res = fn(fn, ind + 1, cnt_a+(s[ind]==A), ops);
        DP = {res.F+(s[ind]==A)*res.S,res.S+(s[ind]==B)};
        if(ops > 0 && A!= B){
            res = fn(fn, ind + 1, cnt_a + 1, ops - 1);
            pii temp = {res.F + res.S, res.S};
            if(cnt_a * temp.S + temp.F > cnt_a * DP.S + DP.F){
                DP = temp;
            }
            
            res = fn(fn, ind + 1, cnt_a, ops - 1);
            temp = {res.F, res.S+1};
            if(cnt_a * temp.S + temp.F > cnt_a * DP.S + DP.F){
                DP = temp;
            }
        }
        else if(ops > 0 && A == B){
            res = fn(fn, ind + 1, cnt_a + 1, ops - 1);
            pii temp = {res.F + res.S, res.S+1};
            if(cnt_a * temp.S + temp.F > cnt_a * DP.S + DP.F){
                DP = temp;
            }
        }
        return DP;
    };
    cout << fn(fn, 0, 0, k).F << endl;
}

int main()
{
    fastio; 
    // Error_file("0_Error.txt");
    int testCases = 1;
    // cin >> testCases;
    fo(tt, testCases){
        test(tt + 1);
        solve();
    }
    test(0);
}
