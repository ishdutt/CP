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
        vector<ll>u(n-1,0);
        vector<ll>v(n-1,0);

        for(ll i=0;i<n-1;i++)
        {
            cin>>u[i]>>v[i];
        }
        
        ll p=0;
        for(ll i=0;i<n-1;i++)
        {
            if(u[i]==1)
                p+=1;
        }
        //cout<<p<<endl;
        if(p==n-1 || p==n-2)
        {
            cout<<"0\n";
            continue;
        }
        else
        {
            cout<<n-2-p<<endl;
            continue;
        }

    }
    return 0;        
}
    
