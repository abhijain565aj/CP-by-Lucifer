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
#define fo1(i, a, b) for (decltype(b) i = (a); i < (b); i++)
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
vl prime(100001);
void sieve()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i <= 100000; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= 100000; j += i)
            {
                prime[j] = 1;
            }
        }
    }
}
vl primes;
void solve()
{
    ll n;
    cin>>n;
    vl ans;
    int p = (n+1)/2;

    p = upper_bound(all(primes),p) - primes.begin();
    if(p==0) p++;
    p = primes[p-1];
    debug(p);
    ans.pb(p);
    fo1(i,1,p){
        ans.pb(p-i),ans.pb(p+i);
    }
    debug(ans);
    debug(2*p);
    fo1(i,2*p,n+1){
        ans.pb(i);
    }
    print_space(ans,n);
    // vl c(n);
    // ll count = 0;
    // ll sum = 0;
    // fo(i,n){
    //     sum += ans[i];
    //     c[i] = (sum+i)/(i+1);
    //     if(prime[c[i]]==0){
    //         count++;
    //     }
    // }
    // debug(c)
    // cout<<count<<endl;
}

// void solve()
// {
//     ll n;
//     cin>>n;
//     set<ll> s;
//     fo(i,n){
//         s.insert(i+1);
//     }
//     ll sum = 0;
//     ll i,j;
//     i = j = 0;
//     vl ans(n);
//     fo(i,n){
//         ans[i] = n-i;
//     }
//     // while(j<n){
//     //     ll req = primes[i]*(j+1);
//     //     auto v = s.lower_bound(req-sum-j);
//     //     if(v==s.end()){
//     //         break;
//     //     }
//     //     if(*v>req-sum){
//     //         i++;
//     //         continue;
//     //     }
//     //     ans[j++] = *v;
//     //     s.erase(v);
//     //     sum += *v;
//     // }
//     // for(int i=j;i<n;i++){
//     //     auto v = s.begin();
//     //     ans[i] = *v;
//     //     s.erase(v);
//     // }
//     vl c(n);
//     ll count = 0;
//     sum = 0;
//     fo(i,n){
//         sum += ans[i];
//         c[i] = (sum+i)/(i+1);
//         if(prime[c[i]]==0){
//             count++;
//         }
//     }
//     debug(c)
//     cout<<count<<endl;
//     // print_space(ans,n);
// }

int main()
{
    fastio; 
    // Error_file("0_Error.txt");
    int testCases = 1;
    cin >> testCases;
    sieve();
    fo(i,100001){
        if(prime[i]==0){
            primes.pb(i);
        }
    }
    fo(tt, testCases){
        test(tt + 1);
        solve();
    }
    test(0);
}
