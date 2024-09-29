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
        int k, n;
        cin >> n >> k;
        int ncopy = n;
        int perm[n];
        int current = 0;
        bool inc = true;
        while (n > 0)
        {
            perm[current] = n;
            n--;
            if (inc)
            {
                current = current + k;
            }
            else
            {
                current = current - k;
            }
            if (current >= ncopy)
            {
                current = current - k;
                if (current + 1 < ncopy)
                {
                    current = current + 1;
                }

                else
                {
                    current = current - k + 1;
                }

                inc = false;
            }
            else if (current < 0)
            {
                current = current + k + 1;
                inc = true;
            }
        }
        fo(i, ncopy)
        {
            cout << perm[i]<<" ";
        }

        cout << endl;
    }
}