#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n=1000;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(j*(j+1)==(i*(i+1)/2))
            {
                cout<<i<<" "<<j<<endl;
            }
        }
    }
}