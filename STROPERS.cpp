#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

void equi(vector<string>&s , vector<vector<int>> &data)
{
    for(int i=0;i<s.size();i++)
    {
        //count number of 0s  , 1s and continous 0s and make an array for that;
        //cout<<"TEST="<<i<<endl;
        vector<int>freq;
        int onecount=0;
        int zerocount=0;

        int oddsum=0;
        int evensum=0;
        bool isodd=true;

        for(int j=0;j<s[i].size();j++)
        {
            //FIXME: ONE COUNT ME PANGA HO RHA HAI
            //cout<<"1 ki testing="<<j<<" "<<s[i][j]<<endl;
            if(s[i][j]=='1')   onecount++;

            else
            {
                int streak=0;
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
        //cout<<s[i]<<" "<<zerocount<<" "<<onecount<<" "<<oddsum<<" "<<evensum<<" "<<freq.size()<<endl;
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
        
        vector<string>a;

        for(int i=0;i<=s.size();i++)
        {
            for(int j=i+1;j<=s.size();j++)
            {
                string temp(s.begin()+i,s.begin()+j);
                a.push_back(temp);
            }
        }
        // sort( a.begin(), a.end() );
        // a.erase( unique( a.begin(), a.end() ), a.end() );

        // unordered_set<string>stringset(a.begin(),a.end());
        
        vector<string>duplicate(a.begin(),a.end());

        // //vector<vector<int>>data(duplicate.size(),vector<int>(5,0));

        
        // // vector<string>duplicate(a.begin(),a.end());

        // // for(int i=0;i<duplicate.size();i++)
        // //     cout<<duplicate[i]<<endl;
        
        // //cout<<"TEST="<<duplicate.size()<<endl;

        vector<vector<int>>data(duplicate.size(),vector<int>(5,0));

        // //calculating info
        equi(duplicate,data);

        int equivalentString=0;

        //j=0->no. of zero,1->no. of ones,2->odd sum, 3-> even sum, 4->freq array size
        for(int i=0;i<duplicate.size();i++)
        {
            for(int j=i+1;j<duplicate.size();j++)
            {
                //REVERSE AND NUMBER OF 1S EVEN IN TOTAL
                if(data[i][1]==data[j][1] && data[j][1]%2==0)
                {
                    string temp= string(duplicate[i].rbegin(),duplicate[i].rend());
                    if(temp==duplicate[j])
                    {
                        equivalentString++;
                        continue;
                    }
                }
                if( data[i][0]==data[j][0] && data[i][1]==data[j][1] && data[i][1]!=1 && data[i][1]!=2)
                {
                    //if Complement hai...Then not equivalent
                    

                    if(data[i][2]==data[j][2] && data[i][3]==data[j][3] && data[i][4]!=1)   equivalentString++;

                    else if(data[i][4]!=data[j][4])   equivalentString++;    
                }
            }
        }
        cout<<duplicate.size()-equivalentString<<endl;

    }
    return 0;        
}
    
