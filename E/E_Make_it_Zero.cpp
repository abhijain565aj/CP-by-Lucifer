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
#define int ll
void solve()
{
    int n;
    cin >> n;
    vl a(n);
    read(a, n);
    ll sum = accumulate(all(a), 0LL);
    if(sum%2){
        cout << -1 << endl;
        return;
    }
    ll half = sum / 2;
    ll run = 0;
    fo(i,n) {
        run += a[i];
        if(run==half){
            cout<<1<<endl;
            print_space(a, n);
            return;
        }
        if(a[i]>half){
            cout<<-1<<endl;
            return;
        }
    }
    cout << 2 << endl;
    run = 0;
    vl ans1(n);
    int index = -1;
    fo(i,n){
        if(run+a[i]<=half){
            run += a[i], ans1[i] = a[i];
        }
        else{
            index = i;
            break;
        }
    }
    ll rem = half - run;
    ans1[index] = a[index] - rem;
    run -= ans1[index];
    fo1(i,index+1,n){
        if(run >= a[i]){
            ans1[i] = a[i];
            run -= a[i];
        }
        else{
            ans1[i] = run;
            break;
        }
    }
    vl ans2(n);
    fo(i, n) {
        ans2[i] = a[i] - ans1[i];
    }
    print_space(ans1, n);
    print_space(ans2, n);
    return;
}

signed main()
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
