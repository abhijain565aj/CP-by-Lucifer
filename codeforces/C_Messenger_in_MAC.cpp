// Solution by Abhi Jain aka Lucifer aka abhijain565aj
// Mera solution kyun dekh rha?

#include <bits/stdc++.h>

using ll = long long int;
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define L cout<<"n"

#define fo(i, n) for (int i = 0; i < n; i++)
#define re(i, n) for (int i = n-1; i >= 0; i--)
#define fo1(i, a, b) for (int i = a; i <= b; i++)
#define fo2(i, a, b) for (int i = a; i >= b; i--)

#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define F first
#define S second
#define pb push_back

using namespace std;
bool sortby2(pll &a, pll &b){
    return a.S<b.S;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testCases = 1;
    cin >> testCases;
    fo(t, testCases)
    {
        int n;
        cin>>n;
        ll l;
        cin>>l;
        vector<pll> msg(n);
        ll a,b;
        fo(i,n){
            cin>>a>>b;
            msg[i] = {a,b};
        }
        sort(all(msg),sortby2);
        vi diff(n-1);
        vi sumdiff(n-1);;
    
        fo(i,n){
            diff[i] = msg[i+1].S - msg[i].S;
        }
        vector<pii> cpf(n);
        fo(i,n){
            cpf[i] = {i,msg[i].F};
        }
        sort(all(cpf),sortby2);

    }
}
