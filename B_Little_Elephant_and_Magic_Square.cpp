#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

int main() 
{
    ios::sync_with_stdio(false);
    
     vector<vector<int>> a( 3 , vector<int> (3, 0));
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cin>>a[i][j];
    }
    int r1=a[0][0]+a[0][1]+a[0][2];
    int r2=a[1][0]+a[1][1]+a[1][2];
    int r3=a[2][0]+a[2][1]+a[2][2];
    int c1=a[0][0]+a[1][0]+a[2][0];
    int c2=a[0][1]+a[1][1]+a[2][1];
    int c3=a[0][2]+a[1][2]+a[2][2];

    int d1=a[0][0]+a[1][1]+a[2][2];
    int d2=a[0][2]+a[1][1]+a[2][0];
    
    a[0][0]=(r2-r1+r3)/2;
    a[2][2]=(r2-r3+r1)/2;
    a[1][1]=(r3-r2+r1)/2;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

    return 0;        
}
        
