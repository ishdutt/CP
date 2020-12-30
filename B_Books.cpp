#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

int main() 
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,t;
    cin>>n>>t;
    vector<int>a(n,0);
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    int l = 0, r = 0, sum = 0, ans = 0;
	while (r<n)
	{
		sum += a[r];
		if (sum <= t)
		{
			ans = max(ans, (r-l + 1));
		}
        //SUBTRACT THE L WHICH ARE CAUSING THE OVERFLOW
		while (sum > t)
		{
			sum -= a[l];
			l++;
		}
		r++;
	}
	cout << ans << endl;
    

    return 0;        
}
        
