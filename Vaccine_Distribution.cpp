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
        ll n,d;
        cin>>n>>d;
        vector<ll>a(n,0);

        for(int i=0;i<n;i++)
            cin>>a[i];
        
        vector<ll>safe;
        vector<ll>risk;
        for(int i=0;i<n;i++)
        {
            if(a[i]>=80 || a[i]<=9)
                risk.push_back(a[i]);
            
            else
            {
                safe.push_back(a[i]);
            }
        }
        cout<<ceil(double(safe.size())/double(d)) + ceil(double(risk.size())/double(d))<<endl;

    }
    
    
    return 0;        
}
    
