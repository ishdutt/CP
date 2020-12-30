#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    vector<string>s{"01110","0111000","1001001011101","1001001011100","1001000111101"};
    
    vector<vector<int>>data(s.size(),vector<int>(5,0));
    for(int i=0;i<s.size();i++)
    {
        //count number of 0s  , 1s and continous 0s and make an array for that;
        cout<<"TEST="<<i<<endl;
        vector<int>freq;
        ll onecount=0;
        ll zerocount=0;

        ll oddsum=0;
        ll evensum=0;
        bool isodd=true;

        for(int j=0;j<s[i].size();j++)
        {
            //FIXME: ONE COUNT ME PANGA HO RHA HAI
            //cout<<"1 ki testing="<<j<<" "<<s[i][j]<<endl;
            if(s[i][j]=='1')   onecount++;

            else
            {
                ll streak=0;
                while (s[i][j]=='0')
                {
                    streak++;
                    j++;
                }
                j--;
                zerocount+=streak;
                freq.push_back(streak);

                //number of elements even then the last element was added to odd place
                if(freq.size()%2==0)  oddsum+=streak;

                else    evensum+=streak;  
            }
        }
         data[i][0]=zerocount;
        data[i][1]=onecount;
        data[i][2]=oddsum;
        data[i][3]=evensum;
        data[i][4]=freq.size();
        //data i= for index of string vectors  j=0->no. of zero,1->no. of ones,2->odd sum, 3-> even sum, 4->freq array size
        cout<<s[i]<<" "<<zerocount<<" "<<onecount<<" "<<oddsum<<" "<<evensum<<" "<<freq.size()<<endl;
        cout<<s[i]<<" "<<data[i][0]<<" "<<data[i][1]<<" "<<data[i][2]<<" "<<data[i][3]<<" "<<data[i][4]<<endl;
    }
    return 0;        
}
    
