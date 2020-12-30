#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

ll prim(vector<vector<ll>>& A) 
{
    
    ll n = A.size();
    vector<ll> dist(n+1, 0);
    vector<ll> parent(n);
    ll v = 0;
    ll total_cost = 0;
    while (true) 
    {
        cout<<"TEST\n";
        //cout<<"SOURCE "<<v<<endl;
        //make the source separate from every other node
        dist[v] = -dist[v];
        for (ll i = 0; i < n; ++i) 
        {
            
            if(v==i)
                continue;
            
            int ans=A[v][i] < dist[i];
            //cout<<"DIST="<<dist[i]<<" MATRIX="<<A[v][i]<<" "<<"COndition="<<ans<<endl;
            if (dist[i] <= 0 && A[v][i] < dist[i]) 
            {
                //cout<<"CHALA\n";
                dist[i] = A[v][i];
                parent[i] = v;
            }
        }
        //FIXME: DISTANCE MATRIX GALAT HAI 
        //cout<<"DISTANCE MATRIX\n";
        // for (ll i = 0; i < n; ++i) 
        //     cout<<dist[i]<<" ";
        // cout<<endl;

        //mi stores the minimum value from the distance matrix
        ll mi = n;
        dist[mi]=INT_MIN;
        for (ll i = 0; i < n; ++i) 
        {
            //cout<<i<<" "<<"MIN index"<<mi<<" "<<dist[i]<<" dmin "<<dist[mi]<<endl;
            if ((mi == n || dist[i] < dist[mi]) && dist[i] < 0) mi = i;
        }

        if (mi == n) break;
        total_cost += A[mi][parent[mi]];
        //cout<<"MINIMUM index="<<mi<<endl;
        v = mi;
    }
    // cout<<"PARENT=\n";
    // for(int i=0;i<n;i++)
    //     cout<<parent[i]<<" ";
    // cout<<endl;

    //cout<<"COST="<<total_cost+dist[0]<<endl;
    return abs(total_cost+dist[0]);
}




// ll prim(vector<vector<ll>>& A) 
// {
    
//     ll n = A.size();
//     vector<ll> dist(n, INT_MAX);
//     vector<ll> parent(n);
//     ll v = 0;
//     ll total_cost = 0;
//     while (true) 
//     {
//         dist[v] = -dist[v];
//         for (int i = 0; i < n; ++i) 
//         {
//             if (dist[i] > 0 && A[v][i] < dist[i]) 
//             {
//                 dist[i] = A[v][i];
//                 parent[i] = v;
//             }
//         }

//         int mi = -1;
//         for (int i = 0; i < n; ++i) 
//         {
//             cout<<i<<" MI="<<mi<<endl;
//             if ((mi == -1 || dist[i] < dist[mi]) && dist[i] > 0) mi = i;
//         }

//         if (mi == -1) break;
//         total_cost += A[mi][parent[mi]];
//         v = mi;
//     }

//     cout<<"PARENT=\n";
//     for(int i=0;i<n;i++)
//         cout<<parent[i]<<" ";
//     cout<<endl;

//     cout<<"MAX COST="<<total_cost<<endl;
//     return total_cost;
// }




int main() 
{
    ios::sync_with_stdio(false);
    ll n,d;
    cin>>n>>d;
    vector<vector<ll>> points;
    for(ll i=0;i<n;i++)
    {
        vector<ll>temp;
        for(ll j=0;j<d;j++)
        {
            ll input;
            cin>>input;
            temp.push_back(input);
        }
        points.push_back(temp);
    }

    // for(ll i=0;i<n;i++)
    // {
    //     for(ll j=0;j<n;j++)
    //     {
    //         cout<<points[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
        
    
    
    vector<vector<ll>>adj(n,vector<ll>(n,INT_MAX));
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {   
            if(i==j)
            {
                adj[i][j]=0;
                continue;
            }
            if(adj[j][i]!=0)
            {
                adj[i][j]=adj[j][i];
            }
            //compute
            ll weight=0;
            for(ll k=0;k<d;k++)
                weight+=abs(points[i][k]-points[j][k]);
            

            adj[i][j]=weight*(-1);
        }
    }
    //kruskalMST(adj);

    // cout<<"YE ADJ Matrix=\n";
    // for(ll i=0;i<n;i++)
    // {
    //     for(ll j=0;j<n;j++)
    //     {
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    
    // cout<<"+++++\n";
    cout<<prim(adj)<<endl;

    return 0;        
}
    
