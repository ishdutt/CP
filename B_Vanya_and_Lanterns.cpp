#include <bits/stdc++.h>
using namespace std;
#define mp             make_pair
#define pb             push_back
#define fi             first
#define se             second
#define sz(x)          (ll)((x).size())
#define fill(x, y)     memset(x, y, sizeof(y))
#define all(x)         (x).begin(), (x).end()
#define sci(x)         ll x;       scanf("%d", &x);
#define scii(x, y)     ll x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) ll x, y, z; scanf("%d %d %d", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define rep(i, x, y)   for (__typeof(x) i = x; i <= y; i ++)
#define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
typedef long long      ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ll>  iii;
typedef vector<ll>    vi;
typedef vector<ii>     vii;
typedef vector<iii>    viii;
const   ll            inf = 0;
const   long double         eps = 0;
const   ll            ms  = 0;
const   ll            md  = 0;

// void reposition(string s,ll a,ll )

int main() 
{
    ios::sync_with_stdio(false);
    
    ll n,l;
    cin>>n>>l;

    vector<ll>a(n,0);
    for(ll i=0;i<n;i++)
        cin>>a[i];
    
    sort(a.begin(),a.end());

    ll maxdif=0;
    for(ll i=1;i<n;i++)
        maxdif=max(maxdif,a[i]-a[i-1]);
    
    long double rear=l-a[n-1];
    long double front=a[0];

    long double inbet=double(maxdif)/2.0;

    //cout<<fixed<<"rear "<<rear<<"Front "<<front<<" MAx diff= "<<inbet<<endl;
    cout<<fixed<<max(max(rear,front),inbet)<<endl;

	return 0;
}