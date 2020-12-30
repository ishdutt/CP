#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

//FIXME: CHECK FOR EVERY STEPS .. IF IT FAILS ANYWHERE (DONE)

int main() 
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--)
    {
        ll n,X,p,k;
        cin>>n>>X>>p>>k;

        vector<ll>a(n);
		for(auto&x : a) cin >> x;

        sort(a.begin(),a.end());

        ll xindex=0;
        ll xispresent=0;

        ll mindif=LONG_MAX;
        //if(X present)
        for(ll i=0;i<n;i++)
            if(a[i]==X)
            {
                //IF MULTIPLE OCCURENCES THEN TAKE XINDEX WHICH IS CLOSEST TO P
                if(abs(i-p)<mindif)
                {
                    mindif=abs(i-p);
                    xindex=i;
                    xispresent=1;
                }
                
            }


        //1ST SMALLEST REFERS TO 0TH ELEMENT ;)
        if(xispresent)
        {

            //NEGATIVE CASES:
            // if(k-1<xindex && xindex<p-1)
            // {
            //     cout<<"-1\n";
            //     continue;
            // }
            // else if(p-1<xindex && xindex<k-1)
            // {
            //     cout<<"-1\n";
            //     continue;
            // }

            // else if((p-1<k-1 && k-1<xindex)||(xindex<k-1 && k-1<p-1))
            // {
            //     cout<<"-1\n";
            //     continue;
            // }
            if(a[p-1]==X)
            {
                cout<<"0"<<endl;
                continue;
            }

            if(p < k && p-1 < xindex) 
            {
                //cout<<"HELLO\n";
                cout << "-1"<<endl;
                continue;
            }

            else if(p > k && p-1 > xindex) 
            {
                //cout<<"CONAN\n";
                cout << "-1"<<endl;
                continue;
            }
            //POSITIVE CASES WITH NUM. OF STEPS
            //cout<<"TEST="<<xindex<<" "<<p<<endl;
            cout<<abs(xindex+1-p)<<endl;
            
        }
        //FIXME: CHECKOUT HERE.. SINCE DEFAULT IS -1...IF ANY POSITIVE CASE MISSED IN IFs
        // THEN -1 WHICH IS WHY IT'S NOT WORKING...EVERYTIME...
        //IT'S THE SAME FOR EVERY SUBMISSION
        else if(!xispresent)
        {
            //cout<<"MOSHI\n";
               
            a[k-1]=X;
            sort(a.begin(),a.end());
                        
            //x index
            ll Xindex=0;
            for(ll i=0;i<n;i++)
                if(a[i]==X)
                    Xindex=i;
                    

            //NEGATIVE CASES:
            // if(k-1<Xindex && Xindex<p-1)
            // {
            //     cout<<"-1\n";
            //     continue;
            // }
            // else if(p-1<Xindex && Xindex<k-1)
            // {
            //     cout<<"-1\n";
            //     continue;
            // }

            // else if( (p-1<k-1 && k-1<Xindex)||(Xindex<k-1 && k-1<p-1))
            // {
            //     cout<<"-1\n";
            //     continue;
            // }

            if(a[p-1]==X)
            {
                cout<<"1"<<endl;
                continue;
            }

            if(p < k && p-1 < Xindex) 
            {
                //cout<<"HELLO\n";
                cout << "-1"<<endl;
                continue;
            }

            else if(p > k && p-1 > Xindex) 
            {
                //cout<<"CONAN\n";
                cout << "-1"<<endl;
                continue;
            }
            //POSITIVE CASES WITH NUM. OF STEPS
                    
            cout<<abs(Xindex+1-p)+1<<endl;
            
        }
    }
    return 0;        
}
    
