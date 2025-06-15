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

    void solve()
    {
        ll n;
        cin >> n;
        v(pll) vp(n);
        fo(i, n) {
            cin >> vp[i].F >> vp[i].S;
        }
        vi adj(n);
        map<ll, set<ll>> vol, pitch;
        fo(i,n) vol[vp[i].F].insert(i), pitch[vp[i].S].insert(i);
        vl vol_s, pitch_s;
        for(auto [v,s]:vol) if(s.size()%2) vol_s.pb(*s.begin());
        for(auto [p,s]:pitch) if(s.size()%2) pitch_s.pb(*s.begin());
        debug(vol_s);
        debug(pitch_s);
        ll sz = vol_s.size() + pitch_s.size();  
        if(sz>2 || sz==1) {
            cout << "NO\n";
            return;
        } 
        vl answer;
        auto dfs = [&](auto&& dfs, ll v, bool volume)->void{
            answer.pb(v);
            pitch[vp[v].S].erase(v);
            vol[vp[v].F].erase(v);
            if(volume){
                if(!vol[vp[v].F].empty()) 
                    dfs(dfs,*vol[vp[v].F].begin(),false);
            }
            else{
                if(!pitch[vp[v].S].empty()) 
                    dfs(dfs,*pitch[vp[v].S].begin(),true);
            }
        };
        if(vol_s.size()>=1){
            dfs(dfs, vol_s[0], false);
        }
        else if(pitch_s.size()>=1){
            dfs(dfs, pitch_s[0], true);
        }
        else {
            dfs(dfs, 0, false);
        }
        if(answer.size() != n) {
            cout << "NO\n";
            return;
        }
        cout<< "YES\n";
        for(auto v:answer) {
            cout << v + 1 << " ";
        }
        cout << endl;
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
