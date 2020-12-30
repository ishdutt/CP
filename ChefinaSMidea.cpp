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
        ll sum = n*(n+1)/2;
        if(sum%2!=0)    
        {
            printf("0\n");
            continue;
        }
        
        ll ans=0;
        if(n==3)
        {
            printf("2\n");
            continue;
        }
        ll i;

        double m= (sqrt(4*sum+1)/2)-1;
        //cout<<"M is "<<m<<endl;
        i=ceil(m);
        //cout<<"I="<<i<<endl;
        int flag=1;
        if((i)*(i+1)/2==sum/2)
        {
            //cout<<"MOSHI\n";
            ll first_half=n-i-1;
            ll seconf_half=i-1;
            ans+= (first_half*(first_half+1)/2)+(seconf_half*(seconf_half+1)/2);
            //cout<<(first_half*(first_half+1)/2)+(seconf_half*(seconf_half+1)/2)<<endl;
            flag=0;
            //i++;
        }
        
        if(i*(i+1)/2<sum/2) i++;
        //cout<<"I="<<i<<endl;
        if(flag==1)
            ans+=n-i+1;
        else
        {
            //cout<<"I here "<<i<<endl;
            ans+=n-i;
        }
        
        // cout<<"TEST "<<n-i<<endl;
        printf("%lld\n",ans);

    }
    return 0;        
}
    
