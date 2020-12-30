#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

int main() 
{
    ios::sync_with_stdio(false);
    ll r,x1,y1,x2,y2;
    cin>>r>>x1>>y1>>x2>>y2;
    
    ll dis=ceil(double(pow(pow(x1-x2,2) + pow(y1-y2,2),0.5)));
    //cout<<dis<<endl;
    
    double temp=(double)dis/(2*r);
    // double tmep=double(dis%(2*r));

    // cout<<tmep<<endl;
    // if(tmep%2==0)   tmep=0;
    // else    tmep=1;
    // cout<<"TEST="<<dis<<endl;

    // cout<<"TEMP="<<tmeap<<endl;

    // cout<<temp+tmep<<endl;
    if(fmod(temp, 1.0)==0)
    {
        cout<<ll(temp)<<endl;
    }
    else
    {
        cout<<ll(temp)+1<<endl;
    }
    
    
    return 0;        
}
        
