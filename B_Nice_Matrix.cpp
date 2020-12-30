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

int palindrome(int arr[], int n) 
{ 
    // Initialise flag to zero. 
    int flag = 0; 
  
    // Create another array 
    // to store the original array 
    int arr2[n]; 
    memcpy(arr2, arr, n * sizeof(int)); 
  
    // Reverse the array 
    reverse(arr, arr + n); 
  
    // Check if the array is Palindrome 
    for (int i = 0; i < n; i++) 
        if (arr[i] != arr2[i]) { 
            flag = 1; 
            break; 
        } 
  
    // Print the result 
    if (flag == 0) 
        return 0;
    else
        return 1;
} 


int main() 
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<vector<int> > a( n , vector<int> (m, 0));

        if(n==1 && m==1)
        {
            cout<<"0\n";
            continue;
        }
        
        ll sum=0; 
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                cin>>a[i][j];
                sum+=a[i][j];
            }
                
        }
        int flag1=0;
        int flag2=0;
        ll ans2=0;
        // cout<<"ROW WISE\n";
        //CHECK PALLINDROME FOR ALL THE ROWS AND COLUMNS
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                //cout<<a[i][j]<<" ";
                if(a[i][j]!=a[i][m-j-1])
                {
                    //cout<<"VALUE="<<a[i][j]<<" "<<a[i][m-j-1]<<endl;
                    ans2+=abs(a[i][j]-a[i][m-j-1]);
                    //cout<<"ANS="<<ans2<<endl;
                    flag1=1;
                }
            }
            //cout<<"\n";
                
        }
        
        //ans2/=2;

        // cout<<"N"<<n<<" "<<endl;
        // cout<<"coll WISE\n";


         // accessing element column wise 
        for (ll i = 0; i < m; i++) 
        { 
            for (ll j = 0; j < n; j++) 
            { 
                //cout<<a[j][i]<<" ";
                if(a[j][i]!=a[n-j-1][i])
                {
                    ans2+=abs(a[j][i]-a[n-j-1][i]);
                    //cout<<"ANS1="<<ans2<<endl;
                    flag2=1;
                }
            } 
            //cout<<endl;
        } 
        ans2/=4;
        
        if(flag1==0 && flag2==0)
        {
            cout<<"0\n";
            continue;
        }

        ll ans=0;
        if(m==1)
        {
            for(ll i=0;i<n/2;i++)
            {
                //cout<<"TEST="<<a[i][0]<<" "<<a[n-i-1][0]<<endl;
                if(a[i][0]!=a[n-i-1][0])
                {
                    //cout<<"MOSHI\n";
                    // cout<<n-1-i<<endl;
                    // cout<<a[i][0]<<" "<<a[n-1-i][0]<<endl;
                    ans+=abs(a[i][0]-a[n-1-i][0]);
                }
            }
                
            cout<<ans<<endl;
            continue;
        }

        if(n==1)
        {
            for(ll i=0;i<m/2;i++)
            {
                //cout<<a[0][i]<<" "<<a[0][m-1-i]<<endl;
                if(a[0][i]!=a[0][m-i-1])
                {
                    //cout<<"MOSHI\n";
                    // cout<<n-1-i<<endl;
                    // cout<<a[i][0]<<" "<<a[n-1-i][0]<<endl;
                    ans+=abs(a[0][i]-a[0][m-1-i]);
                }
            }
                
            cout<<ans<<endl;
            continue;
        }

        ll av=sum/(n*m);
        
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                ans+=abs(av-a[i][j]);
            }
                
        }
        //cout<<"TEST0"<<ans2<<" "<<ans<<endl;
        cout<<min(ans,ans2)<<endl;
    }
    
	return 0;
}