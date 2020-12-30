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

//FIXME:D.. MY FIRST DP SOLUTION ;)

ll solve(ll n,ll time,vector<ll>a,vector<vector<ll>>&dp)
{
    
    if(n-1<0)    return dp[n][time]=0;

    else if(time<n)  return dp[n][time]=INT_MAX;

    // cout<<"TEST="<<n<<" "<<time<<" "<<a[n-1]<<endl;
    //WE HAVE 2 OPTIONS.. EITHER REMOVE THE DISH FROM OVEN.. ADD THE ABS(A[I]-TIME) VALUE ELSE DECREASE THE TIME WITHOUT CHANGING 
    // THE DISH
    // HERE WE SORTED THE LIST.. SO OBJECTS WILL BE REMOVED BASED ON STARTING TIME ONLY..ie.. MAX TIME DISH WILL BE REMOVED LAST

    else if(dp[n][time]!=-1)   return dp[n][time];

    return dp[n][time]=min(
            solve(n-1,time-1,a,dp)+abs(a[n-1]-time),
            solve(n,time-1,a,dp));
    
    
}


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
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

        sort(a.begin(),a.end());
        vector<vector<ll>>dp(a.size()+1,vector<ll>(a[n-1]+a.size()+1,-1));
        

        cout<<solve(a.size(),a[n-1]+a.size(),a,dp)<<endl;     
    }
    
	return 0;
}