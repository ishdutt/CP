#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

ll mod=1000000007;

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

        vector<ll>a(n,0);
        for(ll i=0;i<n;i++)
            cin>>a[i];


        int onepresent=0;
        ll oneindex=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)
            {
                onepresent=1;
                oneindex=i;
                break;
            }
        }

        ll sum=0;
        ll flag=0;

        vector<ll>presum(n,0);

        for(ll i=0;i<n;i++)
        {
            //last element hamesha odd hi hoga
            if(i==n-1)
            {
                if(a[n-1]%2==0)    sum=(sum +(a[n-1]-1))%mod;
                else    sum=(sum + a[i] )%mod;
            }
            else if(a[i]%2==0 || a[i]==1)   sum=(sum + a[i])%mod;
            else    sum=(sum + (a[i]-1) )%mod;     
            //TODO:CHECK IF PRESUM IS REALLY NEDDED TO BE TILL LAST?   
            presum[i]=sum;
        }

        ll q;
        cin>>q;
        while (q--)
        {
            ll r;
            cin>>r;
            if(onepresent==0 || a[n-1]==1)
            {
                ll ans=((r%mod/n)*(sum))%mod;    
                ll left=r%n;
                //HAR BAAR IF LEFT IS ZERO... THEN TAKE THE NUMBER AS IT IS
                if(left==0)
                {
                    if(a[n-1]%2==0)
                        ans= (ans+1)%mod;
                    else    ans = ans%mod;
                }    

                else
                {
                    if(left==1)     ans = (ans + (a[left-1]))%mod;
                    else    ans= (ans +(presum[left-2] +a[left-1])%mod )%mod;
                }        

                cout<<ans<<endl;
            }

            else if(a[0]==1)
            {
                //ll ans=ceil(double(r%mod)/double(n));
                ll ans= (r+n-1) / n;
                ans=ans%mod;
                ll left=r%n;
                //WHEN FIRTS ELEMENT AND ANS IS NOT 1(CEIL HAI ANS).. SO EVEN THAT ONE WILL
                // BE TAKEN BY CHEFINA
                if(left==1 && ans!=1)  ans=(ans-1)%mod;

                cout<<ans<<endl;
            }
            else
            {
                if(a[oneindex-1]%2!=0)
                {
                    ll ans=((r%mod/n)*(sum))%mod;
                    ll left=r%n;
                    if(left==0)
                    {
                        if(a[n-1]%2==0)
                            ans= (ans+1)%mod;
                        else    ans = ans%mod;
                    }    

                    else
                    {
                        if(left==1)     ans = (ans + (a[left-1]))%mod;
                        else        ans= (ans + (presum[left-2] + a[left-1])%mod)%mod;
                    }        

                    cout<<ans<<endl;
                }

                else
                {
                    ll ans=((r%mod/n)*(sum-2))%mod;
                    ll left=r%n;
                    if(left==0)
                    {
                        if(a[n-1]%2==0)
                            ans= (ans+1)%mod;

                        else    ans = ans%mod;
                    }    
                    else
                    {
                        if(left-1<=oneindex)
                        {
                            if(left==1)   ans = (ans + (a[left-1]))%mod;

                            else    ans = (ans + (presum[left-2]+a[left-1])%mod)%mod;
                        }
                        else    ans = (ans + (presum[left-2] -2 + a[left-1])%mod)%mod;
                    }        

                    cout<<ans<<endl;

                }
                
            }
            
        }
        

    }
    return 0;        
}
        
