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
v(pii) dir = {{-1,0},{1,0},{0,-1},{0,1}};
int main()
{
    fastio; 
    // Error_file("0_Error.txt");
    int n,m;
    cin >> n >> m;
    vs a(n);
    fo(i,n) cin>> a[i];
    vvi arr(n, vi(m, 0));
    fo(i,n) fo(j,m) arr[i][j] = (a[i][j]=='#')?-1:1e9;
    auto arr_cpy = arr;
    queue<pii> q;
    fo(i,n) fo(j,m) if(a[i][j]=='M') q.push({i,j}), arr[i][j] = 1;
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for(auto [dx, dy] : dir){
            int nx = x + dx, ny = y + dy;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] != 1e9) continue;
            arr[nx][ny] = arr[x][y] + 1;
            q.push({nx, ny});
        }
    }
    debug(arr);
    // shortest path from A to B
    queue<pii> q2;
    fo(i,n) fo(j,m) if(a[i][j]=='A') q2.push({i,j}), arr_cpy[i][j] = 1;
    while(!q2.empty()){
        auto [x,y] = q2.front();
        q2.pop();
        for(auto [dx, dy] : dir){
            int nx = x + dx, ny = y + dy;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || arr_cpy[nx][ny] != 1e9) continue;
            arr_cpy[nx][ny] = arr_cpy[x][y] + 1;
            q2.push({nx, ny});
        }
    }
    debug(arr_cpy);
    pii curr = {-1, -1};
    fo(i,n) fo(j,m) if(i==0 || i==n-1 || j==0 || j==m-1) {
        if(arr_cpy[i][j] < arr[i][j]){
            curr = {i, j};
            break;
        }
    }
    if(curr.F == -1) {
        cout << "NO" << endl;
        return 0;
    } 
    cout << "YES" << endl;
    cout<<arr_cpy[curr.F][curr.S] - 1<< endl;
    v(pii) path;
    path.pb(curr);
    while(arr_cpy[curr.F][curr.S]!= 1){
        for(auto [dx, dy] : dir){
            int nx = curr.F + dx, ny = curr.S + dy;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || arr_cpy[nx][ny] != arr_cpy[curr.F][curr.S] - 1) continue;
            path.pb({nx, ny});
            curr = {nx, ny};
            break;
        }
    }
    reverse(all(path));
    debug(path);
    string ans = "";
    for(auto [x, y] : path){
        if(x == curr.F && y == curr.S) continue;
        if(x == curr.F) {
            if(y < curr.S) ans += 'L';
            else ans += 'R';
        } else {
            if(x < curr.F) ans += 'U';
            else ans += 'D';
        }
        curr = {x, y};
    }
    cout << ans << endl;
}
