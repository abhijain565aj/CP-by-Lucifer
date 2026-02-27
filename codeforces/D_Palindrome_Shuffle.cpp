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
    string s1;
    int ind = -1;
    fo(i,n/2) {
        if(s[i]!=s[n-i-1]) {
            ind = i; break;
        }
    }
    if(ind==-1){
        cout<<0<<endl;
        return;
    }
    for(int i=ind;i<n-ind;i++) s1.pb(s[i]);
    debug(s1);
    int m = s1.size();
    //max pallindrome at center of s1;
    int len = 0;
    for(int i=0;i<m/2;i++){
        if(s1[m/2-1-i]==s1[m/2+i]) len++;
        else break;
    }
    debug(len);
    multiset<char> st1;
    for(int i=0;i<m/2-len;i++){
        st1.insert(s1[i]);
    }
    for(int i=0;i<m/2-len;i++){
        if(st1.find(s1[m-i-1])!=st1.end())
            st1.erase(st1.find(s1[m-i-1]));
    }
    if(st1.size()==0){
        cout<<m/2-len<<endl;
        return;
    }
    multiset<char> st;
    for(int j=m-1;j>=0;j--){
        st.insert(s1[j]);
    }
    int l = 0;
    for(int j=0;j<m;j++){
        if(st.find(s1[j])==st.end()){
            l = j;
            break;
        }
        st.erase(st.find(s1[j]));
        if(st.find(s1[j])==st.end()){
            l = j;
            break;
        }
        else(st.erase(st.find(s1[j])));
    }
    st.clear();
    for(int j=m-1;j>=0;j--){
        st.insert(s1[j]);
    }
    int r = m-1;
    debug(st);
    for(int j=m-1;j>=0;j--){
        if(st.find(s1[j])==st.end()){
            r = j;
            break;
        }
        st.erase(st.find(s1[j]));
        debug2(j,st);
        if(st.find(s1[j])==st.end()){
            r = j;
            break;
        }
        else(st.erase(st.find(s1[j])));
    }
    debug2(l,r);
    debug2(m-l,r+1);
    int ans = min(m - l,r+1);
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
