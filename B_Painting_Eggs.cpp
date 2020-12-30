#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ll tot=0;
    vector<pair<int,int>>a;
    for(int i=0;i<n;i++)
    {
        int a, b;
        cin >> a >> b;
        if (tot+a <= 500) {
            tot += a;
            cout << "A";
        } else {
            tot -= b;
            cout << "G";
        }  
    }
    cout<<endl;
    return 0;
}
        
