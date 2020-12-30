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


void simpleSieve(int limit, vector<int>& prime)
{
	bool mark[limit + 1];
	memset(mark, false, sizeof(mark));

    //cout<<"TEST from Simple Sieve="<<limit<<endl;
    limit=limit*limit;

	for (int i = 2; i*i <= limit; ++i) 
	{
		if (mark[i] == false) 
		{
            //cout<<"TEST2\n";
			prime.push_back(i);
			for (int j = i; j <= limit; j += i)
				mark[j] = true;
		}
	}
}

vector<ll> primesInRange(int low, int high)
{
    //cout<<"TEST="<<low<<" "<<high<<endl;
	int limit = floor(sqrt(high)) + 1;
	vector<int> prime;
	simpleSieve(high, prime);

	int n = high - low + 1;

	bool mark[n + 1];
	memset(mark, false, sizeof(mark));

	for (int i = 0; i < prime.size(); i++) 
	{
		//cout<<"TEST\n";
		int loLim = floor(low / prime[i]) * prime[i];
		if (loLim < low)
			loLim += prime[i];
		if(loLim==prime[i])
			loLim += prime[i];
		

		for (int j = loLim; j <= high; j += prime[i])
			if(j != prime[i])
            {
                //cout<<"Source="<<j-low<<endl;
                mark[j - low] = true;
            }
			
	}

    vector<ll>p;
	for (int i = low; i <= high; i++)
		if (!mark[i - low])
			p.push_back(i);
    return p;
}



int main() 
{
    ios::sync_with_stdio(false);
    
    ll n;
    cin>>n;

    vector<ll>a(n,0);
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    ll upperbound=0;

    for(ll i=0;i<n;i++)
        upperbound=max(upperbound,a[i]);

    vector<ll> primes = primesInRange(2, pow(upperbound,0.5));

    //primesInRange(2, upperbound)  ;  

    // cout<<"TESt "<<upperbound<<endl;
    // for(ll i=0;i<primes.size();i++)
    //     cout<<primes[i]<<" ";
    // cout<<endl;


    unordered_set<ll>primeset(primes.begin(),primes.end());


    // cout<<"TESt\n";
    // for(auto it:primeset)
    //     cout<<it<<" ";
    // cout<<endl;

    for(ll i=0;i<n;i++)
    {
        ll root=pow(a[i],0.5);

        //if not a perfect square then just ignore it
        if(root*root!=a[i])
        {
            cout<<"NO\n";
            continue;
        }

        if(primeset.find(root)!=primeset.end())
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
        
    }

    // for(int i=0;i<ans.size();i++)
    //     cout<<ans[i]<<endl;

	return 0;
}