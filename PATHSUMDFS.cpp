#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

//IMPORTANT:
//TODO: USED TREE CONCEPT(STORING HEIGHT IN QUEUE FOR BFS) IN GRAPH
//======================================DFS USE KIYA HAI YAHA======================================

void dfs(vector<ll>&visited,vector<ll>&val,vector<vector<ll>>adj,ll currentnode,ll currentval)
{ 
    // Set current node as visited 
    visited[currentnode] = 1; 

    val[currentnode]=currentval;
  
    // For every node of the graph 
    for (ll i = 0; i < visited.size(); i++) { 
  
        // If some node is adjacent to the current node 
        // and it has not already been visited 
        if (adj[currentnode][i] == 1 && (visited[i]==-1)) { 

            if(currentval==2)  dfs(visited,val,adj,i,3);
            
            else
            {
                dfs(visited,val,adj,i,2);
            }
            
        } 
    } 
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

        //pair (S,D)
        vector<vector<ll>>adj(n,vector<ll>(n,0));
        // index-1 will be the source and vector will have 
        //vector<int>graph(n+1,0);
        for(ll i=0;i<n-1;i++)
        {
            ll a,b;
            cin>>a>>b;
            adj[a-1][b-1]=1;
            adj[b-1][a-1]=1;
        }

        vector<ll>visited(n,-1);

        //VAL IS 2 FOR STARTING NODE ;)
        vector<ll>val(n,2);
        
        dfs(visited,val,adj,0,2);

        for(int i=0;i<val.size();i++)
            cout<<val[i]<<" ";
        cout<<endl;
    }
    return 0;        
}
        
