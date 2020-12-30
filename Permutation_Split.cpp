#include <bits/stdc++.h>
using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
typedef long long ll;
 
void solve(int tc = 0) {
	ll n; 
	cin >> n;
	ll a[n], b[n];
	
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	ll tot = 0;
	
	for (ll i = 0; i < n; i++) {
		ll inv = 0;
		for (ll j = 0; j < i; j++) {
			if (a[j] > a[i]) ++inv;
		}
		
		for (ll j = i + 1; j < n; j++) {
			if (a[i] > a[j]) ++inv;
		}
		
        //cout<<"TEST="<<inv<<" "<<inv2<<endl;
		// ARRAY FOR EACH ELEMENTS 
		b[i] = inv;
		tot += inv;
        
	}
	cout<<"B array=";
    for(ll i=0;i<n;i++)
        cout<<b[i]<<" ";
    cout<<endl;

	tot /= 2;
	
	ll dp[tot + 1] = {0};
	dp[0] = 1;
	for (ll i = 0; i < n; i++) 
    {
		for (ll j = tot; j >= 0; j--) 
        {
            cout<<b[i]<<" "<<j<<"\n";
			//DP IS EITHER WE DIVIDE THE SET INTO J AND B[I] OR JUST
				// CONSIDER THE SINGLE DP[J](I.E ONLY J)
			if (j + b[i] <= tot) 
				dp[j + b[i]] |= dp[j];
		}
	}

    //dp table	
    cout<<"DP table=";
    for(ll i=0;i<tot+1;i++)
        cout<<dp[i]<<" ";
    cout<<"\n";
	
	cout << (dp[tot] ? "YES\n" : "NO\n");
}
 
int main() {
	send help
	
	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
}  