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

// void reposition(string s,int a,int )

int main() 
{
    ios::sync_with_stdio(false);
    
    ll n;
    cin>>n;
    vector<ll>a;
    
    while(n>10)
    {
        a.push_back(n%10);
        n=n/10;
    }
    a.push_back(n);
    
    reverse(a.begin(),a.end());

    ll leftmosteven=0;
    ll evenany=0;
    ll count=0;

    for(ll i=a.size()-2;i>=0;i--)
    {
        if(a[i]%2==0)
        {
            count++;
            leftmosteven=i;
            if(count==1)    evenany=i;

            if(a[leftmosteven] < a[a.size()-1])
            {
                evenany=i;
            }
        }
    }
    swap(a[evenany],a[a.size()-1]);

    if(count==0)
    {
        cout<<-1<<endl;
        return 0;
    }    
    for(int i=0;i<a.size();i++)
        cout<<a[i];

    cout<<endl;

	return 0;
}