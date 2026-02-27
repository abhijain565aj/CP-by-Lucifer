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
    string s;
    string t;
    cin>>s>>t;
    if(s==t) {
        cout<<0<<endl;
        return;
    }
    int n = s.size();
    char curr = s[0];
    vi s1, t1;
    s1.pb(0),t1.pb(0);
    fo(i,n) if(s[i]!=curr) s1.pb(1), curr = s[i]; else s1.back()++;
    curr = t[0];
    fo(i,n) if(t[i]!=curr) t1.pb(1), curr = t[i]; else t1.back()++;
    s1.pb(0);
    s1.pb(0);
    int lp,back,ans;
    if(t[0]==s[0]){
        lp = 0;
        ans = 0;
    }
    else{
        lp = 1;
        ans = 1;
        s1[2]+=s1[0];
        s1[0] = 0;
    }
    back = 0;
    debug2(s1,t1);
    for(int i=0;i<t1.size();i++,lp++){
        debug3(i,lp,back);
        s1[lp]+=back;
        back = 0;
        while(t1[i]>0 && lp<s1.size()){
            debug3(t1[i],lp,back);
            t1[i]-=s1[lp];
            if(t1[i] && lp+2<s1.size()){
                ans++;
                back+=s1[lp+1];
                lp+=2;
            }
            else break;
        }
        if(t1[i]){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<ans<<endl;
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
