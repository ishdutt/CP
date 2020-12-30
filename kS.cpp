//  Mayank Agarwal
//  IIIT Hyderabad



#include<bits/stdc++.h>
using namespace std;
const long long int M = 1000000007; 
#define ll long long int
#define ld double
#define pb push_back
#define mp make_pair
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t,t1;
    cin>>t;
    t1=1;
    while(t--)
    {
        ll n,a,b,c;
        cin>>n>>a>>b>>c;
        if(n==1)
        {
            if(a==1 && b==1 && c==1)
            {
                cout<<"Case #"<<t1<<": 1\n";
            }
            else
            {
                cout<<"Case #"<<t1<<": IMPOSSIBLE"<<'\n';
            }
            t1++;
            continue;
        }
        if(n==2)
        {
            if(n==a+b-c)
            {
                cout<<"Case #"<<t1<<": ";
                for (int i = 0; i < a-c; ++i)
                {
                    cout<<"1 ";
                }
                for (int i = 0; i < c; ++i)
                {
                    cout<<n<<" ";
                }
                for (int i = 0; i < b-c; ++i)
                {
                    cout<<"1 ";
                }
                cout<<'\n';
                t1++; 
            }
            else
            {
                cout<<"Case #"<<t1<<": IMPOSSIBLE"<<'\n';
                t1++;
            }
            continue;
        }
        if(a+b-c>n)
        {
            cout<<"Case #"<<t1<<": IMPOSSIBLE"<<'\n';
            t1++;
            continue;
        }
        std::vector<ll> ans;
        for (int i = 0; i < a-c; ++i)
        {
            ans.pb(2);
        }
        ll zz=0;
        if(a-c!=0)
        {
            for (int i = 0; i < n-a-b+c; ++i)
            {
                ans.pb(1);
            }
            zz=1;
        }
        ll c1=c;
        ans.pb(n);
        c1--;
        if(c1 && zz==0)
        {
            for (int i = 0; i < n-a-b+c; ++i)
            {
                ans.pb(1);
            }
            zz=1;        
        }
        for (int i = 0; i < c1; ++i)
        {
            ans.pb(n);
        }
        if(zz==0 && b-c!=0)
        {
            for (int i = 0; i < n-a-b+c; ++i)
            {
                ans.pb(1);
            }
            zz=1;
        }
        for (int i = 0; i < b-c; ++i)
        {
            ans.pb(2);
        }
        // cout<<'\n';
       if(zz==0)
       {
            cout<<"Case #"<<t1<<": IMPOSSIBLE"<<'\n';
            t1++;
            continue;
       }
        cout<<"Case #"<<t1<<": ";
       for (int i = 0; i < n; ++i)
       {
           cout<<ans[i]<<" ";
       }
       t1++;
       cout<<'\n';
    }
}