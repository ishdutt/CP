#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

int main() 
{
    ios::sync_with_stdio(false);
    ll n;

    ll f1,f2;
    cin>>f1>>f2;

    cin>>n;
    vector<ll>a(n,0);
    a[0]=f1;
    a[1]=f2;

    if(n==2)
    {
        //cout<<"TEST\n";
        cout<<(a[1]+1000000007)%1000000007<<endl;
        return 0;
    }
    else if(n==1)
    {
        cout<<(a[0]+1000000007)%1000000007<<endl;
        return 0;
    }
    for(ll i=2;i<n;i++)
    {
        cout<<"moshi "<<i<<endl;
        a[i]=(a[i-1]-a[i-2] + 1000000007)%1000000007;
    }
    cout<<a[n-1]<<endl;

    return 0;        
}
        
