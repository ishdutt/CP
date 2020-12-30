#include<bits/stdc++.h>
using namespace std;
typedef long long      ll;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    ll k;
    cin>>k>>t;
    while (t--)
    {
        
        ll n;
        cin >> n;
        //SEARCH FOR SUM/2
        ll limit=n*(n+1)/4;

        if(n==1)
        {
            cout<<"1"<<endl;
            cout<<"1\n";
            continue;
        }

        vector<ll> a(n,0);
        ll sumtilln = 0;
        // ll k=2;
        for (ll i = 0; i < n; i++) 
            a[i]=i+1;
        
        sumtilln=n*(n+1)/2;
        
        if(sumtilln%2==0)	cout<<"0\n";
        else	cout<<"1\n";

        ll b;
        ll w_bar = 0;
        for (b = 0; w_bar + a[b] <= limit; b++) 
            w_bar += a[b];
        
        vector<vector<ll> > s(n - b + 1, vector<ll>(2 * n));
        auto  s_b_1 = s[0].begin() + (n - 1);
        
        for (ll i = 1-n; i <= 0; i++) 
            s_b_1[i] = -1;
        
        for (ll i = 1; i <= n; i++) 
            s_b_1[i] = 0;
        
        s_b_1[w_bar - limit] = b;

        for (ll t = b; t < n; t++) 
        {
            auto s_t_1 = s[t - b].begin() + (n - 1);
            auto  s_t = s[t - b + 1].begin() + (n - 1);

            for (ll i = 1-n; i <= n; i++) 
                s_t[i] = s_t_1[i];
            

            for (ll i = 1-n; i <= 0; i++) 
            {
                ll z = i + a[t];
                s_t[z] = max(s_t[z], s_t_1[i]);
            }

            for (ll i = a[t]; i >= 1; i--) 
            {
                for (ll j = s_t[i] - 1; j >= s_t_1[i]; j--) 
                {
                    ll z = i - a[j];
                    s_t[z] = max(s_t[z], j);
                }
            }
        }
        bool solved = false;
        ll z;
        auto s_n_1 = s[n - b].begin() + (n - 1);
        for (z = 0; z >= 1-n; z--) 
        {
            if (s_n_1[z] >= 0) 
            {
                solved = true;
                break;
            }
        }
        if (solved) 
        {
            //cout << limit + z << '\n' << n << '\n';
            vector<bool> setformed(n, false);
            for (ll j = 0; j < b; j++) setformed[j] = true;
            for (ll t = n - 1; t >= b; t--) 
            {
                auto s_t = s[t - b + 1].begin() + (n - 1);
                auto s_t_1 = s[t - b].begin() + (n - 1);
                while (true) 
                {
                    ll j = s_t[z];
                    assert(j >= 0);
                    ll z_unprime = z + a[j];
                    if (z_unprime > n || j >= s_t[z_unprime]) break;
                    z = z_unprime;
                    setformed[j] = false;
                }
                ll z_unprime = z - a[t];
                if (z_unprime >= -n + 1 && s_t_1[z_unprime] >= s_t[z]) 
                {
                    z = z_unprime;
                    setformed[t] = true;
                }
            }

            for (ll j = 0; j < n; j++)
                cout << setformed[j] << ' ';
            
            cout<<endl;
            
        }
    }
    return 0; 
}