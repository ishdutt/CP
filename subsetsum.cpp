#include<bits/stdc++.h>
using namespace std;
typedef long long      ll;


int main() 
{
  	ll c;
	ll n = 0;
	cin >> n;

	c=n*(n+1)/4;

	vector<ll> w(n);
	ll sumtilln = 0;
	ll k=2;
	for (ll j = 0; j < n; ++j) 
		w[j]=j+1;
	
	sumtilln=n*(n+1)/2;
	
	if(sumtilln%2==0)	cout<<"0\n";
	else	cout<<"1\n";

	ll b;
	ll w_bar = 0;
	for (b = 0; w_bar + w[b] <= c; ++b) 
		w_bar += w[b];
	
	vector<vector<ll> > s(n - b + 1, vector<ll>(2 * n));
	auto  s_b_1 = s[0].begin() + (n - 1);
	
	for (ll mu = -n + 1; mu <= 0; ++mu) 
		s_b_1[mu] = -1;
	
	for (ll mu = 1; mu <= n; ++mu) 
		s_b_1[mu] = 0;
	
	s_b_1[w_bar - c] = b;

	for (ll t = b; t < n; ++t) 
	{
		auto s_t_1 = s[t - b].begin() + (n - 1);
		auto  s_t = s[t - b + 1].begin() + (n - 1);

		for (ll mu = -n + 1; mu <= n; ++mu) 
			s_t[mu] = s_t_1[mu];
		

		for (ll mu = -n + 1; mu <= 0; ++mu) 
		{
			ll mu_prime = mu + w[t];
			s_t[mu_prime] = max(s_t[mu_prime], s_t_1[mu]);
		}

		for (ll mu = w[t]; mu >= 1; --mu) 
		{
			for (ll j = s_t[mu] - 1; j >= s_t_1[mu]; --j) 
			{
				ll mu_prime = mu - w[j];
				s_t[mu_prime] = max(s_t[mu_prime], j);
			}
		}
	}
	bool solved = false;
	ll z;
	auto s_n_1 = s[n - b].begin() + (n - 1);
	for (z = 0; z >= -n + 1; --z) 
	{
		if (s_n_1[z] >= 0) 
		{
			solved = true;
			break;
		}
	}
	if (solved) 
	{
		//cout << c + z << '\n' << n << '\n';
		vector<bool> x(n, false);
		for (ll j = 0; j < b; ++j) x[j] = true;
		for (ll t = n - 1; t >= b; --t) 
		{
			auto s_t = s[t - b + 1].begin() + (n - 1);
			auto s_t_1 = s[t - b].begin() + (n - 1);
			while (true) 
			{
				ll j = s_t[z];
				assert(j >= 0);
				ll z_unprime = z + w[j];
				if (z_unprime > n || j >= s_t[z_unprime]) break;
				z = z_unprime;
				x[j] = false;
			}
			ll z_unprime = z - w[t];
			if (z_unprime >= -n + 1 && s_t_1[z_unprime] >= s_t[z]) 
			{
				z = z_unprime;
				x[t] = true;
			}
		}

		for (ll j = 0; j < n; ++j)
			cout << x[j] << ' ';
		
		cout<<endl;
		
	}
}