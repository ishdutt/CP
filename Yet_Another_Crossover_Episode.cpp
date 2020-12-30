#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

//IMPORTANT:
//TODO: USED TREE CONCEPT(STORING HEIGHT IN QUEUE FOR BFS) IN GRAPH
int main() 
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--)
    {
        ll d;
        cin>>d;

        vector<ll>a;
        if(d+1<100000)
        {
            cout<<2<<endl;
            cout<<d+1<<" "<<d+2<<endl;
            continue;
        }
        else
        {
            ll howmanymax=0;
            ll maxpossible=pow(10,5)-2;
            howmanymax=d/maxpossible;
            ll leftdif=d%maxpossible;
            //cout<<"KITNI BAAR REPEAT="<<howmanymax<<" "<<leftdif<<endl;
            for(ll i=0;i<howmanymax;i++)
            {
                // if(i%2==0)  a.push_back(1);
                a.push_back(pow(10,5)-1);
                a.push_back(pow(10,5));
                a.push_back(1);
            }
            a.push_back(leftdif+1);
            a.push_back(leftdif+2);
        }
        
        cout<<a.size()<<endl;
        for(ll i=0;i<a.size();i++)
            cout<<a[i]<<" ";
        cout<<endl;

    }
    return 0;        
}
        
