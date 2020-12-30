#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

int main() 
{
    ios::sync_with_stdio(false);
    int t;

    string s;
    cin>>s;
    int k;
    cin>>k;
    vector<int>a(26,0);
    for(int i=0;i<26;i++)
        cin>>a[i];
    
    int ans=*max_element(a.begin(),a.end());
    int output=0;
    for(int i=0;i<s.size();i++)
    {
        output+=a[s[i]-'a']*(i+1);
    }
    int i=s.size();
    //cout<<output<<endl;
    while (k--)
    {
        output+=ans*(i+1);
        i++;
    }
    cout<<output<<endl;
    
    
    return 0;        
}
        
