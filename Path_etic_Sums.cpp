#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

// // ll n;
// vector<ll>a;
// vector<vector<ll>>b;

void solve(ll p,ll num,ll n,vector<ll>&a,vector<vector<ll>>&b)
{
    //cout<<"MOSHI\n";
    ll pum=0;
    if(num==3)  pum=2;

    else if(num==2) pum=3;

    for(ll i=0;i<n;i++)
    {
        if(b[p][i]==1)
        {
            if(a[i]==-1)
            {
                a[i]=num;
                solve(i,pum,n,a,b);
            }
        }
    } 
    return ;
}


int main() 
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;

        vector<ll>a(n,-1);
        vector<vector<ll>>b(n,vector<ll>(n,-1));

        // for(ll i=0;i<n;i++)
        //     a.push_back(-1);

        // for(ll i=0;i<n;i++)
        // {
        //     vector<ll>temp;
        //     for(ll j=0;j<n;j++)
        //     {
        //         temp.push_back(-1);
        //     }
        //     b.push_back(temp);
        // }
            

        for(ll i=0;i<n-1;i++)
        {
            ll u,v;
            cin>>u>>v;
            b[u-1][v-1]=1;
            b[v-1][u-1]=1;
        }
        a[0]=2;
        ll p=0;
        ll num=3;

        solve(p,num,n,a,b);

        for(ll i=0;i<a.size();i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;        
}
        
