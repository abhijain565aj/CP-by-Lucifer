#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define fo(i, n) for (int i = 0; i < n; i++)
#define fo1(i, a, b) for (int i = a; i < b; i++)

int mod = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    vi a(n);
    fo(i, n)
    {
        cin >> a[i];
    }
    vvi dp(n + 1, vi(x + 1, 0));
    // cout << coin_count(a, dp, x, n);
    dp[0][0] = 1;
    fo1(i, 1, n + 1)
    {
        fo1(j, 0, x + 1)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - a[i - 1] >= 0)
            {
                dp[i][j] = (dp[i][j] + dp[i][j - a[i - 1]]) % mod;
            }
        }
    }
    cout << dp[n][x];
}