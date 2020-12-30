#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

int main() 
{
    ios::sync_with_stdio(false);
    
    string s;
    cin>>s;

    unordered_map<char,int>m;
    for(int i=0;i<s.size();i++)
        m[s[i]]++;
    
    int oddcount=0;
    int evencount=0;
    for(auto it:m)
    {
        if(it.second%2==0)  evencount++;
        else
        {
            oddcount++;
        }    
    }
    if(oddcount%2!=0)   cout<<"First"<<endl;

    else if(oddcount%2==0)  cout<<"Second"<<endl;

    return 0;        
}
        
