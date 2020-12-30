#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

int solve(int n,int t,int k,int p)
{
    while (t--)
        {
            // ll n,X,p,k;
            // cin>>n>>X>>p>>k;
            
            int max = 100; //set the upper bound to generate the random number
            srand(time(0));
                
            vector<ll>a(n,0);

            // for(ll i=0;i<n;i++)
            //     a[i]=rand()%max;
            a[0]=3,a[1]=28,a[2]=30,a[3]=62,a[4]=70;

            ll X=29;
            
            cout<<"n="<<n<<" p="<<p<<" k="<<k<<" X="<<X<<endl;

            sort(a.begin(),a.end());

            cout<<"ARRAY is= ";
            for(int i=0;i<n;i++)
                cout<<a[i]<<" ";
            cout<<endl;

            ll xindex=0;
            ll xispresent=0;

            //if(X present)
            for(ll i=0;i<n;i++)
                if(a[i]==X)
                {
                    xindex=i;
                    xispresent=1;
                }

            // if(k==p)
            // {
            //     if(xindex==a[k-1])
            //     {
            //         cout<<"0\n";
            //         continue;
            //     }
            //     else
            //     {
                    
            //     }
                
            // }

            //1ST SMALLEST REFERS TO 0TH ELEMENT ;)
            if(xispresent)
            {

                //cout<<"TEST="<<a[k-1]<<" "<<a[p-1]<<" "<<X<<endl;
                if(xindex==p-1)
                {
                    cout<<"0\n";
                    continue;
                }

                //NEGATIVE CASES:
                else if(k-1<xindex && xindex<p-1)
                {
                    cout<<"-1\n";
                    continue;
                }
                else if(p-1<xindex && xindex<k-1)
                {
                    cout<<"-1\n";
                    continue;
                }

                else if(k-1==xindex || (p-1<k-1 && k-1<xindex)||(xindex<k-1 && k-1<p-1))
                {
                    cout<<"-1\n";
                    continue;
                }
                //POSITIVE CASES WITH NUM. OF STEPS
                
                cout<<abs(xindex+1-p)<<endl;
                
            }
            if(!xispresent)
            {
                
                //cout<<"TEST="<<k<<" "<<p<<" "<<X<<endl;
                // cout<<a[]
                if(X>a[p-1] && X<a[p] && p>k)
                {
                    //cout<<"MOSHI\n";
                    cout<<"1\n";
                    continue;
                }


                else if(X<a[p-1] && a[p-1]<a[k-1])
                {
                    //COUNT NUMBER OF STEPS... YES CASE
                    cout<<min(p,n-p+1)<<endl;
                    continue;
                }
                else if(a[k-1]<a[p-1] && a[p-1]<X)
                {
                    //COUNT NUMBER OF STEPS... YES CASE
                    cout<<min(p,n-p+1)<<endl;
                    continue;
                }
                else if(k==p)
                {
                    //FIXME:
                    //cout<<"MOOHI";
                    if(a[k-1]>X && a[k-2]<X)
                    {
                        cout<<"1\n";
                        continue;
                    }
                    else
                    {
                        a[k-1]=X;
                        sort(a.begin(),a.end());
                        
                        //x index
                        ll Xindex=0;
                        for(ll i=0;i<n;i++)
                            if(a[i]==X)
                                Xindex=i;
                        
                        if(Xindex==p-1)
                        {
                            //cout<<"MOSHI\n";
                            cout<<"1\n";
                            continue;
                        }
                        else
                        {
                            //FIXME:
                            /*
                            1
                            5 25 3 3
                            1 20 30 40 50
                            */
                            //cout<<"YO\n";
                            //DON'T FORGET TO COUNT THE 1 (ALREADY DONE ONE TRANSFORMATION)
                            //cout<<Xindex<<endl;
                            cout<<abs(Xindex-k+1)+1<<endl;
                            continue;
                        }
                        
                    }
                    
                    cout<<"1\n";
                    continue;
                }
                else
                {
                    //K.. X(lies in between the min and max)..P
                    //OR REVERSE CASE...P..X..K

                    a[k-1]=X;
                    sort(a.begin(),a.end());
                        
                    //x index
                    ll Xindex=0;
                    for(ll i=0;i<n;i++)
                        if(a[i]==X)
                            Xindex=i;
                    
                    if(xindex==p-1)
                    {
                        cout<<"1\n";
                        continue;
                    }

                    //NEGATIVE CASES:
                    else if(k-1<xindex && xindex<p-1)
                    {
                        cout<<"-1\n";
                        continue;
                    }
                    else if(p-1<xindex && xindex<k-1)
                    {
                        cout<<"-1\n";
                        continue;
                    }

                    else if(k-1==xindex || (p-1<k-1 && k-1<xindex)||(xindex<k-1 && k-1<p-1))
                    {
                        cout<<"-1\n";
                        continue;
                    }
                    //POSITIVE CASES WITH NUM. OF STEPS
                    
                    cout<<abs(Xindex+1-p)<<endl;
                    
                    continue;
                }
                
            }
        }
}


int main() 
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;

    ll n,p,k;
    //cin>>n>>X>>p>>k;
    n=5;
        for(int j=1;j<n+1;j++)
        {
            p=j;
            for(int it=1;it<n+1;it++)
            {
                k=it;
                int max = 100; //set the upper bound to generate the random number
                srand(time(0));
                //X=rand()%max;
                
                solve(n,t,k,p);
            }
        }
        
   
    return 0;        
}
    
