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
        vector<ll> speed(n,0);
        //ARRAY
        for(int i=0;i<n;i++)
            cin>>speed[i];

        
        
        ll maxinfected=INT_MIN;
        ll mininfected=INT_MAX;
        
        
        for(ll i=0;i<n;i++)
        {
            vector<ll>a=speed;
            vector<ll>infectedarray(n,0);
            infectedarray[i]=1;

            ll overtaker=0;
            ll overtakerindex=-1;
            
            //PEHLA CASE: L1 TRANSMISSION   INFECTED HERE IS iTH PERSON
            for(int j=0;j<n;j++)
            {
                if(a[j]<a[i] && j>i)
                {
                    infectedarray[j]=1;
                    sort(a.begin()+i, a.begin()+j+1);
                }   

                if(a[i]<a[j] && i>j)
                {
                    infectedarray[j]=1;
                    sort(a.begin()+j, a.begin()+i+1);
                }   
            }

            cout<<"AFTER first case ";
            for(int j=0;j<n;j++)
                cout<<infectedarray[j]<<" ";
            cout<<"\n";

            //sort(a.begin(),a.end());

            //CASE 2: L2 SPREAD FROM INFECTED
            for(int k=0;k<n;k++)
            {
                if(infectedarray[k]==1)
                {
                    for(int j=0;j<n;j++)
                    {
                        if(a[j]<a[k] && j>k)
                        {
                            infectedarray[j]=1;
                            sort(a.begin()+k, a.begin()+j+1);
                        }   

                        if(a[k]<a[j] && k>j)
                        {
                            infectedarray[j]=1;
                            sort(a.begin()+j, a.begin()+k+1);
                        }   
                    }
                }
            }

            cout<<"AFTER 2nd case ";
            for(int j=0;j<n;j++)
                cout<<infectedarray[j]<<" ";
            cout<<"\n";

            //CASE 3: FOR COMMUNITY CASE
            for(int k=0;k<n;k++)
            {
                if(infectedarray[k]==1)
                {
                    for(int j=0;j<n;j++)
                    {
                        if(a[j]<a[k] && j>k)
                        {
                            infectedarray[j]=1;
                            sort(a.begin()+k, a.begin()+j+1);
                        }   

                        if(a[k]<a[j] && k>j)
                        {
                            infectedarray[j]=1;
                            sort(a.begin()+j, a.begin()+k+1);
                        }   
                    }
                }
            }
            
            cout<<"AFTER 3rd case ";
            for(int j=0;j<n;j++)
                cout<<infectedarray[j]<<" ";
            cout<<"\n";

           for(int k=0;k<n;k++)
            {
                if(infectedarray[k]==1)
                {
                    for(int j=0;j<n;j++)
                    {
                        if(a[j]<a[k] && j>k)
                        {
                            infectedarray[j]=1;
                            sort(a.begin()+k, a.begin()+j+1);
                        }   

                        if(a[k]<a[j] && k>j)
                        {
                            infectedarray[j]=1;
                            sort(a.begin()+j, a.begin()+k+1);
                        }   
                    }
                }
            }

            cout<<"AFTER 4th case ";
            for(int j=0;j<n;j++)
                cout<<infectedarray[j]<<" ";
            cout<<"\n";
            
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
    
