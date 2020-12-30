// #include <bits/stdc++.h>
// using namespace std;
// typedef long long      ll;


// int main() 
// {
//     ios::sync_with_stdio(false);
//     ll w,h,n,m;
//     cin>>w>>h>>n>>m;

//     vector<ll>ha(n,0);
//     vector<ll>vb(m,0);

//     for(ll i=0;i<n;i++)
//         cin>>ha[i];

//     for(ll i=0;i<m;i++)
//         cin>>vb[i];
    
//     unordered_map<ll,ll>verdif;
//     unordered_map<ll,ll>hordif;

//     ll ans=0;
//     //LIMIT WILL BE MAX - MIN
//     ll maxnumhorizontal=0;
//     ll minnumberhorizontal=0;
//     for(ll i=0;i<n;i++)
//     {
//         maxnumhorizontal=max(maxnumhorizontal,ha[i]);
//         minnumberhorizontal=min(minnumberhorizontal,ha[i]);
//     }
        
//     ll upperbound=maxnumhorizontal-minnumberhorizontal;
    
//     //ALL POSSIBLE NEW LINES
//     ll k=0;
//     ll newY;

//     unordered_set<ll>vbset(vb.begin(),vb.end());

//     unordered_set<ll>area;

//     //FIXME: K KI VALUE GALAT FIX HO RHI HAI

//     for(newY=0;newY<upperbound+1;newY++)
//     {
//         if(vbset.find(newY)!=vbset.end())
//         {
//             continue;
//         }
//         //cout<<"NEWLY added="<<newY<<"\n";
        
//         vb.push_back(newY);
//         // sort(vb.begin(),vb.end());
//         // sort(ha.begin(),ha.end());

//         unordered_map<ll, ll> m1, m2;

//         for (ll i = 0; i < ha.size(); i++) 
//         {
//             for (ll j = i + 1; j <ha.size() ; j++) 
//             {
//                 ll dist = abs(ha[i] - ha[j]);
//                 m1[dist]++;
//             }
//         }

//         for (ll i = 0; i < vb.size(); i++) 
//         {
//             for (ll j = i + 1; j < vb.size(); j++) 
//             {
//                 ll dist = abs(vb[i] - vb[j]);
//                 m2[dist]++;
//             }
//         }
//         ll tempans=0;
//         for (auto i = m1.begin();i != m1.end(); i++) 
//         {
//             if (m2.find(i->first)!= m2.end()) 
//             {
//                 if(area.find(i->first*i->first)==area.end())
//                     tempans ++;
//             }
//         }
//         //removed the added element
//         // for(ll i=0;i<vb.size();i++)
//         // {
//         //     if(vb[i]==newY)
//         //     {
//         //         vb.erase(vb.begin()+i);
//         //         break;
//         //     }
//         // }


//         vb.pop_back();
//         //cout<<"TEMP ans="<<tempans<<endl;
//         if(ans<tempans)
//         {
//             ans=tempans;
//             k=newY;
//         }
//         //ans=max(ans,tempans);
//     }
//     cout<<"TEST K="<<k<<endl;
//     cout<<ans<<endl;
//     return 0;        
// }
    

#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;


int main() 
{
    ios::sync_with_stdio(false);
    ll w,h,n,m;
    cin>>w>>h>>n>>m;

    vector<ll>ha(n,0);
    vector<ll>vb(m,0);

    for(ll i=0;i<n;i++)
        cin>>ha[i];

    for(ll i=0;i<m;i++)
        cin>>vb[i];
    
    unordered_map<ll,ll>verdif;
    unordered_map<ll,ll>hordif;

    ll ans=0;
    //LIMIT WILL BE MAX - MIN
    ll maxnumhorizontal=0;
    ll minnumberhorizontal=0;
    ll mindif=0;
    for(ll i=0;i<n;i++)
    {
        maxnumhorizontal=max(maxnumhorizontal,ha[i]);
        minnumberhorizontal=min(minnumberhorizontal,ha[i]);
    }
        
    ll upperbound=maxnumhorizontal-minnumberhorizontal;
    
    //ALL POSSIBLE NEW LINES
    ll k=0;
    ll newY;

    unordered_set<ll>vbset(vb.begin(),vb.end());

    unordered_set<ll>area;

    unordered_map<ll, ll> m1, m2;

    //STORING ALL POSSIBLE DIFFERENCES
    for (ll i = 0; i < ha.size(); i++) 
    {
        for (ll j = i + 1; j <ha.size() ; j++) 
        {
            ll dist = abs(ha[i] - ha[j]);
            m1[dist]++;
        }
    }

    for (ll i = 0; i < vb.size(); i++) 
    {
        for (ll j = i + 1; j < vb.size(); j++) 
        {
            ll dist = abs(vb[i] - vb[j]);
            mindif=min(mindif,dist);
            m2[dist]++;
        }
    }
    
    ll zero=0;
    ll maxlower=minnumberhorizontal-upperbound;
    
    ll lowerbound=max(maxlower,zero);
    //GETTING THE COORDINATES OF THE NEWLY ADDED LINE
    for(newY=lowerbound;newY<upperbound+1;newY++)
    {
        if(vbset.find(newY)!=vbset.end())
        {
            continue;
        }
        //cout<<"NEWLY added="<<newY<<"\n";
        
        // vb.push_back(newY);
        for(ll i=0;i<vb.size();i++)
            m2[abs(vb[i]-newY)]++;

        //cout<<"DIFFERNCE ARRAY"<<newY<<"\n";
        // for (auto i = m2.begin();i != m2.end(); i++) 
        // {
        //     cout<<i->first<<" freq="<<i->second<<endl;
        // }

        vb.push_back(newY);

        ll tempans=0;
        for (auto i = m1.begin();i != m1.end(); i++) 
        {
            if (m2.find(i->first)!= m2.end() && m2.find(i->first)->second>0) 
            {
                tempans ++;
            }
        }
        //removed the added element
        for(ll i=0;i<vb.size();i++)
        {
            if(vb[i]==newY)
            {
                vb.erase(vb.begin()+i);
                break;
            }
        }
        //empty the set
        for(ll i=0;i<vb.size();i++)
        {
            m2[abs(vb[i]-newY)]--;
        }

        //vb.pop_back();
        //cout<<"TEMP ans="<<tempans<<endl;
        if(ans<tempans)
        {
            ans=tempans;
            k=newY;
        }
        //ans=max(ans,tempans);
    }
    //cout<<"TEST K="<<k<<endl;
    cout<<ans<<endl;
    return 0;        
}
    
