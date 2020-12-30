#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

        int d1,d2,v1,v2,p;
        cin>>d1>>v1>>d2>>v2>>p;
        int flag=0,flag2=0;

        for(int days=1;days<1000;days++)
        {
            
            if(days==d1)    flag=1;
            if(days==d2)    flag2=1;

            if(flag==1)
            {
                p-=v1;
            }
            if(flag2==1)
            {
                p-=v2;
            }
            if(p<=0)
            {
                cout<<days<<endl;
                break;
            }
            //cout<<days<<" "<<p<<endl;
        }
    
    return 0;        
}
    
