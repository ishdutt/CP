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
        ll n,k,l;
        cin>>n>>k>>l;
        if(n>k*l)
        {
            cout<<"-1"<<endl;
            continue;
        }
        if(k==1 && n>1)
        {
            cout<<"-1"<<endl;
            continue;
        }
        ll i,j;
        for( i=0;i<n;i++)
        {
            for(j=0;i<n;j++,i++)
            {
                if(i==n-1)
                {
                    cout<<(j%k)+1;
                    break;
                }
                cout<<(j%k)+1<<" ";
            }
                
        }

        cout<<endl;

    }
    return 0;        
}
    
