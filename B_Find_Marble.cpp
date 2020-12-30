#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

int main() 
{
    ios::sync_with_stdio(false);
    
    int n,s,t;
    cin>>n>>s>>t;
    vector<int>p(n,0);
    for(int i=0;i<n;i++)
        cin>>p[i];

    vector<int>visited(n,0);
    s--;
    t--;
    int pos=s;
    int steps=0;

    while (1)
    {
        //cout<<"TEST="<<pos<<" "<<steps<<endl;
        if(pos==t)  
        {
            cout<<steps<<endl;
            return 0;
        }
        else if(visited[pos]==1)
        {
            cout<<-1<<endl;
            return 0;
        }
        else
        {
            visited[pos]=1;
            pos=p[pos]-1;
            steps++;
        }
        
    }
    

    return 0;        
}
        
