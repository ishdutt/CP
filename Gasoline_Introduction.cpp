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
        ll n;
        cin>>n;
        vector<ll> a;
        //ARRAY
        for(int i=0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            a.push_back(temp);
        }

        ll totaldis=a[0];
        ll fuel=a[0];
        ll i=0;
        a[0]=0;
        while(fuel)
        {
            i++;
            fuel--;
            fuel+=a[i%n];
            totaldis+=a[i%n];
            //cout<<"TEST="<<totaldis<<endl;
            a[i%n]=0;
        }

        cout<<totaldis<<endl;
    }
    return 0;        
}
    
