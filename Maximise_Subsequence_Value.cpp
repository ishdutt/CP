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
        for(int i=0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            a.push_back(temp);
        }
        ll low=0;
        ll high=n-1;
        vector<ll> ans;
        ll sum=0;
        for(ll i=0;i<n;i++)
        {
            if(a[i]>0)
                sum+=a[i];
        }
        cout<<sum<<endl;
        while (low<=high)
        {
            if(a[low]<0 && a[high]>0)
            {
                ans.push_back(low);
                ans.push_back(high);
                low++;
                high--;
            }
            else if(a[low]>=0)   low++;
            else if(a[high]<=0)     high--;
        }

        sort(ans.begin(),ans.end());
        cout<<ans.size()<<" ";
        for(ll i=0;i<ans.size();i++)
            cout<<ans[i]+1<<" ";
        
        
        cout<<endl;
        
    }
    return 0;        
}
    
