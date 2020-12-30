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
        
        vector<ll>a(n-1,0);

        for(ll i=0;i<n-1;i++)
            cin>>a[i];
        
        //WORST CASE ME EK CHILD KE N-1 NODES..
        //parent... aur then uske child ke list hai..
        vector<vector<ll>> tree(n,vector<ll>(n-1,0));

        for(int i=0;i<n-1;i++)
        {
            //a[i] is parent and i+1 is child
            tree[a[i]][i+1]=1;
        }

        vector<ll>val(n,0);

        val[0]=n-1;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n-1;j++)
            {
                if(tree[i][j]!=0)
                {
                    val[j]=n-1-j;
                }
            }
        }


    }
    return 0;        
}
    
