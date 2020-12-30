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
        //calculat sum
        ll sum = n*(n+1)/2;

        if(sum%2!=0)    
        {
            cout<<"0\n";
            continue;
        }
        
        
        ll m=1;
        ll ans=0;
        ll sumtillm = m*(m+1)/2;
        if(n==3)
        {
            cout<<"2\n";
            continue;
        }
        
        for(ll m=1;m<=n;m++)
        {
            for(ll i=1;i<=m;i++)
            {
                for(ll j=m+1;j<=n;j++)
                {
                    sumtillm=m*(m+1)/2;
                    if(sumtillm-i+j==sum/2)
                    {
                        ans++;
                        //cout<<"M pointer="<<m<<" I="<<i<<" J="<<j<<endl;
                    } 
                }
            }
        }
        
        cout<<ans<<endl;
        
    }
    return 0;        
}
    
