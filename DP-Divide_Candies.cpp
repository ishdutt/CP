#include<bits/stdc++.h>
using namespace std;
typedef long long      ll;


ll getdiff(vector<ll>&a,ll sum,vector<vector<ll>>&dp)
{
    for(ll i=0;i<a.size()+1;i++)
    {
        for(ll j=0;j<sum+1;j++)
        {
            if(j==0)    dp[i][j]=1;

            else if(i==0)   dp[i][j]=0;

            else
            {
                if(a[i-1]>j)   dp[i][j]= dp[i-1][j];

                else    dp[i][j]= dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
            
        }
    }


    // NOW WE CHECK ALL POSSIBLE SUM.. AND CHECK THE DIFF FOR THE CORRESPONDING SUM VALUE
    ll ans=LLONG_MAX;
    for(ll i=0;i<(sum/2)+1;i++)
    {
        if(dp[a.size()][i]==1)
        {   
            //IF ABOVE CONDITION IS TRUE THEN THAT SUM IS POSSIBLE..i.e i IS POOSIBLE
            ans=min(ans,abs(sum-2*i));
        }
    }

    
    // YE DIFFERNCE DE RHA HAI.. TEKO SUM CHAHIYE
    return ans;
}


  
void display(vector<ll>& v) 
{ 
    for (ll i = 0; i < v.size(); ++i) 
        cout<<v[i]<<" "; 
    cout<<"\n";
} 

void printSubsetsRec(vector<ll> &arr, ll i, ll sum, vector<ll>& p,vector<vector<ll>>&dp) 
{ 
    //cout<<i<<" sum="<<sum<<endl;
    if (i == 0 && sum != 0 && dp[0][sum]) 
    { 
        //cout<<"CO"<<endl;
        p[i-1]=1;
        display(p); 
        return; 
    } 
  
    else if (i == 0 && sum == 0) 
    { 
        //cout<<"MOSHI"<<endl;
        display(p); 
        return; 
    } 
 
    if (dp[i-1][sum]) 
        printSubsetsRec(arr, i-1, sum, p,dp); 
    
  
    else if (sum >= arr[i-1] && dp[i-1][sum-arr[i-1]]) 
    { 
        p[i-1]=1; 
        printSubsetsRec(arr, i-1, sum-arr[i-1], p,dp); 
    } 
} 
  
void check(vector<ll>&a, ll sum)
{
    vector<vector<ll>>dp(a.size()+1, vector<ll> (sum+1, 0));
    for(ll i=0;i<a.size()+1;i++)
    {
        for(ll j=0;j<sum+1;j++)
        {
            if(j==0)    dp[i][j]=1;

            else if(i==0)   dp[i][j]=0;
            
            else
            {
                if(a[i-1]>j)    dp[i][j]=dp[i-1][j];

                else    dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
        }
    }

    // cout<<"LEAVING FROM CHECK\n";
    vector<ll> p(a.size(),0);
    printSubsetsRec(a, a.size(), sum, p,dp);
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    ll k;
    cin>>k>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vector<ll>a;
        for(ll i=1;i<n+1;i++)
            a.push_back(pow(i,k));
        
        ll sum=0;

        for(ll i=0;i<a.size();i++)     sum+=a[i];

        vector<vector<ll>>dp(a.size()+1, vector<ll> (sum+1, -1));
        ll difference= getdiff(a,sum,dp);
        ll reqsum= (sum-difference)/2;
        cout<<difference<<endl;
        //printAllSubsets(a,n,reqsum);

        //cout<<"TEST "<<reqsum<<endl;
        vector<ll>p;
        check(a,reqsum);

    }
    return 0; 
}