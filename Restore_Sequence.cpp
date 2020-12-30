#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

const ll MAX = 4000000; 


void primesInRange(vector<ll>&prime)
{
    for (ll i = 2; i <= MAX; i++)
    {
        if(prime.size()==100000)    return ;
        
        ll c = 0;
        for (ll j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                c = 1;
                break;
            }
        }
        if (c == 0)
            prime.push_back(i);
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long int> prime;

    primesInRange(prime);
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vector<ll> b;
        //ARRAY
        for(ll i=0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            b.push_back(temp);
        }
        ll a[n]={0};

        //cout<<"TEST="<<primelist[primelist.size()-1]<<endl;


        for(ll i=0;i<n;i++)
            a[i]=prime[i];

        ll finalans[n] = {0};
        
        for(ll i=0;i<n;i++)
        {
            if(b[i]==i+1)   finalans[i]=a[i];

            else if(b[i]!= i+1)  finalans[i]=a[b[i]-1];
        }     
        
        for(ll i=0;i<n;i++)
            cout<<finalans[i]<<" ";
        
        cout<<endl;

    }
    return 0;        
}
    
