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

        sort(a.begin(),a.end(),greater<int>());
        if(n==1)    cout<<a[0]<<endl;   
	    
	    else
        {
            int burner1=a[0];
            int burner2=a[1];
            for(ll j=2;j<a.size();j++)
            {
                if(burner1<=burner2)
                    burner1=burner1+a[j];
                else
                    burner2=burner2+a[j];
            }
            
            if(burner1<=burner2)    cout<<burner2<<endl;
            
            else    cout<<burner1<<endl;
	    }        
    }
    return 0;        
}
    
