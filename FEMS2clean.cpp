#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

ll ans=0;
void mapfun(vector<pair<ll,ll>>&iron, vector<pair<ll,ll>>&metal, unordered_map<ll,ll>&maping,ll k, unordered_set<ll>&visited)
{
    for (ll i = 0; i < metal.size(); i++)
    {
        if(visited.find(i)!=visited.end())  continue;
        //PATA NAI MAP KYA KAREGA YAHA
        for(ll j=0;j<iron.size();j++)
        {
            if(visited.find(i)!=visited.end())  break;
            if(visited.find(j)!=visited.end())  continue;

            int power= k + 1 - abs(iron[j].first - metal[i].first) - abs(iron[j].second - metal[i].second);

            if(power > 0)
            {
                visited.insert(i);
                visited.insert(j);
                ans++;
                break;
            } 
        }
    }
    iron.clear();
    metal.clear();
}


int main() 
{
    ios::sync_with_stdio(false);
    
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,k;
        cin>>n;
        cin>>k;

        vector<char> a;
        //ARRAY
        for(ll i=0;i<n;i++)
        {
            char temp;
            cin>>temp;
            a.push_back(temp);
        }

        vector<pair<ll,ll>>iron;
        vector<pair<ll,ll>>metal;

        ll sheet=0;

        unordered_map<ll,ll>maping;

        unordered_set<ll>visited;
        
        for(ll i=0;i<n;i++)
        {
            if(a[i]=='I')   iron.push_back(make_pair(i,sheet));

            else if(a[i]=='M')   metal.push_back(make_pair(i,sheet));
            
            else if(a[i]==':')  sheet++;
            //ab yaha pe sahi pair khojo aur match kardo 
            else if(a[i]=='X')    mapfun(iron,metal,maping,k,visited);
        }

        mapfun(iron,metal,maping,k,visited);

        cout<<ans<<endl;
    }
    return 0;        
}
    
