#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define MOD 998244353

void solve();

int main()
{
	ll t = 1;
	// cin>>t;
	while (t--)
	{
		solve();
	}
}

ll modpow(ll n, ll p, ll mo)
{
	if (p == 0)
		return 1;
	if (p == 1)
		return n % mo;
	else
	{
		ll x = modpow(n, p / 2, mo);
		if (p % 2 == 0)
			return (x * x) % mo;
		else
			return (((x * x) % mo) * n) % mo;
	}
}

ll m, k, d;
vector<ll> bit_freq(35, 0);

void freq_setter(){
    for(ll j=0;j<35;j++){
        long long g = 1LL << (j + 1);
        bit_freq[j]= (m/g)*(g/2)+max(0LL,m % g-(g / 2)+1);
    }
}

ll binpow(ll a, ll b)
{
	a %= MOD;
	ll res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
ll inv(ll a)
{
	return binpow(a, MOD - 2);
}

vector<ll> inverse_of_power_of_m(2005, 0);
void set_inverse_of_power_of_m()
{
	ll p = 1;
	inverse_of_power_of_m[0] = 1;
	for (ll i = 1; i < 2004; i++)
	{
		p *= m;
		p %= MOD;
		inverse_of_power_of_m[i] = inv(p);
	}
}

vector<vector<ll>> path_xor_bitwise(2005, vector<ll>(32, 0));

void set_path_xor_bitwise(){
    for(ll j=0;j<32;j++){
        path_xor_bitwise[0][j]=0;
    }
    for(ll j=0;j<32;j++){
        path_xor_bitwise[1][j]=bit_freq[j]*inverse_of_power_of_m[1];
        path_xor_bitwise[1][j]%=MOD;
    }
    for(ll j=0;j<32;j++){
        path_xor_bitwise[2][j]=(bit_freq[j]*(m-bit_freq[j]))*2;
        path_xor_bitwise[2][j]%=MOD;
        path_xor_bitwise[2][j]*= inverse_of_power_of_m[2];
        path_xor_bitwise[2][j]%=MOD;
    }
    // cout<<path_xor_bitwise[2][0]<<" "<<(m-bit_freq[0])<<endl;
    for(ll i=3;i<=2003;i++){
        for(ll j=0;j<32;j++){
            path_xor_bitwise[i][j]=((path_xor_bitwise[i-1][j]*(m-bit_freq[j]))%MOD)*inverse_of_power_of_m[1];
            path_xor_bitwise[i][j]%=MOD;
            path_xor_bitwise[i][j]+= (bit_freq[j]*inverse_of_power_of_m[1])%MOD;
            path_xor_bitwise[i][j]%=MOD;
            // if(i==3 && j==0)cout<<path_xor_bitwise[3][0]<<endl;
            path_xor_bitwise[i][j]-=(((path_xor_bitwise[i-1][j]*bit_freq[j])%MOD)*inverse_of_power_of_m[1])%MOD;
            // path_xor_bitwise[i][j]%=MOD;
            path_xor_bitwise[i][j]+=MOD;
            path_xor_bitwise[i][j]%=MOD;
            // if(i==3 && j==0)cout<<path_xor_bitwise[3][0]<<endl;
        }
    }
}

vector<ll> path_xor(2005, 0);
void set_path_xor()
{
    // cout<<path_xor_bitwise[3][0]<<"kfv"<<endl;
	for (ll i = 0; i <= 2003; i++)
	{
		for (ll j = 0; j < 32; j++)
		{
			path_xor[i] += (1LL<<j) * path_xor_bitwise[i][j];
			path_xor[i] %= MOD;
    // if(i==3)cout<<path_xor[3]<<endl;
		}
	}
}

void solve()
{
	// ll m,k,d;
	cin >> m >> k >> d;
    
	freq_setter();
	set_inverse_of_power_of_m();
	set_path_xor_bitwise();
	set_path_xor();
    // for(int i=0;i<6;i++)
    // {
    //     cout<<path_xor[i]<<" ";
    // }
	// vector<ll> num_paths(2 * d + 2, 0);

	// num_paths[size][depth]
	vector<vector<ll>> num_paths(2 * d + 10, vector<ll>(d + 2, 0));

	for (ll dep = 1; dep <= d + 1; dep++)
	{
		for (ll i = 1; i <= 2 * dep + 1; i++)
		{
			if (i - 1 <= dep)
				num_paths[i][dep] += modpow(k, i - 1, MOD);
			num_paths[i][dep] %= MOD;
			ll min_j = max(i - dep - 1, 1ll);
			ll max_j = min(dep, (i + 1) / 2 - 1);

			ll val = (((k * (k - 1) % MOD) * modpow(k, i - 3, MOD)) % MOD);

			if (max_j < min_j)
				continue;
			num_paths[i][dep] += ((max_j - min_j + 1) * val) % MOD;
			num_paths[i][dep] %= MOD;

			if ((i - 1) % 2 == 0 && (i - 1) / 2 >= min_j && (i - 1) / 2 <= max_j)
			{
				num_paths[i][dep] -= (val * inv(2))%MOD;
				num_paths[i][dep] += MOD;
				num_paths[i][dep] %= MOD;
			}
		}
	}

	// for(int i=0;i<=2*3+1;i++)
	// {
	// 	cout<<num_paths[i][3]<<" ";
	// }

	// vector<ll> xr(2*d+2);

	vector<ll> recur(d+1, 0);

	recur[0] = path_xor[1];
	for(int i=1;i<=d;i++)
	{
		recur[i] += (k*recur[i-1]) % MOD;

		for(int j=1;j<=2*i+1;j++)
		{
			recur[i] += (num_paths[j][i] * path_xor[j])%MOD;
			recur[i] %= MOD;
		}

	}

	// for(int i=0; i<=10;i++)
	// 	cout<<path_xor[i]<<" ";

	// for(auto x : num_paths)
	// 	cout<<x<<" ";
	// cout<<"\n";
	// cout<<"\n";
	cout<<recur[d]<<"\n";
}