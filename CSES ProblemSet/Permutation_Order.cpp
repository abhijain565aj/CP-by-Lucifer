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

vl fac(21);
void fac_init(){
    fac[0] = 1;
    for(int i=1;i<21;i++){
        fac[i] = fac[i-1]*i;
    }
}
void query1(){
    ll n,k;
    cin>>n>>k;
    vl p;
    ordered_set<int> s;
    fo(i,n) s.insert(i+1);
    k--;
    for(int i=n-1;i>=0;i--){
        p.pb(*s.find_by_order(k/fac[i]));
        s.erase(p.back());
        k = k%fac[i];
    }
    
    for(auto x:p) cout<<x<<" ";
    cout<<endl;
}
void query2(){
    ll n;
    cin>>n;
    vl p(n);
    read(p,n);

    ordered_set<int> s;
    fo(i,n) s.insert(i+1);
    
    ll k = 0;
    fo(i,n){
        s.erase(p[i]);
        k += s.order_of_key(p[i])*fac[s.size()];
    }
    cout<<k+1<<endl;
}
int main()
{
    fastio; 
    // Error_file("0_Error.txt");
    fac_init();
    int nq;
    cin >> nq;
    while(nq--){
        int q;
        cin>>q;
        if(q == 1){
            query1();
        }
        else if (q == 2) {
            query2();
        }
    }
}
