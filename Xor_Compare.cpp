#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while (t--)
    {
        ll x,y,n;
        cin>>x>>y>>n;

        ll jump=max(x,y);

        if(y==x)
        {
            cout<<0<<endl;
            continue;
        }
        cout<<"TEST="<<jump<<endl;
        if(y>x)
        {
            ll times=n/jump;
            //even 
            if(times%2!=0)
            {
                cout<<(((times)/2))*jump<<endl;

            }
            else
            {
                cout<<ceil(double(times)/2.0)*jump + (n%jump)<<endl;
                
            }
            
        }

        else
        {
            ll times=n/jump;
            if(times%2==0)
            {
                cout<<(times-1)*jump<<endl;
            }
            else
            {
                cout<<(times-1)*jump + (n%jump)<<endl;
            }
        }
        
    }
    return 0;        
}
    
