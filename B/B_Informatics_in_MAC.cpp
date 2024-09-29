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
#define L cout << "\n"

#define fo(i, n) for (int i = 0; i < n; i++)
#define re(i, n) for (int i = n - 1; i >= 0; i--)
#define fo1(i, a, b) for (int i = a; i <= b; i++)
#define fo2(i, a, b) for (int i = a; i >= b; i--)

#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define F first
#define S second
#define pb push_back

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testCases = 1;
    cin >> testCases;
    fo(t, testCases)
    {
        int n;
        cin >> n;
        vi arr(n);
        vi count(n, 0);
        fo(i, n)
        {
            cin >> arr[i];
            count[arr[i]]++;
        }
        int izero = n;
        fo(i, n)
        {
            if (count[i] == 0)
            {
                izero = i;
                break;
            }
        }
        vi index;
        bool push = true;
        vi bl(izero, 0);
        int counter = 0;
        int arrays = 0;
        // cout<<izero<<endl;
        fo(i, n)
        {
            if (push)
            {
                index.pb(i + 1);
                push = false;
            }
            if (arr[i] < izero && bl[arr[i]] == arrays)
            {
                counter++;
                bl[arr[i]]++;
            }
            if (counter == izero)
            {
                push = true;
                arrays++;
                index.pb(i + 1);
                counter = 0;
            }
        }
        if(index.size()&1){
            index.pop_back();
            index.pop_back();
            index.pb(n);
        }
        if (arrays <= 1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << arrays<<endl;
            int odd = true;
            for (auto x : index)
            {
                if (odd)
                {
                    cout << x << " ";
                    odd = false;
                }
                else
                {
                    cout << x << endl;
                    odd = true;
                }
            }
        }
    }
}
