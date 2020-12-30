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

        ll n,m,x,y;
        cin>>n>>m>>x>>y;

        vector<vector<ll>>a(n,vector<ll>(m,0));

        if(n*m==1)  cout<<x<<endl;

        else if(y-x>=x)   cout<<n*m*x<<endl;

        else if(x>=y)
        {
            //cout<<"MOSHi\n";
            ll num1=ceil(y/2);
            ll num2=y-num1;

            // cout<<"TESt="<<(n*m/2*(num1))<<endl;
            // cout<<"TEST2="<<(n*m/2*(num2))<<endl;
            if(n*m%2==0)    cout<<(n*m/2*(num1))+(n*m/2*(num2))<<endl;

            else if(num1>=num2)
            {
                cout<<(((n*m/2)+1)*(num1))+(n*m/2*(num2))<<endl;           
            }
            else
            {
                cout<<(((n*m/2)+1)*(num2))+(n*m/2*(num1))<<endl;    
            }
            
            //cout<<(n*m/2*(num1))+(n*m/2*(num2))<<endl;
        }

        else
        {
            if(n*m%2==0)
            {
                cout<<((n*m/2)*x)+((n*m/2)*(y-x))<<endl;
            }
            else
            {
                //cout<<(n*m/2*(x+1))+(n*m/2*(y-x))<<endl;
                ll xcount= (ceil(m/2)*ceil(n/2)+ m/2*n/2)*x;

                //ll othercount=m/2*(n/2+ceil(n/2))*(y-x);
                ll othercount= (m/2*ceil(n/2)+ceil(m/2)*n/2)*x;
                cout<<xcount+othercount<<endl;
            }
            
        }
        
    }
    return 0;        
}
    
