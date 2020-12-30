#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

int main() 
{
    ios::sync_with_stdio(false);
    
    int n,m;
    cin>>n>>m;
    if(m==0)    
    {
        cout<<"YES"<<endl;
        return 0;
    }
    vector<int>a(m,0);
    for(int i=0;i<m;i++)    cin>>a[i];

    sort(a.begin(),a.end());

    if(a[0]==1 || a[a.size()-1]==n)
    {
        cout<<"NO"<<endl; 
        return 0;
    } 

    // for(int i=0;i<m;i++)
    // //     cout<<a[i]<<" ";
    // // cout<<endl;

    int skip=1;
    for(int i=0;i<m;i++)
    {
        //cout<<"TEST="<<a[i]<<" "<<skip<<endl;
        
        if(skip>=3) 
        {
            cout<<"NO"<<endl;
            return 0;
        }
        
        if(a[i+1]==a[i]+1)    skip++;

        else
        {
            skip=1;
        }
    }
    cout<<"YES"<<endl;
    
    return 0;        
}
        
