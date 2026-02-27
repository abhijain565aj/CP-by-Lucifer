// Solution by Abhi Jain aka Lucifer aka abhijain565aj
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> // find_by_order, order_of_key

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
    ll n,m;
    vl a(n);
    vl b(m);
    read(a,n);
    read(b,m);
    sortall(a);
    sortall(b);
    vi sumsa;
    vi sumsb;
    int i=0;
    while(n-1-i>i){
        sumsa.pb(a[i]-a[n-1-i]);
        i++;
    }
    int j=0;
    while(m-1-j>j){
        sumsb.pb(b[j]-b[m-1-j]);
        j++;
    }
    int kmax = min((n+m)/3, min(n,m));
    int counta = 0;
    int countb = 0;
    int current_ans = 0;
    int a1, b1;
    a1 = b1 = 0;
    vi ans(kmax);
    fo(i,kmax){
        if(counta == n && countb<=m-2){
            current_ans -= sumsa[--a1];
            current_ans += sumsb[b1++];
            countb+=2;
            counta--;
        }
        else if(countb == m && counta<=n-2){
            current_ans -= sumsb[--b1];
            current_ans += sumsa[a1++];
            counta+=2;
            countb--;
        }
        else if(counta == n && countb == m){
            current_ans -= sumsa[--a1];
            current_ans += sumsb[b1++];
            counta--;
            countb++;
        }
        else if(sumsa[a1] > sumsb[b1]){
            current_ans += sumsa[a1++];
            counta++;
        }
        else{
            current_ans += sumsb[b1++];
            countb++;
        }
        ans[i] = current_ans;
    }
    cout<<kmax<<endl;
    print_space(ans, kmax);
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
