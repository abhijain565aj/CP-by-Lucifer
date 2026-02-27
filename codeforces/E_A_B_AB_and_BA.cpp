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
    string s;
    cin>>s;
    int n = s.size();
    int a,b,ab,ba;
    cin>>a>>b>>ab>>ba;
    debug(s);
    vs v; 
    string curr = s.substr(0,1);
    for(int i=1;i<n;i++){
        if(curr.back()==s[i]) v.pb(curr), curr = s[i];
        else curr+=s[i];
    }
    v.pb(curr);
    debug(v);
    vs V;
    vi C;
    for(auto x:v){
        if(x.size()%2==0){
            V.pb(x);
        }
        else{
            a-=(x[0]=='A');
            b-=(x[0]=='B');
            C.pb(x.size()-1);
        }
    }
    if(a<0 || b<0){
        cout<<"NO"<<endl;
        return;
    }
    debug2(a,b);
    sort(all(V),[&](string x, string y){
        return x.size()<y.size();
    });
    debug(V);
    debug(C);
    vs V1;
    for(auto &x:V){
        if(x[0]=='A'){
            if(ab>=x.size()/2) ab-=x.size()/2;
            else{
                x = x.substr(0,x.size()-ab*2);
                V1.pb(x);
                ab = 0;
            }
        }
        else{
            if(ba>=x.size()/2) ba-=x.size()/2;
            else{
                x = x.substr(0,x.size()-ba*2);
                ba = 0;
                V1.pb(x);
            }
        }
    }
    ll sum = accumulate(all(C),0);
    debug(V1);
    debug2(ab,ba);
    debug2(a,b);
    debug(sum);
    if(ab!=0 && ba!=0){
        YN(sum/2<=ab+ba+min(a,b));
        return;
    }
    if(ab==0 && ba!=0){
        for(auto x:V1){
            a--, b--;
            auto sz = x.size()-2;
            if(ba>=sz/2)ba-=sz/2;
            else{
                sz -= ba*2, ba = 0;
                a-=sz/2; b-=sz/2;
            }
        }
    }
    else if(ab!=0 && ba==0){
        for(auto x:V1){
            a--, b--;
            auto sz = x.size()-2;
            if(ab>=sz/2)ab-=sz/2;
            else{
                sz -= ab*2, ab = 0;
                a-=sz/2; b-=sz/2;
            }
        }
    }
    else if (ab==0 && ba == 0){
        for(auto x:V1){
            auto sz = x.size();
            a-=sz/2; b-=sz/2;
        }
    }
    if(a<0 || b<0){
        cout<<"NO"<<endl;
        return;
    }
    YN(sum/2<=ab+ba+min(a,b) && a>=0 && b>=0);
    
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
