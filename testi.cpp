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

        //Iron CENTRIC WORK
        ll power=k+1;
        ll icount=0;
        ll mcount=0;
        ll ans=0;
        ll firstI=0;
        //MORE LIKE KADANE'S ALGORITHM
        //TRY BACKWARD... FORWARD,... KEEPING I AS CENTER AND ,M AS CENTER(Max number of situations)
        for(ll i=0;i<n;i++)
        {
            //cout<<"TEST="<<power<<endl;
            if(a[i]=='I')
            {
                power+=i;
                icount++;
                firstI=1;
            }  
            if(firstI!=1)   continue;

            else if(a[i]=='M')
            {
                if(power-i>0)
                    mcount++;
            } 
            else if(a[i]==':')
                power--;
            
            else if(a[i]=='X')
            {
                ans+=min(icount,mcount);
                icount=0;
                mcount=0;
            }
        }
        cout<<"TEST="<<icount<<mcount<<endl;

        ll icountb=0;
        ll mcountb=0;
        power=k+1;
        firstI=0;
        for(ll i=n-1;i>0;i--)
        {
            //cout<<"TEST="<<power<<endl;
            if(a[i]=='I')
            {
                power+=i;
                icountb++;
                firstI=1;
            }  
            if(firstI!=1)   continue;

            else if(a[i]=='M')
            {
                if(power-i>0)
                    mcountb++;
            } 
            else if(a[i]==':')
                power--;
            
            else if(a[i]=='X')
            {
                ans+=min(icountb,mcountb);
                icountb=0;
                mcountb=0;
            }
        }
        cout<<"VAL="<<icount<<" "<<mcount<<" "<<icountb<<" "<<mcountb<<endl;
        ans+=max(min(icount,mcount),min(icountb,mcountb));
        cout<<ans<<endl;
    }
    return 0;        
}
    
