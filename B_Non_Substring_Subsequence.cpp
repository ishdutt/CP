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
        ll n,q;
        cin>>n>>q;

        string s;
        cin>>s;
        
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            
            string snew="";
            for(int i=l;i<r+1;i++)
                snew+=s[i];

            char first=snew[0];
            char last=snew[snew.size()-1];
            
            //cout<<"TEST="<<snew<<endl;
            int flag=0;

            //check in range 0-l
            for(int i=0;i<l;i++)
            {
                if(s[i]==first)
                {
                    //cout<<"YE HAI RE\n";
                    flag=1;
                }     
            }
                

            //r-n me check
            for(int i=r+1;i<n;i++)
            {
                if(s[i]==last)
                {   
                    //cout<<"MOS\n";
                    flag=1;
                }  
            }
                

            if(flag!=0) cout<<"YES\n";

            else cout<<"NO\n";
        }
          
    }
    
	return 0;
}