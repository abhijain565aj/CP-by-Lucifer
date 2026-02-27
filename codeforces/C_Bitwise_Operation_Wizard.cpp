#include <bits/stdc++.h>

using ll = long long int;
#define fo(i, n) for (int i = 0; i < n; i++)
#define pb push_back
using namespace std;
int main()
{
    int testCases;
    cin >> testCases;
    fo(t, testCases)
    {
        int max = 0;
        int n;
        cin >> n;
        char b;
        fo(i,n){
            cout<<"? "<<max<<" "<<max<<" "<<i<<" "<<i<<endl;
            cin>>b;
            if(b=='<'){
                max = i;
            }
        }
        int sup = 0;
        fo(i,n){
            cout<<"? "<<max<<" "<<sup<<" "<<i<<" "<<max<<endl;
            cin>>b;
            if(b=='<'){
                sup = i;
            }
            if(b=='='){
                cout<<"? "<<sup<<" "<<sup<<" "<<i<<" "<<i<<endl;
                cin>>b;
                if(b=='>'){
                    sup = i;
                }
            }
        }
        cout<<"! "<<sup<<" "<<max<<endl;
    }
}