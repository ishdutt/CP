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
        vector<vector<ll>> a(n,vector<ll>(n,0));
        //ARRAY
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin>>a[i][j];
        }

        vector<bool> mainprobl;

        for(int i=1;i<n;i++)
        {
            if(a[i][0]==i*n+1)    mainprobl.push_back(1);

            else    mainprobl.push_back(0);
        }
        
        // for(int i=0;i<mainprobl.size();i++)
        //     cout<<mainprobl[i]<<" ";

        // cout<<"\n";

        ll ans=0;
        
        //INITIAL CASE
        if(mainprobl[0]==0)
             ans++;

        for(int i=1;i<mainprobl.size();i++)
        {
            //cout<<"TEST "<<ans<<endl;

            if(mainprobl[i-1]==0 && mainprobl[i]==0) continue;

            if(mainprobl[i]==0) ans+=2;
            
        }

        cout<<ans<<endl;

        
        // ll correctplace=0;
        // ll wrongplace=0;
        // //COERCT PLACE
        // if(a[1][0]!=5)  wrongplace+=1;

        // //TO CHECK IF THE LAST ELEMENT WAS PLACED CORRRECTLY OR NOT.. IF ONE THEN NO
        // //ELSE YES
        // ll last_element=0;

        // for(int i=2;i<n;i++)
        // {
        //     //INCORRECT ELEMENT
        //     if(a[i][0]!=i*n)
        //     {
        //         //CHEK IF PREVIOUS ELEMENT WAS CORRECT OR NOT
        //         // IF CORRECT THEN OGNORE THIS ELEMENT
        //         if(a[i-1][0]!=(i-1)*n && i!=2)
        //             continue;
        //         else    wrongplace+=2;

        //         //cout<<"TEST "<<a[i][0]<<wrongplace<<endl;
        //     }
        // }
        // cout<<wrongplace<<endl;

    }
    return 0;        
}
    
