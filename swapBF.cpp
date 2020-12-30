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
        while (1)
        {
            ll tempans=0;
            sumtillm = m*(m+1)/2;

            ll dif=sum/2-sumtillm;

            if(dif==0)
            {
                ll first_half=m-1;
                ll seconf_half=n-m-1;

                ans+= (first_half*(first_half+1)/2)+(seconf_half*(seconf_half+1)/2);
                //cout<<"TEST "<<m<<endl;
                m++;
                continue;
            } 

            if(dif<0)   break;
            //SEE IF DIFFERENCE TILL THESE ELEMENTS POSSIBLE
            // for(int i=1;i+dif<=n;i++)
            // {
            //     //AGAR WO PARTITION SE PEHLE HI AA GAYA :)
            //     if(i+dif<=m) continue;
            //     //IF I IS GREATER THAN M THEN THAT NUMBER REACHES THE ORTHER SET
            //     if(i>m) continue;
            //     cout<<"DIFF= "<<dif<<"Point = "<<m<<" i= "<<i<<" i+dif="<<i+dif<<endl;
            //     // cout<<"TEST "<<tempans;
            //     tempans++;
            // }
            
            ll low=1;
            ll high=m;
            ll bsans=-1;
            while (low <= high) 
            { 
        
                ll mid = low + (high - low + 1) / 2;  

                if (mid+dif >n) high = mid - 1; 

                else if (mid+dif <= m)     low = mid + 1; 
        
                else if (mid+dif >m && mid+dif<=n) 
                { 
                    bsans = mid; 
                    high = mid - 1; 
                } 
            } 

            tempans=min(m-bsans+1,n-bsans-dif+1);
            if(bsans<0)   tempans=0;

            ans+=tempans;
            m++;
        }
        cout<<ans<<endl;
        
    }
    return 0;        
}
    
