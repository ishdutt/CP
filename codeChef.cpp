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
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        //EDge case
        
        ll onedata=0;
        ll zerodata=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')  zerodata++;

            else    onedata++;
        }

        if(onedata==0 || zerodata==0)
        {
            if(s.size()%2==0)
            {
                cout<<s<<endl;
                continue;
            }
        }

        if(onedata!=zerodata)
        {
            cout<<"IMPOSSIBLE\n" ;
            continue;
        }   

        string temp="";
        if((n/k)%2==0)
        {
            //Starting is 10
            for(int i=0;i<k;i++)
            {
                if(i%2==0)  temp+='1';
                else    temp+='0';
            }
            cout<<"TEST\n";
            while (temp.size()!=n)
            {
                string tempt = temp.substr(0,2*k);
                //cout<<tempt;
                reverse(tempt.begin(),tempt.end());
                temp.insert(0,tempt);
            }
            cout<<temp<<endl;
            continue;
            
        }

        if((n/k)%2!=0)
        {
            //Starting is 10
            for(int i=0;i<k;i++)
            {
                if(i%2==0)  temp+='0';
                else    temp+='1';
            }
            cout<<"TEST\n";
            while (temp.size()!=n)
            {
                string tempt = temp.substr(0,2*k);
                //cout<<tempt;
                reverse(tempt.begin(),tempt.end());
                temp.insert(0,tempt);
            }
            cout<<temp<<endl;
            continue;
        }
    }
        
    return 0;        
}
    
