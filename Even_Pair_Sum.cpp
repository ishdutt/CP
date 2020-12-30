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
        ll a,b;
        cin>>a>>b;
        ll evenForX,evenForY, oddForX,oddForY;

        evenForX=a/2;
        evenForY=b/2;

        oddForX=ceil(double(a)/2.0);

        oddForY=ceil(double(b)/2.0);
        
        cout<<(evenForX*evenForY)+(oddForX*oddForY)<<endl;

    }
    
    
    return 0;        
}
    
