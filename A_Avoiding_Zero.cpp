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
        vector<ll> a;
        //ARRAY
        for(int i=0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            a.push_back(temp);
        }

        ll countpos=0;
        ll countneg=0;
        for (ll i = 0; i < n; i++)
        {
            if(a[i]>0)
            countpos+=a[i];
            else
            {
                countneg+=a[i];
            }
            
        }
        
        if(abs(countneg)>countpos)
            sort(a.begin(),a.end());

        else if(abs(countneg)==countpos)
        {
            cout<<"NO\n";
            continue;
        }
        
        else if(abs(countneg)<countpos)
        {
            sort(a.begin(),a.end(),greater<int>());
        }
        

        ll sum=0;
        int flag=0;
        for(ll i=0;i<n;i++)
        {
            sum+=a[i];
            if(sum==0)
            {
                cout<<"NO\n";
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"YES\n";
            for(ll i=0;i<n;i++)
                cout<<a[i]<<" ";
            cout<<endl;
        }
            
    }
    
	return 0;
}