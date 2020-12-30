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



ll ncr(ll n, ll r)
{
    if(r==1)    return n;

    return n/r*ncr(n,r-1);
}

int main() 
{
    ios::sync_with_stdio(false);
    
    ll n,m;
    cin>>n>>m;

    ll maxpair=n-m+1;
    ll minpair=(n/m)+n%m;   //1 only
    ll minpairforothergroups=n/m;   //

    ll maxans=maxpair*(maxpair-1)/2;
    

    // if(minpairforothergroups!=1)
    //     ll minans=minpair*(minpair-1)/2 + minpairforothergroups*(minpairforothergroups-1)*(m-1)/2;


    
    ll minans=n%m;

    //cout<<"TEST "<<minpairforothergroups<<" "<<minans<<endl;
    ll finalmin= minpairforothergroups*(minpairforothergroups+1)*minans/2
                 +
                 minpairforothergroups*(minpairforothergroups-1)*(m-minans)/2;

    // else
    // {
    //     ll minans=minpair*(minpair-1)/2;
    
    // }
    



    cout<<finalmin<<" "<<maxans<<endl;
    
	return 0;
}