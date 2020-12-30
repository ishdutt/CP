#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

int main() 
{
    ios::sync_with_stdio(false);
    
    string s;
    string t;
    cin>>s>>t;
    int automaton=0;
    int array=0;
    int tree=0;

    unordered_map<char,int>ms;
    unordered_map<char,int>mt;
    for(int i=0;i<s.size();i++)
        ms[s[i]]++;

    for(int i=0;i<t.size();i++)
        mt[t[i]]++;
    

    for(int i=0;i<t.size();i++)
    {
        if(mt[t[i]]>ms[t[i]])
        {
            tree=1;
            cout<<"need tree"<<endl;
            return 0;
        }
    }
    array=1;

    //CHECKING FOR AUTOMATON
    //IF POSSSIBLE SUBSEQUENCE OR NOT
    int p2=0;
    for(int i=0;i<s.size();i++)
    {
        if(p2==t.size())
        {
            automaton=1;
            array=0;
            break;
        }
        if(s[i]==t[p2] && p2<t.size()) p2++;
    }
    //cout<<"POINTER="<<p2<<endl;
    if(p2==t.size())
    {
        automaton=1;
        array=0;
    }    

    if(t.size()<s.size())
    {
        if(automaton==0)
        {
            array=1;
            automaton=1;
        }
            
    }

    //FINAL CONDITIONS
    if(array==1 && automaton==1)
    {
        cout<<"both"<<endl;
        return 0;
    }
    else if(array==1)
    {
        cout<<"array"<<endl;
        return 0;
    }
    else
    {
        cout<<"automaton"<<endl;
        return 0;
    }
    

    return 0;        
}
        
