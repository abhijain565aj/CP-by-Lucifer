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
pii dx[8] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
pii operator+(pii a, pii b)
{
    return {a.F + b.F, a.S + b.S};
}
void solve()
{
    string s;
    cin>>s;
    map<char, int> mp;
    for(auto x:s) mp[x]++;

    set<char> st;
    for(auto x:s) st.insert(x);

    set<pair<int, char>> st2;
    for(auto x:st) st2.insert({mp[x], x});
    
    int n = s.size();
    if(st2.rbegin()->F>(n+1)/2)
    {
        cout<<-1<<endl;
        return;
    }
    string ans = "";
    while(!st.empty() && st2.rbegin()->F - 1 != n/2){
        char c;
        debug(st);
        if(ans.size() == 0 || ans.back() != *st.begin()){
            c = *st.begin();
        }
        else{
            auto it = st.begin();
            it++;
            c = *it;
        } 
        ans += c;
        debug2(c,n);
        st2.erase({mp[c], c});
        mp[c]--;
        if(mp[c] == 0) st.erase(c);
        else st2.insert({mp[c], c});
        n--;
    }
    debug(st2);
    if(!st2.empty()){
        debug("hi");
        auto [ct ,c] = *(st2.rbegin());
        debug(c);
        st.erase(c);
        fo(i,ct-1){
            ans+=c;
            char c1 = *st.begin();
            ans += c1;
            st2.erase({mp[c1], c1});
            mp[c1]--;
            if(mp[c1] == 0) st.erase(c1);
            else st2.insert({mp[c1], c1});
        }
        ans += c;
    }
    cout<<ans<<endl;
}   

int main()
{
    fastio; 
    // Error_file("0_Error.txt");
    int testCases = 1;
    // cin >> testCases;
    fo(tt, testCases){
        test(tt + 1);
        solve();
    }
    test(0);
}
