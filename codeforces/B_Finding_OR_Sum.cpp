// Solution by Abhi Jain aka Lucifer aka abhijain565aj
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
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
    //calculate the number with 30 bits having all even bits turned on
    // 101010101010101010101010101010
    //number with all bits turned on
    // 010101010101010101010101010101
    int n1 = 0, n2 = 0;
    for (int i = 0; i < 30; i += 2)
    {
        n1 += (1 << i);
        n2 += (1 << (i + 1));
    }
    int out1, out2;
    cout<<n1<<endl; cin>>out1;
    cout<<n2<<endl; cin>>out2;
    out1 -= 2*n1;
    out2 -= 2*n2;
    int sum = out1 + out2;
    out1 = sum - out1;
    out2 = sum - out2;
    vi a1(32);
    vi a2(32);
    for (int i = 0; i < 32; i++)
    {
        a1[i] = (out1 >> i) & 1;
        a2[i] = (out2 >> i) & 1;
    }
    vi x(32);
    vi y(32);
    for(int i=0;i<30;i++){
        if(i%2==0){
            if(a1[i]==1) x[i] = 1;
            if(a1[i+1]==1) x[i] = y[i] = 1;
        }
        else{
            if(a2[i]==1) y[i] = 1;
            if(a2[i+1]==1) x[i] = y[i] = 1;
        }
    }
    int X = 0, Y = 0;
    for(int i=0;i<32;i++){
        X += (x[i] << i);
        Y += (y[i] << i);
    }
    cout<<"!"<<endl;
    int m;
    cin>>m;
    cout<<(X|m)+(Y|m)<<endl;
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
