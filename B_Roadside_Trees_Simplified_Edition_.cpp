#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

int main() 
{
    ios::sync_with_stdio(false);
    long long int n;
   
    cin>>n;
    vector<long long int>a(n,0);
    for(long long int i=0;i<n;i++)
        cin>>a[i];
    long long int ans=0;

    ans=a[0];
    for(long long int i=1;i<n;i++)
    {
        ans+=abs(a[i-1]-a[i]);
    }
    cout<<ans+2*n-1<<endl;
    return 0;        
}
        
