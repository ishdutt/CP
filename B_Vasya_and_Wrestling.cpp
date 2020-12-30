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
    
    long long int sum=0;
    for(long long int i=0;i<n;i++)
        sum+=a[i];
    
    if(sum>0)
    {
        cout<<"first"<<endl;
        return 0;
    }   
    else if(sum<0)
    {
        cout<<"second"<<endl;
        return 0;
    }
    else
    {
        string p1="";
        string p2="";
        for(long long int i=0;i<n;i++)
        {
            if(a[i]>0)
                p1+=char(a[i]);
            else
            {
                p2+=char(-a[i]);
            }
            
        }
        if(p1>p2)
        {
            cout<<"first"<<endl;
            return 0;
        }  
        else if(p1<p2)
        {
            cout<<"second"<<endl;
            return 0;
        }
        else 
        {
            if(a[n-1]>0)
            {
                cout<<"first"<<endl;
                return 0;
            }
            else
            {
                cout<<"second"<<endl;
            return 0;   
            }
            
        }
    }
    

    return 0;        
}
        
