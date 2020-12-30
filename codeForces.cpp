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
    
    sort(a.begin(),a.end());

    ll ans=LLONG_MAX;
    //cout<<ans<<endl;
    
    float power = 1/float(n-1);
    //cout<<n-1<<"TEST "<<power<<endl;
    ll limit = pow(a[n-1],power)+1;
    //cout<<limit<<endl;

    //FIRST LOOP IS FOR C VALUE
    for(ll i=1;i<=limit;i++)
    {
        ll curr=0;
        //2nd loop for number and power
        for(ll j=0;j<n;j++)
        {   
            //cout<<"TEST "<<pow(i,j)<<" "<<a[j]<<endl;
            curr+=abs(pow(i,j)-a[j]);
        }
        //cout<<"TEST "<<curr<<endl;
        ans=min(ans,curr);
    }

    cout<<ans<<endl;

	return 0;
}

//5934139386
//2147483647
//850575966
//4791531280738
//10000000000
