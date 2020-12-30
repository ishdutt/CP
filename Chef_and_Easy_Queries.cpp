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
        
        ll carry=0;
        ll flag=0;
        for(ll i=0;i<n;i++)
        {
            if(a[i]+carry<k)
            {
                cout<<i+1<<endl;
                flag=1;
                break;
            }
            carry=a[i]+carry-k;
        }
        ll extradays=0;
        if(flag==1)
        {
            continue;
        }
        if(carry==0)
        {
            cout<<n+1<<endl;
        }
        else if(carry!=0)
        {
            extradays=carry/k;
            cout<<n+extradays+1<<endl;
        }
        
    }
    return 0;        
}
    
