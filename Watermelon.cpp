#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;


int main() 
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vector<ll> a;
        //ARRAY
        for(ll i=0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            a.push_back(temp);
        }
        //cout<<"MOSHI\n";
        int flag=1;
        ll sum=0;
        for(ll i=0;i<n;i++)
            sum+=a[i];
        
        if(sum<0)
        {
            cout<<"NO\n";
            continue;
        }  
        else
        {
            cout<<"YES\n";
            continue;
        }
          
        // for(ll i=0;i<n;i++)
        // {
        //     if(a[i]%(i+1)!=0 || a[i]<0)
        //     {
        //         cout<<"NO\n";
        //         flag=0;
        //         break;
        //     }
        // }
        // if(flag==1)
        //     cout<<"YES\n";
    }
    return 0;        
}
    
