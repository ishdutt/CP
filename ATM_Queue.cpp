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
    ll total=t;
    while (t--)
    {
        ll n;
        ll x;
        cin>>n>>x;
        vector<ll> a(n,0);
        //ARRAY
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        vector<ll>ans;
        vector<ll>temp(a.begin(),a.end());
        cout<<"Case #"<<total-t<<": ";
        for(ll i=0;i<n;i++)
        {
            if(temp[i]%x==0)
                temp[i]=(temp[i]/x)-1;
            else    
                temp[i]=temp[i]/x;
            
            if(temp[i]==0)
            {
                ans.push_back(i+1);
            }
        }
        
        vector<pair<ll,ll>>t(0);
        for(ll i=0;i<n;i++)
        {
            if(temp[i]!=0)
            {
                t.push_back(make_pair(temp[i],i+1));
            }
        }
        sort(t.begin(),t.end(),[&](pair<ll,ll>a, pair<ll,ll>b)
        {
            return a.first < b.first || (a.first == b.first && a.second < b.second); 
        });

        for(ll i=0;i<t.size();i++)
            ans.push_back(t[i].second);
        
        for(ll i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
        
    }
    
	return 0;
}