#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;




int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,q,s;
    cin>>n>>q>>s;

    vector<ll> a;
    //ARRAY
    for(int i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        a.push_back(temp);
    }
    
    ll last=0;

    ll maxhtillnow;

    ll maxlen=0;
    ll r;
        //cout<<"TEST="<<L<<" "<<R<<endl;

    //l HERE IS I
    //SELECTING l AND r FOR GETTING THE DESIRED OUTPUT...
    //NOW WE NEED TO TAKE THE UNION... I.E FOR L AND R VALUES 
    // ll ans[n][n]={0};
    vector<vector<ll>>ans(n,vector<ll>(n,0));
    for(ll i=0;i<n;i++)
    {
        maxhtillnow=a[i];
        ll templen=1;
        for(ll j=i+1;j<n;j++)
        {
            //cout<<"TEST2= "<<i<<" "<<j<<" maxelement="<<maxhtillnow<<" "<<a[j]<<endl;
            if(a[j]>maxhtillnow)   
            {
                templen++;
                maxhtillnow=a[j];
                r=j;
            }
            ans[i][j]=templen;
        }
        //cout<<"TEST="<<i<<" "<<r<<" "<<templen<<endl;
        //cout<<"===================";
        maxlen=max(templen,maxlen);
        //ans.push_back(make_pair(make_pair(i,r),maxlen));
        //ans[i][r]=maxlen;
    }

    // for(ll i=0;i<n;i++)
    // {
    //     for(ll j=0;j<n;j++)
    //         cout<<ans[i][j]<<" ";

    //     cout<<endl;
    // }


    //QUERIES ANSWERING.. WE JUST NEED OT CHOOSE l ,r WILL BE SAME AS R AS IF IT IS GREATER.. WE WILL SIMPLY INCLUDE IT ELSE 
    // REJECT IT OTHERWISE... 
    while (q--)
    {
        ll x,y;
        cin>>x>>y;

        ll L = (x+(s*last)-1)%n;
        ll R = (y+(s*last)-1)%n;
        ll templ=max(L,R);
        ll tempr=min(L,R);

        L=tempr;
        R=templ;

        ll maxhtillnow=0;
        ll maxlen=0;
        ll r;
        //cout<<"TEST="<<L<<" "<<R<<endl;

        //l HERE IS I
        for(ll i=L;i<=R;i++)
        {
            if(ans[i][R]>maxhtillnow)   maxhtillnow=ans[i][R];
        }

        cout<<maxhtillnow<<endl;
        last=maxhtillnow;
        
    }
    return 0;        
}
    
