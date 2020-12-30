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
        
        //ll i = 1;
        for(ll i=0;i<n;i++)
        {
            //FOR EACH PLAYER..CALCULATE THE AVERAGE SPEED WRT TO OTHERS NAD 
            // CHECK IF HE CAN DEFEAT OTHER OR NOT.. AND CALCULATE THE ABOVE
            //VALUE;

            // I IS THE INFECTED PERSON

        //0 -> not infected else infected
            vector<ll>infectedarray(n,0);
            infectedarray[i]=1;
            
            
            for(int j=i+1;j<n;j++)
            {   
                //AGAR SPEED LESS HAI TOH HOGA HI.. SINCE NO FINISHING TIME :)
                if(a[j]<a[i])
                {
                    infectedarray[j]=1;
                    //cout<<"MOSHI "<<a[i]<<endl;
                }
                    
                //curinfected++;
            }
            // USS INFECTED KO KITNE CROSS KARENGE :
            //GET THE ONE WITH MAX SPEED AND CHECK KI SABSE FASTEST WALA KITNO
            // KO CROSS KAREGA :)
            ll overtaker=0;
            ll overtakerindex=-1;
            for(int j=0;j<i;j++)
            {
                if(a[j]>a[i])
                    infectedarray[j]=1;
            }

            //INDEX WILL START FROM THE INFECTED PERSON :)
            //INFECTED PERSONS WILL INFECT OTHERS NOW
            for(ll k=0;k<n;k++)
            {
                
                if(infectedarray[k]!=1) continue;
                for(int j=k+1;j<n;j++)
                {
                    if(a[j]<a[k] && a[i]<=a[j] && j>i)
                    {
                        infectedarray[j]=1;
                        //cout<<"T1 "<<j<<"th position "<<a[j]<<" "<<a[k]<<endl;
                    }   
                }
                for(int j=0;j<k;j++)
                {
                    if(a[j]>a[k] && a[j]<=a[i])
                    {
                        if(a[j]==a[i] && i<j)   continue;
                        infectedarray[j]=1;
                        //cout<<"T2 "<<j<<"th position "<<a[j]<<" "<<a[k]<<endl;
                    }
                }   
                       
            }
            
            for(ll k=0;k<n;k++)
            {
                
                if(infectedarray[k]!=1) continue;
                for(int j=k+1;j<n;j++)
                {
                    if(a[j]<a[k] && a[i]<=a[j] && j>i)
                    {
                        infectedarray[j]=1;
                    }   
                }
                for(int j=0;j<k;j++)
                {
                    if(a[j]>a[k] && a[j]<=a[i])
                    {
                        if(a[j]==a[i] && i<j)   continue;
                        infectedarray[j]=1;
                    }
                }   
                       
            }
            for(ll k=0;k<n;k++)
            {
                
                if(infectedarray[k]!=1) continue;
                for(int j=k+1;j<n;j++)
                {
                    if(a[j]<a[k] && a[i]<=a[j] && j>i)
                    {
                        infectedarray[j]=1;
                    }   
                }
                for(int j=0;j<k;j++)
                {
                    if(a[j]>a[k] && a[j]<=a[i])
                    {
                        if(a[j]==a[i] && i<j)   continue;
                        infectedarray[j]=1;
                    }
                }   
                       
            }
            for(ll k=0;k<n;k++)
            {
                
                if(infectedarray[k]!=1) continue;
                for(int j=k+1;j<n;j++)
                {
                    if(a[j]<a[k] && a[i]<=a[j] && j>i)
                    {
                        infectedarray[j]=1;
                    }   
                }
                for(int j=0;j<k;j++)
                {
                    if(a[j]>a[k] && a[j]<=a[i])
                    {
                        if(a[j]==a[i] && i<j)   continue;
                        infectedarray[j]=1;
                    }
                }   
                       
            }
            
            
            
            ll curinfected=0;
            //cout<<"TEST "<<a[i]<<"============";
            for(ll j=0;j<n;j++)
            {
                //cout<<infectedarray[j]<<" ";
                if(infectedarray[j]==1)
                {
                    // cout<<"ETETET\n";
                    curinfected++;
                }     
            }
            //cout<<"\n";



            maxinfected=max(maxinfected,curinfected);
            mininfected=min(mininfected,curinfected);

        }
        
        cout<<mininfected<<" "<<maxinfected<<endl;
        
    }
    return 0;        
}
    
