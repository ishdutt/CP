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
        vector<ll> a(n,0);
        //ARRAY
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        ll maxinfected=INT_MIN;
        ll mininfected=INT_MAX;
        
        
        for(ll i=0;i<n;i++)
        {
            vector<ll>infectedarray(n,0);
            infectedarray[i]=1;

            ll overtaker=0;
            ll overtakerindex=-1;
            for(int j=0;j<i;j++)
            {
                if(a[j]>a[i])
                {
                    infectedarray[j]=1;

                    for(ll k=j+1;k<n;k++)
                        if(a[j]>a[k])
                        {
                            cout<<"CONAN\n";
                            infectedarray[k]=1;
                        }  


                    for(ll k=0;k<j;k++)
                        if(a[j]>a[k] && a[k]>a[i])
                        {
                            cout<<"MOURI\n";
                            infectedarray[k]=1;
                        }  


                    if(overtaker<a[j])
                    {
                        cout<<"HELLO "<<a[j]<<endl;
                        overtaker=a[j];
                        overtakerindex=j;

                    }
                }   
            }
            if(overtakerindex!=-1)
                infectedarray[overtakerindex]=1;

            // for(ll k=i+1;k<n;k++)
            //     if(overtaker>a[k])  infectedarray[k]=1;

            for(int j=i+1;j<n;j++)
            {   
                if(a[j]<a[i])
                {
                    infectedarray[j]=1;
                    cout<<"MOSHI "<<a[j]<<endl;
                    
                    for(ll k=0;k<j;k++)
                        if(a[j]>a[k])  infectedarray[k]=1; 
                }                  

                 
            }

            
            ll curinfected=0;
            cout<<"TEST "<<a[i]<<"============";
            for(ll j=0;j<n;j++)
            {
                cout<<infectedarray[j]<<" ";
                if(infectedarray[j]==1)
                    curinfected++;
            }
            cout<<"\n";

            maxinfected=max(maxinfected,curinfected);
            mininfected=min(mininfected,curinfected);

        }
        
        cout<<mininfected<<" "<<maxinfected<<endl;
        
    }
    return 0;        
}
    
