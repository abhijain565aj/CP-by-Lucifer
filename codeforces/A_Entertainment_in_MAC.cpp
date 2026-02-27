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
void pr(string &s){
    fo(i,s.size()){
        cout<<s[i];
    }
}
void rpr(string &s){
    re(i,s.size()){
        cout<<s[i];
    }
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
        string s;
        cin>>s;
        int a = s.size();
        bool str = true;
        fo(i,a){
            if(s[i]<s[a-1-i]){
                str = true;
                break;
            }
            else if(s[i]>s[a-1-i]){
                str = false;
                break;
            }
        }
        if(str){
            if(n&1){
                pr(s);
                rpr(s);
            }
            else{
                pr(s);
            }
        }
        else{
            n--;
            if(n&1){
                rpr(s);
                pr(s);
            }
            else{
                rpr(s);
            }
        }
        cout<<endl;
    }
}
