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

#define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;
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
    cin>>n;
    vi a(n);
    read(a, n);
    auto ask = [&](int i, int j)->int{
        cout<<"? "<<i+1<<" "<<j+1<<endl;
        int x;
        cin>>x;
        return x;
    };
    auto winA = [&](){
        cout<<"! A"<<endl;
    };
    auto winB = [&](){
        cout<<"! B"<<endl;
    };
    vi adj(n);
    fo(i,n){
        adj[a[i]-1]++;
    }
    vvi index(n);
    fo(i,n){
        index[a[i]-1].pb(i);
    }
    vi b;
    vi c;
    fo(i,n) {
        if(adj[i] == 0) b.pb(i);
        else c.pb(i);
    }
    if(b.size() >= 1){
        int x = ask(b[0], c[0]);
        if(x==0) winA();
        else winB();
    }
    else{
        int x = ask(index[0][0], index[n-1][0]);
        int y = ask(index[n-1][0], index[0][0]);
        if(x>=n-1 && y>=n-1) winB();
        else winA();
    }
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
