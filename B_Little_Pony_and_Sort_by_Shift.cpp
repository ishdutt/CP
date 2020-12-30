#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

int main() 
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int>a(n,0);
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<int>target(a.begin(),a.end());

    sort(target.begin(),target.end());

    int f1=0;
    //compare
    for(int i=0;i<n;i++)
    {
        if(a[i]!=target[i])
        {
            f1=1;
            break;    
        }   
    }
    if(f1==0)
    {
        cout<<0<<endl;
        return 0;
    }
 
    
    int minelement= *min_element(a.begin(),a.end());
    int minelindex=0;
    for(int i=0;i<n;i++)
        if(a[i]=minelement)
            minelindex=i;

    minelindex=n-minelindex;
    //cout<<"TEST="<<minelindex<<endl;
    if(minelindex==0)
    {
        cout<<-1<<endl;
        return 0;
    }

    int flag=1;
    for(int i=0;i<minelindex;i++)
    {
        // auto it=a.begin()+n;
        // int temp=*it;
        // cout<<*(it)<<endl;
        a.erase(a.end()-1);
        
        //a.insert(a.begin(),temp);
    }
    cout<<"array"<<endl;
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<endl;

    for(int i=0;i<n;i++)
    {
        if(a[i]!=target[i])
        {
            cout<<-1<<endl;
            return 0;
        }   
    }
    cout<<minelindex<<endl;
}
        
