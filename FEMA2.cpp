#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;


//========================================NEW VERSION==============================================================
void mapfun(queue<pair<ll,ll>>&iron, queue<pair<ll,ll>>&metal, unordered_map<ll,ll>&maping,ll k)
{
    //NOW SELECTING THE METAL WHICH HAS MINIMUM POWER BETWEEN I AND M.\

    while(!iron.empty())
    {
        //cout<<"TEST\n";
        ll power=INT_MAX;
        queue<pair<ll,ll>>temp=metal;
        while(!temp.empty())
        {

            //cout<<"k+1+sheet till i="<<iron.front().second<<" sheet till m="<<temp.front().second<<" diff="<<abs( iron.front().first - temp.front().first )<<endl;
            
            //cout<<"POSSIBLES PAIRS metal="<<temp.front().first<<" iron="<<iron.front().first<<endl;
            //FIXME: DUPLICATES ASSIGN HO RHE HAII
            //POPING THE DIFFERENT ELEMENT HERE!!!!!!!!!!!!!!!
            ll temppower=k + 1 - abs(iron.front().second - temp.front().second) - abs( iron.front().first - temp.front().first );
            if(temppower>0 && power>temppower)
            {
                //cout<<"KISKE SAATH PAIRING metal="<<temp.front().first<<" iron="<<iron.front().first<<" Temppower="<<temppower<<endl;
                maping[iron.front().first]=temp.front().first;
                power=temppower;
                temp.pop();
                //remove from metal as well since we don't need to use that metal again
                
                // break;
            }

            else    temp.pop();   
        }
        //POP ONLY WHEN IT IS MODIFIED.. THEN REMOVE THAT ELEMENT SO THAT NO DUPLICACY
        if(power!=INT_MAX)
        {   
            // //FIXME:
            // //POP THE ELEMENT WHICH IS SELECTED RE.. NOT THE FIRST ELEMENT
            //cout<<"SMOIH\n";
            // vector<pair<ll,ll>>change;
            // queue<pair<ll,ll>>temp2=metal;
            // while (!temp2.empty())
            // {
            //     //cout<<"YOYO\n";
            //     // /* code */
            //     if(temp2.front().first==maping[iron.front().first])
            //     {
            //         temp2.pop();
            //         continue;
            //     }
                    
            //     else
            //     {
            //         change.push_back(make_pair(temp2.front().first,temp2.front().second));
            //     }
            //     temp2.pop();
            // }
            // metal=queue <pair<ll,ll>>(change.begin(),change.end());
            metal.pop();
        }
            
        iron.pop();
    }    
    iron = queue <pair<ll,ll>>();
    metal=queue <pair<ll,ll>>();
}


int main() 
{
    ios::sync_with_stdio(false);
    
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,k;
        cin>>n;
        cin>>k;

        vector<char> a;
        //ARRAY
        for(ll i=0;i<n;i++)
        {
            char temp;
            cin>>temp;
            a.push_back(temp);
        }

        //
        queue<pair<ll,ll>>iron;
        queue<pair<ll,ll>>metal;

        ll sheet=0;
        //STROING THE PAIR VALUES
        //CHECK IF DUPLICATES ARE POSSIBLE IN THIS SCENARIO..
        //vector<pair<ll,ll>>maping;

        unordered_map<ll,ll>maping;
        for(ll i=0;i<n;i++)
        {
            if(a[i]=='I')   iron.push(make_pair(i,sheet));

            else if(a[i]=='M')   metal.push(make_pair(i,sheet));
            
            else if(a[i]==':')  sheet++;
            //ab yaha pe sahi pair khojo aur match kardo 
            else if(a[i]=='X')    mapfun(iron,metal,maping,k);
        }
        //HANDLE WHEN NO X IS PRESENT TOO./ THE LAST STRING COMPONENT 

        if(metal.size()!=0 && iron.size()!=0)
            mapfun(iron,metal,maping,k);

        // cout<<"TE    
        // for(auto it:maping)  
        //     cout<<"IRON INDEX="<<it.first<<" METAL INDEX"<<  it.second<<endl;

        cout<<maping.size()<<endl;
    }
    return 0;        
}
    
