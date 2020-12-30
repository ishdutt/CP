#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;


int main() 
{
    ll a=100,b=90,c=70,d=80,e=19;
    ll z=1048576;
    ll x=a^z;
    ll x2=b^z;
    ll x3=c^z;
    ll x4=d^z;
    ll x5=e^z;
    cout<<"Z = "<<x+x2+x3+x4+x5<<endl;
    //cout<<x<<endl;
    for(ll i=1;i<20;i++)
    {
        ll xo=pow(2,i);
        ll v1=a^xo;
        ll v2=b^xo;
        ll v3=c^xo;
        ll v4=d^xo;
        ll v5=e^xo;
        cout<<"TEST POWER= "<<xo<<" = "<<v1+v2+v3+v4+v5<<endl;
    }  
}
    
    