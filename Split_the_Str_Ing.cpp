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
        string s;
        cin>>s;

        char last=s[n-1];
        ll freq=count(s.begin(), s.end(), last);

        if(freq>1)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
        
    }
    return 0;        
}
    
