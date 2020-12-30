#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;


int main() 
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vector<ll>poweroftwo(21,0);
    for(int i=0;i<21;i++)
        poweroftwo[i]=pow(2,i);
    
    // for(int i=0;i<poweroftwo.size();i++)
    //     cout<<poweroftwo[i]<<" ";
    // cout<<endl;
    while (t--)
    {
        ll n;
        cin>>n;
        cout<<"1 "<<poweroftwo[20]<<endl;
        ll reply;
        cin>>reply;
        //SUM OF ALL THE N NUMBERS
        ll sum=reply-(poweroftwo[20]*n);
        ll finalxor=0;

        // IF SUM IS ODD.. ADD ONE TO THE FINAL XOR 
        if(sum%2!=0)    finalxor++;
        //cout<<"SUm="<<sum<<endl;
        for(ll i=1;i<20;i++)
        {
            // XOR SUM ACCORDING TO THE SUM VALUE
            ll mysum=sum+(poweroftwo[i]*n);
            cout<<"1 "<<poweroftwo[i]<<endl;
            ll repliedanswer;
            cin>>repliedanswer;

            //IF DIFFERENCE IN BOTH ANSWER/2**I+1 IS ODD THEN ADD POWER IN FINAL XOR
            //cout<<"REPLIED="<<repliedanswer<<"MAGIC VALUE="<<((mysum-repliedanswer)/(poweroftwo[i]*2))<<endl;
            if(((mysum-repliedanswer)/(poweroftwo[i]*2))%2!=0)
            {
                //cout<<"MOSHI"<<endl;
                finalxor+=poweroftwo[i];
                //cout<<"TEST="<<finalxor<<endl;
            }
                
        }
        cout<<"2 "<<finalxor<<endl;
        int correctness;
        cin>>correctness;
        if(correctness==1)
        {
            //cout<<"1"<<endl;
            continue;
        }   

        else
        {
            //cout<<"-1"<<endl;
            break;
        }    
    }
    return 0;        
}
    
    