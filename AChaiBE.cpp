#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while (t--)
    {
        ll n,k;
        cin>>n;
        cin>>k;

        string s;
        cin>>s;

        vector<pair<char,bool>>arr;
        for(ll i=0;i<n;i++)
            arr.push_back(make_pair(s[i],true));

        vector<ll> iron;
        vector<ll> metal;

        ll count=0;

        unordered_map<int,int> map;
        ll noOfSheets=0;
        
        for(ll i=0;i<n;i++)
        {
            if(arr[i].first=='M')
            {
                map[i]=noOfSheets;
                metal.push_back(i);
            }
            else if(arr[i].first=='I')
            {
                map[i]=noOfSheets;
                iron.push_back(i);
            }
            else if(arr[i].first==':')
            {
                noOfSheets++;
                map[i]=noOfSheets;
            }
            else if(arr[i].first=='X')
            {
                map[i]=0;

                for(ll x=0;x<metal.size();x++)
                {
                    //cout<<"Y\n";
                    if(!arr[metal[x]].second)    continue;

                    for(ll y=0;y<iron.size();y++)
                    {
                        if(!arr[metal[x]].second)    break;

                        if(!arr[iron[y]].second)     continue;

                        ll power= k+1 - abs(metal[x] - iron[y]) - abs(map[metal[x]] - map[iron[y]]);
                        //cout<<"MOSHI\n"<<power<<endl;
                        if(power>0)
                        {
                            arr[metal[x]].second= false;
                            arr[iron[y]].second = false;
                            count++;
                            break;
                        }

                    }
                }
                noOfSheets=0;
                metal.clear();
                iron.clear();
            }
        }
        
        for(ll x=0;x<metal.size();x++)
        {
            if(!arr[metal[x]].second)    continue;

            for(ll y=0;y<iron.size();y++)
            {
                if(!arr[metal[x]].second)    break;

                if(!arr[iron[y]].second)     continue;

                ll power= k+1 - abs(metal[x] - iron[y]) - abs(map[metal[x]] - map[iron[y]]);

                if(power>0)
                {
                    arr[metal[x]].second= false;
                    arr[iron[y]].second = false;
                    count++;
                }

            }
        }
        cout<<count<<endl;

    }
    return 0;        
}
    
