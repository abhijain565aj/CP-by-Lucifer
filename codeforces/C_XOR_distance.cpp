#include <iostream>
// #include<string>
// #include<algorithm>
#include <cmath>
#include <vector>
// #include <bits/stdc++.h>

using ll = long long int;
#define fo(i, n) for (int i = 0; i < n; i++)
#define swap(a, b) \
    {              \
        a ^= b;    \
        b ^= a;    \
        a ^= b;    \
    }

#define pb push_back
using namespace std;
int main()
{
    int testCases;
    cin >> testCases;
    fo(t, testCases)
    {
        vector<ll> N;
        ll n;
        ll m;
        ll r;
        cin >> n >> m >> r;
        ll n1 = n;
        ll m1 = m;
        while (n != 0)
        {
            N.pb(n % 2);
            n = n / 2;
        }
        int i = 0;
        while (m != 0)
        {
            if (i < N.size())
            {
                N[i] -= m % 2;
            }
            else
            {
                N.pb((-1) * (m % 2));
            }
            m = m / 2;
            i++;
        }
        vector<ll> R;
        while (r != 0)
        {
            R.pb(r % 2);
            r = r / 2;
        }
        vector<ll> max;
        int size = N.size();
        int elem = 0;
        for (int i = size - 1; i >= 0; i--)
        {
            if (N[i] != 0 && elem == 0)
            {
                elem = N[i];
                size = i;
                break;
            }
        }
        fo(i, size)
        {
            if (N[i] == elem)
            {
                max.pb(1);
            }
            else
            {
                max.pb(0);
            }
        }
        if (R.size() > max.size())
        {
        }
        else
        {
            for (int i = max.size() - 1; i >= 0; i--)
            {
                if (i >= R.size())
                {
                    max[i] = 0;
                }
                else
                {
                    if (R[i] == 1 && max[i] == 0)
                    {
                        break;
                    }
                    else if (R[i] == 0 && max[i] == 1)
                    {
                        max[i] = 0;
                    }
                }
            }
        }
        ll maxv = 0;
        for(int i= max.size()-1; i>=0; i--)
        {
            maxv *=2;
            maxv += max[i];
        }
        ll n2 = n1 ^ maxv;
        ll m2 = m1 ^ maxv;
        cout << abs(n2 - m2) << endl;
    }
}