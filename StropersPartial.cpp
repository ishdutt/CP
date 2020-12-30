#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;


void equi(vector<string>&a , set<pair<pair<int,int>,pair<int,int>>>&Subset)
{
    for(int i=0;i<a.size();i++)
    {
        int zero=count(a[i].begin(), a[i].end(), '0'); 
        int one=count(a[i].begin(), a[i].end(), '1'); 
        int tillone=0;
        int sumeven=0,sumodd=0;
        for(int j=0;j<a[i].size();j++)
        {
            if(a[i][j]=='1')
                tillone++;
            else
            {
                if(tillone%2==0)    sumeven++;
                else    sumodd++;
            }
        }
        Subset.insert(make_pair(make_pair(zero,one),make_pair(sumeven,sumodd)));
    }
}


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        //vector<string>a;
        unordered_set<string> uniqueset;
        // for(int i=0;i<=s.size();i++)
        // {
        //     for(int j=i+1;j<=s.size();j++)
        //     {
        //         string temp(s.begin()+i,s.begin()+j);
        //         a.push_back(temp);
        //     }
        // }

        for (int i = 0; i < s.size(); i++)
        {
            char temp[s.size() - i + 1];
            int tempindex = 0;
            for (int j = i; j < s.size(); j++)
            {
                temp[tempindex++] = s[j];
                uniqueset.insert(temp);
            }
        }

        // for(int i=1;i<=s.size();i++)
        // {
        //     for(int j=0;j<s.size();j++)
        //     {
        //         string temp(s.begin()+i,s.begin()+j);
        //         a.push_back(temp);
        //     }
        // }
        //vector<string>a(uniqueset.begin(),uniqueset.end());
        
        // vector<vector<int>> groups=group_identical_strings(a);

        // vector<string>uni;
        // for(int i=0;i<groups.size();i++)
        // {
        //     uni.push_back(a[groups[i][0]]);
        // }
        //     //NUMBER OF ZERO, NUMBER OF ODD, SUM OF EVEN, SUM OF ODD
        set<pair<pair<int,int>,pair<int,int>>> Subset;
        //equi(a,Subset);
        cout<<Subset.size()<<endl;
    }
    return 0;        
}
    
