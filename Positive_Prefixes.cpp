#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        
        vector<int>a;
        for(int i=0;i<n;i++)
            a.push_back(i+1);

        if(k==n/2)
        {
            for(int i=0;i<n;i++)
            {
                if(i%2==0)  cout<<-a[i]<<" ";

                else    cout<<a[i]<<" ";
            }
            cout<<endl;
            continue;
        }
        if(k<n/2)
        {
            ll temp=k;
            for(int i=0;i<n;i++)
            {
                if(k==0)
                {
                    a[i]=-a[i];
                }    
                else if(i%2==0)  a[i]=-a[i];

                else
                {
                    a[i]=a[i];
                    k--;
                }    
            }

            for(int i=0;i<n;i++)
                cout<<a[i]<<" ";

            cout<<endl;
        }
        if(k>n/2)
        {

            for(int i=0;i<n;i++)
            {
                if(i%2==0)  a[i]=-a[i];

                else    a[i]=a[i];
            }
            k=k-n/2;
            for(int i=n-1;i>=0;i--)
            {
                if(k==0)    break;
                if(a[i]<0)
                {
                    a[i]=-a[i];
                    k--;
                }
            }

            for(int i=0;i<n;i++)
                cout<<a[i]<<" ";
            cout<<endl;
            continue;
        }
    }
    return 0;        
}
    
