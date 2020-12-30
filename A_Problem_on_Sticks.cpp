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
        
        ll correctplace=0;
        ll wrongplace=0;
        //COERCT PLACE
        if(a[1][1]!=5)  wrongplace+=1;

        //TO CHECK IF THE LAST ELEMENT WAS PLACED CORRRECTLY OR NOT.. IF ONE THEN NO
        //ELSE YES
        ll last_element=0;

        for(int i=1;i<n;i++)
        {
            //INCORRECT ELEMENT
            if(a[i][0]!=i*n)
            {
                //CHEK IF PREVIOUS ELEMENT WAS CORRECT OR NOT
                if(a[i-1][0]==(i-1)*n)
                    continue;
                else    wrongplace+=2;
            }
        }
        cout<<wrongplace<<endl;

    }
    return 0;        
}
    
