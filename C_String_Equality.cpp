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
            ll n,k;
            cin>>n>>k;

            string sa,sb;
            cin>>sa>>sb;

            
            //matching the charcter count;

            // for(int i=0;i<n;i++)  
            // {
            //     if(ma[sa[i]]!=mb[sa[i]])

            // }

            //WHEN SAME CHARACTERS .. ONE IS PERMUTATION OF OTHER THEN YES
            sort(sa.begin(),sa.end());
            sort(sb.begin(),sb.end());

            if(sa==sb)
            {
                cout<<"YES\n";
                continue;
            }  
            
            int flag=0;
            //CHECK IF EQUAL
            //  cout<<"TEST="<<sa[0]-'a'<<endl;
            //if(sa[0]-'a'>sb[0]-'a')    cout<<"NO\n";
            for(int i=0;i<n;i++)
            {
                if(sa[i]-'a'>sb[i]-'a')
                {
                    //cout<<"MOSHI\n";
                    flag=1;
                    cout<<"NO\n";
                    break;
                }
                if(sa[i]!=sb[i])
                {
                    //
                    int temp=k;
                    //if bothb not equal then gaya bhans
                    while (temp && (sa[i]==sa[i+1]&&sb[i]==sb[i+1]||temp==1) )
                    {
                        //cout<<"HELLO\n";
                        temp--;
                        i++;
                    }
                    //for not missing that after temp char
                    i--;
                    if(temp!=0)
                    {
                        flag=1;
                        cout<<"NO\n";
                        break;
                    }
                }

            }
            if(flag==0)
            cout<<"YES\n";
        }
        
        return 0;
    }