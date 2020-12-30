#include <bits/stdc++.h>
using namespace std;
#define mp             make_pair
#define pb             push_back
#define fi             first
#define se             second
#define sz(x)          (int)((x).size())
#define fill(x, y)     memset(x, y, sizeof(y))
#define all(x)         (x).begin(), (x).end()
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define rep(i, x, y)   for (__typeof(x) i = x; i <= y; i ++)
#define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
typedef long long      ll;
typedef pair<int, int> ii;
typedef pair<ii, int>  iii;
typedef vector<int>    vi;
typedef vector<ii>     vii;
typedef vector<iii>    viii;
const   int            inf = 0;
const   double         eps = 0;
const   int            ms  = 0;
const   int            md  = 0;


int main() 
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        
        ll ans=0;
        //1st is index,second is in degreee and 3rd is out degree
        map<int,pair<int,int>>m;

        for(ll i=0;i<n-1;i++)
        {
            // cout<<"YO\n";
            if(s[i]=='-')
            {
                m[i].first=1;
                m[i].second=1;

                m[i+1].first=1;
                m[i+1].second=1;
                
            }
            else if(s[i]=='>')
            {
                m[i].second=1;
                m[i+1].first=1;
            }
            else if(s[i]=='<')
            {
                m[i].first=1;
                m[i+1].second=1;
            }
        }
        
        int c=0;
        int ac=0;
        for(ll i=0;i<n;i++)
        {
            if(s[i]=='<')   ac++;
            else if(s[i]=='>')  c++;
        }
        cout<<"TEST="<<ac<<" "<<c<<endl;
        if(c>0 && ac>0)
        {
            if(ac>0)
            {
                ll finalans=0;
                for(ll i=0;i<n;i++)
                {
                    if(s[i]=='-')
                    finalans++;
                }
                cout<<finalans+1<<endl;
                continue;
            }
            
        }


        for(auto it:m)
        {
            //cout<<it.second.first<<" "<<it.second.second<<endl;
            if(it.second.first==1&&it.second.second==1) ans++;

        }

        //IF ALTERNATE CYCLES
        // for(ll i=0;i<n;i++)
        // {
        //     if(i%2==0)
        //     {
        //         if(s[i]=='-')

        //     }
            
        // }

        //IF NO CYCLE THEN DON'T INCLUDE THE ONES WITH < OR THIS
        if(ans!=n)
        {
            ans=0;
            for(ll i=0;i<n;i++)
                if(s[i]=='-') ans++;
            
            if(ans!=0)
                cout<<ans+1<<endl;
            
            //IF NO CYCLE AND NO - IS THERE
            else
            {
                cout<<0<<endl;
                continue;
            }
            
            continue;
        }

        if(ans==1)
        {
            cout<<0<<endl;
            continue;
        }

        if(s=="<>"||s=="><")
        {
            cout<<0<<endl;
            continue;   
        }
        
        cout<<ans<<endl;
    }
    
	return 0;
}