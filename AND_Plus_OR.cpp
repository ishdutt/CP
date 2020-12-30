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
        
        if(n==0)
        {
            cout<<"-1\n";
            continue;
        }
        if(n%2==0)
        {
            
            ll i=(n/2)-1;
            cout<<i<<" "<<i+2<<endl; 
        }
        else
        {
            if(n==1)
            {
                cout<<0<<" "<<1<<endl;
                continue;
            }
            ll i=(n/2)-1;
            cout<<i<<" "<<i+1<<endl;
        }
        

    }
    return 0;        
}
    
