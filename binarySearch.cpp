#include<bits/stdc++.h>

using namespace std;
typedef long long  ll;


int main()
{
    // int n=1001;
    int ans = -1; 
    ll low=1;
    ll dif= 14;
    ll high=14;
    ll n=20;
    ll m=14;

    while (low <= high) 
    { 
        
        int mid = low + (high - low + 1) / 2;  

        if (mid+dif >n) high = mid - 1; 

        else if (mid+dif <= m)     low = mid + 1; 
        
        else if (mid+dif >m && mid+dif<=n) 
        { 
            ans = mid; 
            high = mid - 1; 
        } 
    } 
  
    cout<<ans<<endl; 
}