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
        ll person_limit,follower_limit;
        cin>>person_limit>>follower_limit;

        ll sword_count,axe_count;
        cin>>sword_count>>axe_count;

        ll weight_sw,weight_axe;
        cin>>weight_sw>>weight_axe;

        //LOGIC
        ll itlmtForme= person_limit/min(weight_sw,weight_axe);
         
        ll min_dif=INT_MAX;
        ll a=0,b=0;
        ll curr=0;
        for(ll i=1;i<=itlmtForme && i<=sword_count;i++)
        {
            ll coef = (person_limit - weight_sw*i)/weight_axe;
            if(coef>axe_count)  continue;

            else
            {
                curr= person_limit - (coef*weight_axe + weight_sw*i);
                if(curr<min_dif || a+b<i+coef)
                {
                    min_dif=curr;
                    a=i;
                    b=coef;
                }
            }
            
        }

        for(ll i=1;i<=itlmtForme && i<=axe_count;i++)
        {
            ll coef = (person_limit - weight_axe*i)/weight_sw;
            if(coef>sword_count)  continue;

            else
            {
                curr= person_limit - (coef*weight_sw + weight_axe*i);
                if(curr<min_dif || a+b<i+coef)
                {
                    min_dif=curr;
                    a=i;
                    b=coef;
                }
            }
            
        }

        sword_count-=a;
        axe_count-=b;

        ll itlmtfollower= follower_limit/min(weight_sw,weight_axe);

        //cout<<"Lasrt bound "<<itlmtfollower<<endl;
        min_dif=INT_MAX;
        ll c=0,d=0;
        curr=0;
        // RUN FOR AXE AND SWORD BOTH
        for(ll i=1;i<=itlmtfollower && i<=sword_count;i++)
        {
            //cout<<"i "<<i<<endl;

            ll coef2 = (follower_limit - weight_sw*i)/weight_axe;

            //cout<<"TEST coef2 "<<coef2<<" i="<<i<<endl;
            if(coef2>axe_count)  continue;
            
            else
            {
                curr= follower_limit - (coef2*weight_axe + weight_sw*i);
                if(curr<min_dif || c+d<i+coef2)
                {
                    min_dif=curr;
                    c=i;
                    d=coef2;
                }
            }
            
        }


        for(ll i=1;i<=itlmtfollower && i<=axe_count;i++)
        {
            //cout<<"i "<<i<<endl;

            ll coef2 = (follower_limit - weight_axe*i)/weight_sw;

            //cout<<"TEST coef2 "<<coef2<<" i="<<i<<endl;
            if(coef2>sword_count)  continue;
            
            else
            {
                curr= follower_limit - (coef2*weight_sw + weight_axe*i);
                if(curr<min_dif || c+d<i+coef2)
                {
                    min_dif=curr;
                    c=i;
                    d=coef2;
                }
            }
            
        }

        // cout<<c<<" "<<d<<endl;
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    }
    
	return 0;
}