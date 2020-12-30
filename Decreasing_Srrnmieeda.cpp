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
            ll l,r;
            cin>>l>>r;

            if(l>=(r/2)+1)
            {
                cout<<r<<endl;
                continue;
            }
            else
            {
                cout<<"-1\n";
                continue;
            }
            
        }
        return 0;        
    }
        
