// @Copyright vxd447	
//#define _GLIBCXX_DEBUG    
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize "trapv"

using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define pll pair<long long,long long>
#define mod 1000000007
#define PI 3.141592653589793238
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0; i<(n); ++i)
#define repA(i,a,n) for(int i=a; i<=(n); ++i)
#define repD(i,a,n) for(int i=a; i>=(n); --i)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define print_clock cerr<<"Time : "<< 1000 * (long double) clock() / (long double) CLOCKS_PER_SEC << "ms\n" ;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll n; cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	sort(all(a));
	ll mn = LLONG_MAX;
    cout<<"TEST "<<mn<<endl;
	for(ll i = 1; pow(i, n-1) <= 10000000000; i++){
		ll temp = 0;
		for(int j = 0; j < n; j++){
			temp += abs(a[j] - pow(i, j));
		}
		mn = min(mn, temp);
	}
	cout << mn << '\n';
	print_clock
	return 0;
}