#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;


bool cmp(pair<pair<ll,ll>,ll>a, pair<pair<ll,ll>,ll>b) 
{ 
    return a.first.second < b.first.second; 
} 
  
double fractionalKnapsack(vector<ll>&wt,vector<ll>&val, int capacity) 
{ 
    vector<pair<pair<ll,ll>,ll>>ival;

    for(ll i=0;i<wt.size();i++)
    {
        if(wt[i]!=0)
            ival.push_back(make_pair(make_pair(wt[i],val[i]),i));
    }

    sort(ival.begin(),ival.end(),cmp);

    ll totalans=0;

    for(ll i=0;i<ival.size();i++)
    {
        ll currwt=ival[i].first.first;
        ll currval=ival[i].first.second;

        if(capacity-currwt>=0)
        {
            capacity-=currwt;
            totalans+=currval;
        }

        else
        {
            ll fraction = capacity/currwt;
            totalans+=currval*fraction;

            capacity-= currwt * fraction;
            break;
        }
        
    }
    return totalans;
} 

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vector<ll> fuel;
        //ARRAY
        for(ll i=0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            fuel.push_back(temp);
        }
        vector<ll> cost;
        //COST ARRAY
        for(ll i=0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            cost.push_back(temp);
        }

        for(ll i=0;i<n;i++)
            cost[i]*=fuel[i];
        
        ll ans=fractionalKnapsack(fuel,cost,n);

        cout<<ans<<endl;

    }
}
    
