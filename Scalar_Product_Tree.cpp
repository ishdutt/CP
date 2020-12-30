#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

ll mod=pow(2,32);

//IMPORTANT:
//TODO: USED TREE CONCEPT(STORING HEIGHT IN QUEUE FOR BFS) IN GRAPH
//======================================BFS USE KIYA HAI YAHA======================================

void dfs(vector<vector<ll>>&tree,vector<ll>&visited, vector<vector<ll>>&fu, vector<ll>&weight ,ll currentnode, ll parent)
{
    //cout<<"Current Position: "<<currentnode+1<<" "<<parent+1<<endl;
    visited[currentnode]=1;
    
    if(parent!=-1)
    {
        fu[currentnode]=fu[parent];
        fu[currentnode].push_back(weight[currentnode]);
    }
    

    // For every node of the graph 
    for (ll i = 0; i < visited.size(); i++) { 
  
        // If some node is adjacent to the current node 
        // and it has not already been visited 
        if (tree[currentnode][i] == 1 && (visited[i]==-1)) { 
           dfs(tree,visited,fu,weight,i,currentnode);
        } 
    } 
}

int main() 
{
    ios::sync_with_stdio(false);
    
    ll n,q;

    cin>>n>>q;

    vector<ll>weight(n,0);
    vector<vector<ll>>tree(n,vector<ll>(n,0));

    
    for(int i=0;i<n;i++)
        cin>>weight[i];
    
    for(ll i=0;i<n-1;i++)
    {
        ll a,b;
        cin>>a>>b;
        tree[a-1][b-1]=1;
        tree[b-1][a-1]=1;
    }

    //PREPROCESS ALL THE VALUES...
    vector<vector<ll>>fu(n,vector<ll>(n));
    vector<ll>visited(n,-1);

    fu[0].push_back(weight[0]);

    dfs(tree,visited,fu, weight,0,-1);

    // cout<<"TEST= "<<endl;
    
    // for (ll i = 0; i < fu.size(); i++)
    // {
    //     for(ll j=0;j<fu[i].size();j++)
    //         cout<<fu[i][j]<<" ";
    //     cout<<endl;
    // }

    //QUERIES
    while (q--)
    {
        ll u,v;
        cin>>u>>v;

        ll ans=0;
        // for(ll i=0;i<fu[u-1].size();i++)
        //     ans=(ans + ((fu[u-1][i]%mod)*(fu[v-1][i]%mod))%mod)%mod;
        
        cout<<ans<<endl;
    }
    

    return 0;        
}
        
