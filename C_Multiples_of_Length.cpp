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
    
        ll n;
        cin>>n;
        vector<ll> a;
        //ARRAY
        for(ll i=0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            a.push_back(temp);
        }
    
    if(n==1)    
    {
        cout<<"1 1\n";
        cout<<-a[0]<<endl;
        a[0]=0;
        for(ll i=1;i<3;i++)
        {
            cout<<"1 1\n";
            cout<<a[0]<<endl;
        }
    }
    else
    {
        cout<<"1 1\n";
        cout<<-a[0]<<endl;
        a[0]=0;
        
        cout<<"1 "<<n<<"\n";
        for(ll i=0;i<n;i++)    cout<<-a[i]*n<<" ";
        cout<<endl;
        cout<<"2 "<<n<<endl;
         for(ll i=1;i<n;i++)    cout<<a[i]*(n-1)<<" ";
        cout<<endl;

        
    }
    
    
    
	return 0;
}