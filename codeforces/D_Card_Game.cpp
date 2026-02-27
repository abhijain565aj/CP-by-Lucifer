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
        int n;
        cin >> n;
        char T;
        cin >> T;
        string arr[2 * n];
        vector<int> C;
        vector<int> D;
        vector<int> H;
        vector<int> S;
        vector<int> *trump;
        if (T == 'C')
        {
            trump = &C;
        }
        else if (T == 'D')
        {
            trump = &D;
        }
        else if (T == 'H')
        {
            trump = &H;
        }
        else if (T == 'S')
        {
            trump = &S;
        }
        fo(i, 2 * n)
        {
            cin >> arr[i];
            if (arr[i][1] == 'C')
            {
                C.pb(arr[i][0] - '0');
            }
            else if (arr[i][1] == 'D')
            {
                D.pb(arr[i][0] - '0');
            }
            else if (arr[i][1] == 'H')
            {
                H.pb(arr[i][0] - '0');
            }
            else if (arr[i][1] == 'S')
            {
                S.pb(arr[i][0] - '0');
            }
        }
        sort(C.begin(), C.end());
        sort(D.begin(), D.end());
        sort(H.begin(), H.end());
        sort(S.begin(), S.end());
        int xtra = C.size() % 2 + D.size() % 2 + H.size() % 2 + S.size() % 2 - trump->size() % 2;
        int l1=0;
        if (xtra <= trump->size())
        {
            if (trump != &C)
            {
                fo(i, (C.size() / 2)*2)
                {
                    cout << C[i] << "C " << C[++i] << "C" << endl;
                }
                if(C.size()%2!=0){
                    cout << C[C.size()-1] << "C " <<(*trump)[l1++]<<T<<endl;
                }
            }
            if (trump != &D)
            {
                fo(i, (D.size() / 2)*2)
                {
                    cout << D[i] << "D " << D[++i] << "D" << endl;
                }
                if(D.size()%2!=0){
                    cout << D[D.size()-1] << "D " <<(*trump)[l1++]<<T<<endl;
                }
            }
            if (trump != &H)
            {
                fo(i, (H.size() / 2)*2)
                {
                    cout << H[i] << "H " << H[++i] << "H" << endl;
                }
                if(H.size()%2!=0){
                    cout << H[H.size()-1] << "H " <<(*trump)[l1++]<<T<<endl;
                }
            }
            if (trump != &S)
            {
                fo(i, (S.size() / 2)*2)
                {
                    cout << S[i] << "S " << S[++i] << "S" << endl;
                }
                if(S.size()%2!=0){
                    cout << S[S.size()-1] << "S " <<(*trump)[l1++]<<T<<endl;
                }
            }
            for(int i=l1;i<trump->size();i+=2){
                cout<<(*trump)[i]<<T<<" "<<(*trump)[i+1]<<T<<endl;
            }
        }
        else
        {
            cout << "IMPOSSIBLE" << endl;
        }
    }
}
