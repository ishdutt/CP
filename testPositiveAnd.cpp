#include <bits/stdc++.h>
using namespace std;

#define ll long long


void solve()
{
    ll n;
    cin >> n;
    unordered_set<ll> PowerOfTwo={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    else if (PowerOfTwo.find(n)!=PowerOfTwo.end())
    {
        cout << -1 << endl;
        return ;
    }
    else
    {
        cout << 2 << " " << 3 << " " << 1<<" ";
        for (ll i = 4; i <= n; i++)
        {
            if (PowerOfTwo.find(i)!=PowerOfTwo.end())
            {
                cout<< i + 1 << " " << i<<" ";
                i++;
            }
            else
            {
                cout<< i<<" ";    
            }
        }
        cout << endl;
        return ;
    }
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}