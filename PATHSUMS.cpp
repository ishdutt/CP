#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

//IMPORTANT:
//TODO: USED TREE CONCEPT(STORING HEIGHT IN QUEUE FOR BFS) IN GRAPH
//======================================BFS USE KIYA HAI YAHA======================================
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
        vector<vector<int>>adj(n,vector<int>(n,0));
        // index-1 will be the source and vector will have 
        //vector<int>graph(n+1,0);
        for(ll i=0;i<n-1;i++)
        {
            ll a,b;
            cin>>a>>b;
            adj[a-1][b-1]=1;
            adj[b-1][a-1]=1;
        }


        //SOURCE AND HEIGHT
        queue<pair<ll,ll>>q;


        vector<ll>values(n,-1);
        values[0]=2;

        ll height=0;
        ll source=0;
        q.push(make_pair(source,height));

        //cout<<"TEST\n";
        int flag=0;
        ll i=0;
            while(!q.empty())
            {
                //cout<<"MOSHI "<<q.size()<<" front="<<q.front().first<<endl;
                flag=0;
                //CHECK IF ALL VISITED
                for(ll i=0;i<values.size();i++)
                {
                    if(values[i]==-1)
                    {
                        // cout<<"YO\n";
                        flag=1;
                        break;
                    }   
                }
                if(flag==0)     break;
                
                if(q.front().second%2==0)
                {
                    values[q.front().first]=2;
                }
                else
                {
                    values[q.front().first]=3;
                }

                for(ll i=0;i<n;i++)
                {
                    //SELECT THE NODES ADJACENT TO SOURCE SUCH THAT THEY DON'T HAVE VALUE ASSIGNED TILL NOW..
                    //NEXT ELEMENT CHOSEN WILL BE I
                    
                    if(adj[q.front().first][i]==1&&values[i]==-1)
                    {
                        //cout<<"NExt source "<<i<<" ";
                        q.push(make_pair(i,q.front().second+1));
                    }
                        
                }
                //cout<<endl;
                //remove the element from queue
                q.pop();
            }



        for(int i=0;i<values.size();i++)
            cout<<values[i]<<" ";
        cout<<endl;

    }
    return 0;        
}
        
