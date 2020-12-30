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
        ll n,k;
        cin>>n>>k;
        vector<ll>a(n,0);
        for(ll i=0;i<n;i++)
            cin>>a[i];
        
        for(ll i=0;i<n;i++)
        {
            if(a[i]%k==0)   a[i]=1;

            else
            {
                a[i]=0;
            }
            cout<<a[i];
        }
        cout<<endl;

    }
    return 0;        
}
    
