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
        char arr[n];
        cin >> arr;
        bool vowel[n];
        fo(i, n)
        {
            if (arr[i] == 'a' || arr[i] == 'e')
                vowel[i] = true;
            else
                vowel[i] = false;
        }
        vector<int> v;
        fo(i, n)
        {
            if (vowel[i] == true)
            {
                if (i + 1 == n)
                {
                    v.pb(2);
                }
                else if (i + 2 == n)
                {
                    v.pb(3);
                }
                else if (i + 2 < n)
                {
                    if (vowel[i + 2] == false)
                        v.pb(3);
                    else
                    {
                        v.pb(2);
                    }
                }
                // cout<<v[v.size()-1]<<endl;
            }
        }
        int count = 0;
        fo(i, v.size())
        {
            fo(j, v[i])
            {
                cout << arr[count++];
            }
            if (i != v.size() - 1)
                cout << ".";
        }
        cout<<endl;
    }
}