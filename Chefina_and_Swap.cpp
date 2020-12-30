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
        //IF NOT DIVISIBLE BY 2.. THEN NOT CONSIDERED..
        if(sum%2!=0)    
        {
            printf("0\n");
            continue;
        }

        //cout<<"TEST HAI YE "<<fact(13)<<endl;
        
        
        ll m=n/2;
        ll ans=0;
        ll sumtillm = m*(m+1)/2;
        if(n==3)
        {
            printf("2\n");
            continue;
        }
        //FOR EVERY POSSIBLE M WE CHECK IF IT IS POSSIBLE TO GET THE PAIRS
        while (1)
        {
            ll tempans=0;
            sumtillm = m*(m+1)/2;

            ll dif=sum/2-sumtillm;
            //AGAR DIFF IS EQUAL TO 0 THEN JUST INCREMENT THE ONE AND 
            // IGNORE THE
            //FIXME: 3,20,696 etc :)
            if(dif==0)
            {
                ll first_half=m-1;
                ll seconf_half=n-m-1;

                ans+= (first_half*(first_half+1)/2)+(seconf_half*(seconf_half+1)/2);
                cout<<"EQUAL CAE "<<(first_half*(first_half+1)/2)+(seconf_half*(seconf_half+1)/2)<<endl;
                //cout<<"TEST "<<m<<endl;
                m++;
                continue;
            }   

            if(dif<0)   break;
            //SEE IF DIFFERENCE TILL THESE ELEMENTS POSSIBLE
            for(ll i=1;i+dif<=n;i++)
            {
                //AGAR WO PARTITION SE PEHLE HI AA GAYA :)
                if(i+dif<=m) continue;
                //IF I IS GREATER THAN M THEN THAT NUMBER REACHES THE ORTHER SET
                if(i>m)     break;
                
                //cout<<m<<" "<<sumtillm<<" difference "<<dif<<" i+dif="<<i+dif<<endl;
                cout<<"DIFF= "<<dif<<"Point = "<<m<<" i= "<<i<<" i+dif="<<i+dif<<endl;

                tempans++;
            }
            

            //BINARY SEARCH THE FIRST ELEMENT :) THEN USE THE DIFFERNCE TO GET THE ANSWER
            
            ans+=tempans;
            m++;
        }
        printf("%lld\n",ans);
        
    }
    return 0;        
}
    
