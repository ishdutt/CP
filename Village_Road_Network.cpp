#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;
typedef pair<int, int> pairs; 

ll sourcex, sourcey;


ll bfs(ll x1,ll y1,ll x2,ll y2,vector<pair<ll,ll>>visited)
{
    //cout<<"YO\n";
    if(x1==x2&&y1==y2)  return 0;

    queue<pair<ll,ll>> q; 
    visited.push_back(make_pair(x1,y1));
    q.push(make_pair(x1,y1)); 
      // 'i' will be used to get all adjacent 
    // vertices of a vertex 
    ll ans=1;
    ll counter=0;
    ll powerfour=4;
    int flag=0;
    //cout<<q.front().first<<" "<<q.front().second<<endl;
    for(ll counter=0;;counter++)
    {
        for(ll i=0;i<visited.size();i++)
        {
            if(visited[i].first==q.front().first && visited[i].second==q.front().second&&counter>0)
            {         
                counter++ ;
                q.pop();
                flag=1;
            }
        }

        if(q.front().first>10 && q.front().second>10)   
        {
            counter++;
            q.pop();
        }

        //mark visited
        visited.push_back(make_pair(q.front().first,q.front().second));

        //counter++;
        // cout<<q.front().first<<" "<<q.front().second<<" ans="<<ans<<endl;
        // cout<<"TEST dir1="<<2*q.front().second+q.front().first<<" "<<q.front().second<<endl;
        // cout<<"TEST dir2="<<q.front().first<<" "<<q.front().second+2*q.front().first<<endl;
        // cout<<"TEST dir3="<<q.front().first-2*q.front().second<<" "<<q.front().second<<endl;
        // cout<<"TEST dir4="<<q.front().first<<" "<<q.front().second-2*q.front().first<<endl;

        // cout<<
        // if(counter==powerfour+1)
        // {
        //     ans++;
        //     powerfour*=4;
        // }
        if(q.front().first==x2&&q.front().second==y2)
        {
            return counter;
        }
        

        //2y+x,y
        q.push(make_pair(2*q.front().second+q.front().first,q.front().second));

        //x,y+2x, ya neg
        if((q.front().second+2*q.front().first)>0)
            q.push(make_pair(q.front().first,q.front().second+2*q.front().first));
        else
        {
            q.push(make_pair(-(q.front().first),-(q.front().second+2*q.front().first)));
        }
        
        //x-2y,y
        q.push(make_pair(q.front().first-2*q.front().second,q.front().second));
        
        //x,y-2x, ya neg
        if((q.front().second-2*q.front().first)>0)
            q.push(make_pair(q.front().first,q.front().second-2*q.front().first));
        else
        {
            q.push(make_pair(-(q.front().first),-(q.front().second-2*q.front().first)));
        }

        q.pop();
        
    }

}

int main() 
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--)
    {
        ll x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        //VISITED ARRAY TOO
        sourcex=x1;
        sourcey=y1;
        vector<pair<ll,ll>> visited;

        if(x1==x2&&y1==y2)
        {
            cout<<"0\n";
            continue;
        }

        //cout<<"YO\n";
        // visited.insert(make_pair(x1,y1));
        ll ans=bfs(x1,y1,x2,y2,visited);
        //cout<<ans<<endl;
        if(ans<5&&ans>0)
        {
            // cout<<
            cout<<1<<endl;
            continue;
        }        

        //cout<<ans<<endl;
        float finlans=log2(float(ans)*3/4);
        cout<<float(finlans)/2.0<<endl;
        cout<<ceil(float(finlans)/2.0)<<endl;
    }
    return 0;        
}
    
