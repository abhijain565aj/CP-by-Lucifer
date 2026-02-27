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
    ll n, l, r;
    cin>>n >> l>>r;
    vl a(n+1);
    fo(i, n){
        cin>>a[i+1];
    }
    vl xorSum(n+1);
    xorSum[0] = 0;
    fo1(i, 1, n+1){
        xorSum[i] = xorSum[i-1] ^ a[i];
    }
    if(n%2==0){
        n++;
        a.pb(xorSum[n/2]);
        xorSum.pb(xorSum[n-1]^a[n]);
    }
    auto fn = [&](auto&&fn, ll i)->ll{
        if(i<=n){
            return a[i];
        }
        i = i/2;
        if(i<=n){
            return xorSum[i];
        }
        if(i%2 == 0){
            return xorSum[n]^fn(fn,i);
        }
        else{
            return xorSum[n];
        }
    };
    vl abnormal;
    fo1(i,1,n+1){
        //number of bits in i
        ll nbits = 0;
        while ((1LL << nbits) <= i) {
            nbits++;
        }
        fo(j,64ll-nbits){
            abnormal.pb(i<<j);
        }
    }
    sortall(abnormal);
    abnormal.resize(unique(all(abnormal)) - abnormal.begin());
    vl values(abnormal.size());
    fo(i,abnormal.size()){
        values[i] = fn(fn,abnormal[i]);
    }
    vl pf(abnormal.size());
    fo(i,abnormal.size()){
        pf[i] = values[i];
        if(i) pf[i] += pf[i-1];
    }
    auto sum = [&](ll l)->ll{
        int count = upper_bound(all(abnormal),l)-abnormal.begin();
        int normal = l-count;
        debug2(count,normal);
        for(int i=0;i<count;i++){
            debug2(abnormal[i],values[i]);
        }
        debug(pf[count-1]);
        return pf[count-1]+(normal/2)*(xorSum[n]);
    };
    auto s2 = sum(r);
    auto s1 = sum(l);
    debug2(s1,s2);
    cout<<s2-s1 + fn(fn,l)<<endl;
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
