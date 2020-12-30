#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

int main() 
{
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    vector<pair<int,int>>kit;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        kit.push_back(make_pair(x,y));
    }
    unordered_map<int,int>home;
    unordered_map<int,int>away;

    for(int i=0;i<n;i++)
        home[kit[i].first]++;

    for(int i=0;i<n;i++)
        away[kit[i].second]++;

    vector<pair<int,int>>ans;
    
    for(int i=0;i<n;i++)
    {
        int hkit=0;
        //1 nai count karenge
        hkit=(n-1)+ home[kit[i].second];
        //cout<<"TEST"<<hkit<<" "<<kit[i].second<<endl;
        int akit=(2*(n-1))-hkit;
        ans.push_back(make_pair(hkit,akit));
    }

    for(int i=0;i<n;i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    

    return 0;        
}
        
