#include <iostream>
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
        
        ll m=n/2;
        ll ans=0;
        ll sumtillm =0;
        if(n==3)
        {
            printf("2\n");
            continue;
        }
        // ll i;
        // ll tempsum=0;
        // for (i=1;;i++)
        // {
        //     sumtillm+=i;
        //     if(sumtillm==sum/2)
        //     {
        //         ll first_half=i-1;
        //         ll seconf_half=n-i-1;
        //         //cout<<"TEST "<<n-i-1<<" "<<i-1<<"\n";
        //         tempsum= (first_half*(first_half+1)/2)+(seconf_half*(seconf_half+1)/2);                
        //         continue;
        //     }   
        //     ans++;
        //     if(sumtillm>sum/2)
        //         break;
        // }

        ll low=n/2;
        ll high=n;
        ll bsans=-1;
        ll jabequalhai=0;
        while (low <= high) 
        { 

            ll mid = low + (high - low + 1) / 2;  

            ll tempsum=mid*(mid+1)/2;
            
            cout<<"mid="<<mid<<" tempsum"<<tempsum<<" sum/2="<<sum/2<<endl;

            if (tempsum >sum/2)
            {
                bsans = mid;
                high = mid - 1; 
            }

            else if (tempsum==sum/2 )
            {
                //cout<<"MId "<<mid<<"\n";
                ll first_half=mid-1;
                ll seconf_half=n-mid-1;
                jabequalhai= (first_half*(first_half+1)/2)+(seconf_half*(seconf_half+1)/2);                
                bsans=mid;
                break;
            }     
    
            else if (tempsum<sum/2) 
            { 
                low=mid+1;
                bsans = mid; 
            } 
        } 
        //cout<<"TEST "<<bsans<<"\n";
        //cout<<"JAB EQUALS mile "<<jabequalhai<<"\n";
        // tempans=min(m-bsans+1,n-bsans-dif+1);
        // if(bsans<0)   tempans=0;

        // if(jabequalhai!=0)
        //     bsans--;
        //cout<<"JAB EQUAL HAI "<<jabequalhai<<endl;        
        printf("%lld\n",n-bsans+jabequalhai);        
    }
    return 0;        
}
    
    