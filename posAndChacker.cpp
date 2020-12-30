#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;


int main() 
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    ll n;
    
    while (t--)
    {
        for(ll p=1;p<=100000;p++)
        {
            n=p;
            cout<<"n="<<n<<endl;
             //IF POWER OF 2 THEN -1
        ll temp=n;
        if(temp>0)
        {   
            if(temp!=0 && temp&(temp-1)==0)
            {
                cout<<"-1"<<endl;
                continue;
            }

        }

        if(n==1)
        {
            cout<<"1"<<endl;
            continue;
        }

        //NOT POWER OF TWO
        //CONTAINS THE SEQUENCE;
        vector<ll>ans(n,0);
        ans[0]=2;
        ans[1]=3;
        ans[2]=1;
        //PUT ODD CHARS AT THE END OF EACH BOUNDRY OF NEW 2 POWER

        ll prevpoweroftwo=2;
        for(ll i=3;i<n;i++)
        {
            //SINCE WE KNOW THAT THIS WILL GO MIN OF 2**K+1(WHICH IS ODD SO WE WILL KEEP IT)
            //PUT I+1 IN A[I+1] POSITION IF MEET WITH OTHER ODD NUMBER... THEN STORE IT AND KEEP IT
            // IN THE LAST PLACE
            
            if((i+1)==prevpoweroftwo*2)
            {
                prevpoweroftwo=i+1;
                ans[i]=i+2;
                ans[i+1]=i+1;
                i++;
            }
            else
            {
                //STORING THE LAST NUMBER(WHICH WILL BE 2**K-1 ALWAYS)
                ans[i]=i+1;
            }
            
            
        }
        if(n>12345)
        ans[12345]=INT_MAX;

        //PRINT
        for(int i=0;i<n-1;i++)
        {
            //check for garbage value
            // cout<<ans[i+1]<<" ";
            if(ans[i]&ans[i+1]==0 || ans[i]>n || ans[i]<1)
            {
                cout<<"NIKAL RE+====================\n";
                goto end;
                for(int j=0;j<i;j++)
                {
                    cout<<ans[i]<<" "<<ans[j]<<endl;
                    if(ans[i]==ans[j])
                    {
                        cout<<"MOSHI\n";
                        goto end;
                    }
                }
            }
        }
            
        
        }

        //IF N==1 ?
    }
    end:
        cout<<"ABORTED\n";
    return 0;        
}
    
