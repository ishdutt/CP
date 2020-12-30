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
        vector<ll> a;
        //ARRAY
        for(ll i=0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            a.push_back(temp);
        }
        int flag=0;
        for(ll i=0;i<n;i++)
        {
            if((i+1)%a[i]!=0 || a[i]>i+1)
            {
                cout<<"NO\n";
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"YES\n";
        }

    }
    return 0;        
}
    
