#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

void transform(vector<ll>&arr)
{
    map<ll, ll> map;

    for (ll i = 0; i < arr.size(); i++)
    map[arr[i]] = i;

    ll rank = 1;

    for (auto i: map)
    arr[i.second] = rank++; // i.second stores the index of element i
}


int main() 
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--)
    {
        ll n,m;
        cin>>n>>m;

        //RATING HAI YE
        vector<ll> a;
        //ARRAY
        for(ll i=0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            a.push_back(temp);
        }
        cout<<"TEST\n";
       vector<vector<ll>>ratchng(n,vector<ll>(m));

       for(ll i=0;i<n;i++)
       {
           vector<ll> tempvec;
           for(ll i=0;i<m;i++)
           {
               ll temp;
               cin>>temp;
                tempvec.push_back(temp);
           }
           ratchng.push_back(tempvec);
       }

        cout<<"TEST\n";

        //RATING CALCULATION
        vector<vector<ll>>rating;
        for(int i=0;i<n;i++)
        {
            //FOR EACH PLAYER I 
            vector<ll>playerrating;
            ll currentrating=a[i];
            for(int j=0;j<m;j++)
            {
                playerrating.push_back(currentrating-ratchng[i][j]);
                currentrating=currentrating-ratchng[i][j];
            }
            rating.push_back(playerrating);
        }

        cout<<"TEST1\n";

        //HIGHEST RATING MONTH
        vector<ll>highestrating;
        for(int i=0;i<n;i++)
        {
            //FOR EACH PLAYER I 
            int maxrating=a[i];
            int month=0;
            for(int j=0;j<m;j++)
            {
                if(maxrating<rating[i][j])
                {
                    maxrating=rating[i][j];
                    month=j;
                }
            }
        }

        cout<<"TEST3\n";

        //TOP RANKING
        vector<vector<ll>>ratingEachPlayer;
        vector<ll>highestranking;
       
        for(int j=0;j<m;j++)
        {
            //FOR EACH MONTH.. for
            vector<ll>temp;
            for(int i=0;i<n;i++)
            {
                temp.push_back(rating[i][j]);
                
            }
            transform(temp);
            ratingEachPlayer.push_back(temp);
        }

        cout<<"TEST4\n";

        for(int j=0;j<m;j++)
        {
            //FOR EACH MONTH.. for Each player rating
            ll maxrate = INT_MAX;
            ll maxmon;
            for(int i=0;i<n;i++)
            {
                if(maxrate>ratingEachPlayer[j][i])
                {
                    maxrate=ratingEachPlayer[j][i];
                    maxmon=j;
                }
                
            }
            highestranking.push_back(maxmon);
        }


        ll count=0;
        for(int i=0;i<n;i++)
        {
            if(highestrating[i]==highestranking[i])
                count++;
        }
        cout<<count<<endl;

    }

    
    
    
	return 0;
}

/*4
7
1 1 0 0 0 1 1
8
1 0 1 1 1 0 0 1
4
1 1 0 1
4
1 1 1 1*/