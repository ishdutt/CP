#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

//NOTE: TASK3: =100,000
//TASK 2: >70,000
//LIMIT=100,000
int main() 
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        //IF N==1 ?

        //IF POWER OF 2 THEN -1
        set<int> poweroftwo={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};

        if(poweroftwo.find(n)!=poweroftwo.end())
        {
            cout<<"-1"<<endl;
            continue;
        }

        //NOT POWER OF TWO
        //CONTAINS THE SEQUENCE;
        //vector<int>ans;
        int ans[n];
        // ans.push_back(2);
        // ans.push_back(3);
        // ans.push_back(1);
        // ans[0]=2;
        // ans[1]=3;
        // ans[2]=1;
        //PUT ODD CHARS AT THE END OF EACH BOUNDRY OF NEW 2 POWER
        cout<<"2 3 1 ";
        //int prevpoweroftwo=2;
        int i=3;
        while(i<n)
        {
            if(poweroftwo.find(i+1)!=poweroftwo.end())
            {
                cout<<i+2<<" "<<i+1<<" ";
                // ans[i]=i+2;
                // ans[i+1]=i+1;
                // ans.push_back(i+1);
                // ans.push_back(i);
                i+=2;
            }
            else
            {
                cout<<i+1<<" ";
                // ans[i]=i+1;
                i++;
            }
                
                // ans.push_back(i);
        }

        
        //PRINT
        // for(int i=0;i<n;i++)
        //     cout<<ans[i]<<" ";
        
        cout<<endl;

    }
    return 0;        
}
        
