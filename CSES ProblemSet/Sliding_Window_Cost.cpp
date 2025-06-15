
// Solution by Abhi Jain aka Lucifer aka abhijain565aj
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> // find_by_order, order_of_key
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

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

int main()
{
    fastio;
    ll n,k;
    cin>>n>>k;
    vl a(n);
    read(a,n);
    ll mid = k/2;
    if(k%2==0) mid--;
    multiset<ll> left, right;
    vl ans;
    ll median;
    ll lsize = mid, rsize = k-mid-1;
    debug2(lsize,rsize);
    multiset<ll> total;
    fo(i,k) total.insert(a[i]);
    multiset<ll>::iterator itr = total.begin();
    ll lsum = 0, rsum = 0;
    fo(i,lsize) left.insert(*(itr)), lsum+=*(itr++);
    median = *(itr++);
    fo(i,rsize) right.insert(*(itr)), rsum+=*(itr++);
    vl ans1;
    ans1.pb(rsum-lsum);
    ans.pb(median);
    fo1(i,k,n){
        if(left.find(a[i-k])!=left.end()) left.erase(left.find(a[i-k])), lsum-=a[i-k];
        else if(right.find(a[i-k])!=right.end()) right.erase(right.find(a[i-k])), rsum-=a[i-k];
        else median = -1;
        right.insert(a[i]), rsum+=a[i];
        if(median == -1){
            median = *right.begin();
            rsum-=median,right.erase(right.begin());
            if(left.size()&&median<*left.rbegin()){
                left.insert(median),lsum+=median;
                median = *left.rbegin();
                left.erase(left.find(median)),lsum-=median;
            }
        }
        else if(left.size()<lsize){
            if(median<*right.begin()){
                left.insert(median),lsum+=median;
                median = *right.begin();
            }
            else{
                left.insert(*right.begin()), lsum+=*right.begin();
            }
            rsum-=*right.begin(),right.erase(right.begin());
        }
        else{
            if(*right.begin()<median){
                right.insert(median),rsum+=median;
                median = *right.begin();
                right.erase(right.begin()),rsum-=median;
            }
            if(left.size()&&median<*left.rbegin()){
                left.insert(median),lsum+=median;
                median = *left.rbegin();
                left.erase(left.find(median)),lsum-=median;
            }
        }
        ans1.pb(rsum-lsum);
        ans.pb(median);
    }
    if(k%2==0) fo(i,n-k+1) ans1[i]-=ans[i];
    print_space(ans1,n-k+1)
}
