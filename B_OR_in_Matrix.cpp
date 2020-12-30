#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

int main() 
{
    ios::sync_with_stdio(false);
    
    int n,m;
    cin>>m>>n;
    vector<vector<int>>b(m,vector<int>(n,0));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cin>>b[i][j];
    }
    vector<vector<int>>a(m,vector<int>(n,1));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(b[i][j]==0)
            {
                for(int k=0;k<n;k++)
                    a[i][k]=0;

                for(int k=0;k<m;k++)
                    a[k][j]=0;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int r=0;
            for(int k=0;k<m;k++)
            {
                r=r|a[k][j];
            }
            for(int k=0;k<n;k++)
            {
                r=r|a[i][k];
            }
            if(r!=b[i][j])
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }


    return 0;        
}
        
