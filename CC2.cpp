#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;


int main() 
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vector<int> a(n,-1);
        //ARRAY
        for(int i=0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            // a.push_back(temp);
            a[i]=temp;
        }
        cout<<"TEST\n";
        ll contzero=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ll maxtemp=0;
            while(a[i]==0)  maxtemp++;

            contzero=max(contzero,maxtemp);
        }
        cout<<contzero<<endl;
    }
    
	return 0;
}

/*4
7
1 1 0 0 0 1 1
8
1 0 1 1 1 0 0 1
4
1 1 0 1
4
1 1 1 1*/