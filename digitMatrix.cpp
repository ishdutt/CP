#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

void solve(vector<int>&a,int iterator,int n)
{
    cout<<iterator<<" "<<n<<endl;
    //BASE CONDITION
    if(n<0 || iterator>6) return;
    
    if(iterator==5 && (n<10&&n>=0))
    {
        a[iterator]=n;
        cout<<"TEST"<<endl;
        cout<<a[0]<<a[1]<<a[2]<<a[3]<<endl;
        cout<<a[2]<<a[3]<<a[4]<<a[5]<<endl;
        return ;
    }


    if(iterator==3 && (n<10&&n>=0))
    {
        a[iterator]=n;
        //cout<<a[0]<<a[1]<<a[2]<<a[3]<<endl;

        //hardcodede daala hai abhi..baad me modify karna
        solve(a,iterator+1,36-a[2]-a[3]);
    }

    for(int i=0;i<=9;i++)
    {
        a[iterator]=i;
        solve(a,iterator+1,n-i);
        a[iterator]=0;
    }
}


int main() 
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;

    // vector<int>b(n,0);
    // for(int i=0;i<n;i++)
    //     cin>>b[i];

    
    vector<int>a(6,0);
    solve(a,0,n);
    
}
        
