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
#define vd vector<long double>
v(vd) mul(v(vd)& A, v(vd)& B){
    v(vd) res(64, vd(64, 0.0));
    fo(i,64) fo(j,64) fo(k,64){
        res[i][j] += A[i][k]*B[k][j];
    }
    return res;
}

int main()
{
    fastio; 
    // Error_file("0_Error.txt");
    long double one = 1.0;
    map<pii, int> mp;
    v(vd) M(64, vd(64, 0));
    v(pii) dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    fo(i, 64) {
        int x = i / 8, y = i % 8;
        long double cnt = 0;
        for (auto [dx, dy] : dir) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                cnt+=one;
            }
        }
        for (auto [dx, dy] : dir) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                M[i][nx * 8 + ny] = one / cnt;
            }
        }
    }
    ll k;
    cin >> k;
    v(vd) Ans(64, vd(64, 0.0));
    fo(i, 64) Ans[i][i] = one;
    while(k>0){
        if(k&1) Ans = mul(Ans,M);
        M = mul(M,M);
        k/=2;
    }
    long double ans = 0.0;
    fo(i,64){
        long double prob = one;
        fo(j,64) prob*=(one-Ans[j][i]);
        ans += prob;
    }
    cout << fixed << setprecision(6) << ans << endl;
}
