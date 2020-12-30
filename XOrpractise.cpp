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
        vector<ll>NoOfOnes(3,0);
        ll firstanswer=14;
        ll secondans=18;
        ll firstquestion=2;
        ll secondquestion=5;
        // for(int i=0;i<4;i++)
        //     cout<<((firstanswer >> i) & 1);
        cout<<"\n";
        if((firstanswer >> 0) & 1)
        {
            //even number of 1's --> 0,2,4;

            
        }
        // NOW WE DON'T KNOW THE NUMBER>> SO WE WILL 
        if((secondans >> 1) & 1)
        {
            // if this is 1.. then we have non zero 1s in 0th place
            
        }
    }
    return 0;        
}
    
    