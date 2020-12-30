#include <bits/stdc++.h>
using namespace std;

int main() 
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,x,p,flag=0;
        cin>>n>>x;

        vector<int>a(n,0);

        for(int i=0;i<n;i++)
            cin>>a[i];

        vector<vector<int>>v(n,vector<int>(33,0));

        int col;
        //CONVERT NUMBER TO BINARY
        for(int i=0;i<n;i++)
        {
            p =a[i];
            col=0;
            while(p>0)
            {
                v[i][col]=p%2;
                p=p/2;
                col++;
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=32;j>=0;j--)
            {
                //get the first 1 from numbers in binary grid
                if(x>0 && v[i][j]==1)
                {
                    flag=0;
                    //ZERO Mil gaya
                    for(int k=i+1;k<n-1;k++)
                    {
                        if(v[k][j]==1)
                        {
                            flag=1;
                            v[k][j]=0;
                            v[i][j]=0;
                            x--;
                            break;
                        }
                    }
                    //0 NAI MILA DOWN THE LINE
                    if(flag==0 &&x>0 && i!= n-1)
                    {
                        v[i][j]=0;
                        v[n-1][j]^=1;
                        x--;
                    }
                }
            }
        }

        //convert number back to Decimal
        for(int i=0;i<n;i++)
        {
            int sum=0;
            string num="";

            for(int j=0;j<33;j++)
            {
                num+=to_string(v[i][j]);
                //cout<<v[i][j];
                // sum += v[i][j]*(1<<j);
            }    
            // cout<<endl;
            
            reverse(num.begin(),num.end());

            // cout<<"HELLO="<<num<<endl;

            //string num(v[i].begin(),v[i].end());
            //cout<<"TEST="<<num<<endl;
            bitset<33> b(num);
            
            a[i]=sum;
            

            // cout<<"TEST="<<a[i]<<endl;
            int temp=b.to_ulong();

            a[i]=temp;

            // cout<<temp<<endl;
            // if(a[i]!=temp)  cout<<"MOHSI"<<endl;
        }

        //WHEN ONLY 2 NUMBERS AND IN CASE ALL OF THEM BECOME ZERO
        if(x%2==1 && n == 2)
        {
            a[n-1]^=1;
            a[n-2]^=1;
        }



        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}