#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
 os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
	return os << "(" << P.first << "," << P.second << ")";}
 
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif
 
 
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector< pii >
#define I insert 
#define pb push_back
#define F first
#define S second
#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define mp make_pair
#define endl "\n"
 
 
void solve(){
	int N; cin>>N;
	ll ans = 0; int num = 0;
	vi v(N); 
	for(int i=0;i<N;i++){
		cin>>v[i];
		tie(ans, num) = v[i]>0 ? mp(ans+v[i], num+1) : mp(ans, num) ;
	}
	cout<<ans<<"\n"; 
	vi seq;
	for(int i=0;i<N;i++){
		if(i<num && v[i]<=0) seq.pb(i);
		else if(i>=num && v[i]>0) seq.pb(i);  
	}
	cout<<seq.size()<<" "; for(auto z:seq) cout<<z+1<<" ";
	cout<<"\n";
}
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<setprecision(25);
	int T; cin>>T;
	while(T--){
		solve();
	}
}