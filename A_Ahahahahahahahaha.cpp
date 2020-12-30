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
        ll countzero=0;
        for(int i=0;i<n;i++)
            if(a[i]==0) countzero++;


        vector<ll>newarray;
        if(countzero==0)
        {
            cout<<n<<endl;
            
            for(ll i=0;i<n;i++)
                cout<<a[i]<<" ";
            cout<<"\n";
        }
        else if(countzero==n)
        {
            cout<<n<<endl;
            for(ll i=0;i<n;i++)
                cout<<a[i]<<" ";
            cout<<"\n"  ;
        }

        //zeros ka case
        else if(countzero>=n/2 )
        {
            cout<<countzero<<endl;
            for(ll i=0;i<countzero;i++)
                cout<<0<<" ";
            cout<<"\n";
        }
        
        //1 ki baaru hai
        else if(countzero<n/2 )
        {
            if((n-countzero)%2==0)
            {
                ll k=n-countzero;
                for(ll i=0;i<n-countzero;i++)
                    newarray.push_back(1);

                cout<<newarray.size()<<endl;
                for(ll i=0;i<newarray.size();i++)   
                    cout<<newarray[i]<<" ";    
                cout<<"\n";
            }
            //FIXME: 
            else
            {
                if(n%4==0)
                {
                    cout<<n/2<<endl;
                    for(ll i=0;i<n/2;i++)
                        cout<<"1 ";
                    cout<<"\n";
                }
                else
                {
                    cout<<(n/2)+1<<endl;
                    for(ll i=0;i<=n/2;i++)
                        cout<<"1 ";
                    cout<<"\n";
                }
                

            }
            

        }
        
        
    }
    
	return 0;
}