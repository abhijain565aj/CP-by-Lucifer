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

pii operator+(const pii& p1, const pii& p2){
    pii ans = {p1.F + p2.F, p1.S + p2.S};
    if(ans.F<0||ans.S<0||ans.F>=8||ans.S>=8) return {-1,-1};
    else return ans;
}

int main()
{
    fastio;
    // Error_file("0_Error.txt");
    vvi board(8,vi(8));
    v(pii) dir = {{1,2},{2,1},{-1,2},{2,-1},{1,-2},{-2,1},{-1,-2},{-2,-1}};
    auto count = [&](pii p)->int{
        if(p.F==-1 || board[p.F][p.S]>0) return 1e9;
        int ret = 0;
        for(auto d:dir){
            auto v = p+d;
            if(v.F!=-1&&board[v.F][v.S]==0) ret++;
        }
        return ret;
    };
    int cnt = 1;
    auto dfs = [&](auto&&dfs, pii p){
        if(p.F==-1) return;
        board[p.F][p.S] = cnt++;
        int minv = 9;
        pii minnode = {-1,-1};
        for(auto d:dir){
            int out = count(p+d);
            debug(out);
            if(minv>out){
                minv = out;
                minnode = p+d;
            }
        }
        debug2(minnode,minv);
        dfs(dfs,minnode);
    };
    int u,v;
    cin>>u>>v;
    dfs(dfs,{v-1,u-1});
    for(auto v:board){
        print_space(v,8);
    }
}
