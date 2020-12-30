#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;


int main() 
{
    ios::sync_with_stdio(false);

    ll r,c;
    cin>>r>>c;
    string ans="";
    if(r==1)
    {
        ans+='U';
        for(ll i=0;i<c-1;i++)
            ans+='R';
        cout<<ans<<endl;
    }
    else
    {
        ll dir=0;

        for(ll i=0;i<r;i++)
        {
            ans+='U';
            if(dir==0)
            {
                if(i==0)
                {
                    for(ll j=0;j<c;j++)
                        ans+='R';
                }
                else if(i==r-1)
                {
                    for(ll j=0;j<c-2;j++)
                        ans+='R';
                }
                else
                {
                    for(ll j=0;j<c-1;j++)
                        ans+='R';
                }
                
                
                dir=1;
                continue;
            }
            if(dir==1)
            {
                if(i==r-1)
                {
                    for(ll j=0;j<c-2;j++)
                        ans+='L';
                }
                else
                {
                    for(ll j=0;j<c-1;j++)
                        ans+='L';
                }
                dir=0;
                continue;   
            }

        }
        cout<<ans<<endl;
    }
    
    
    
    return 0;        
}
    
