#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

ll mod=1000000007;

//YE EVNE PARTITION WALE KA SUM CALCULATE KAREGA
ll evenPos(vector<ll>a,ll limit, ll ans)
{
    ll onecount=0;

    //even part calculate hoga har baar
    for(ll i=0;i<limit;i++)
    {
        if(onecount%2==0)
        {
            if(a[i]%2==0 || a[i]==1)   ans=(ans%mod+a[i]%mod)%mod;
            
            else    ans=(ans%mod+(a[i]-1)%mod)%mod;
        }

        if(a[i]==1)
            onecount++;
    }
    return ans%mod;
}
//YE ODD PARTITION WALE KA SUM CALCULATE KAREGA
ll oddpos(vector<ll>a,ll limit, ll ans)
{
     ll onecount=0;
    for(ll i=0;i<limit;i++)
    {
        if(onecount%2!=0 )
        {
            if(a[i]%2==0 || a[i]==1)   ans=(ans%mod+a[i]%mod)%mod;
                        
            else    ans=(ans%mod+(a[i]-1)%mod)%mod;
        }

        if(a[i]==1)
            onecount++;
    }
    return ans%mod;
}

void oddone(ll r, ll n, vector<ll>a,ll evensegmentSum)
{
    // IF R IS GREATER THAN N THEN SIMPLY ADD THE ODD SEGMENTS R/N TIMES + 
    // THEN TRAVERSE R%N TIMES

    //      CF  |   CA  |   CF  |   CA(CHAHE ISKA EK BHIE ELEMENT NA HO(IE. ENDING WITH 1))
    //      CF  |   CA  |   CF  |   CA
    ll ans=((r/n)*evensegmentSum)%mod;
    ll left=r%n;

    //cout<<left<<" oddsegmentSum="<<oddsegmentSum<<" evensum="<<evensegmentSum<<endl;
    ll onecount=0;
    
    cout<<evenPos(a,left,ans)<<endl;
                
}

void evenone(ll r, ll n, vector<ll>a,ll evensegmentSum, ll oddsegmentSum)
{
    //CF    |   CA  |   CF(CHAHE YE PART EKDUM ZERO HI KYUN NA HO)
    // CA   |   CF  |   CA
                
    ll oddsegmentcount=(r/n)/2;
    ll evensegmentcount=ceil(float(r/n)/2.0);

    ll ans=(evensegmentSum*evensegmentcount%mod + oddsegmentSum*oddsegmentcount%mod)%mod;
                
    ll left=r%n;

    //cout<<"OddsegmentSum="<<oddsegmentSum<<" evensum="<<evensegmentSum<<endl;
    ll onecount=0;

    //even NUMBER OF TIMES REPEAT HUA HAI... TOH EVEN SUM CALCULATE HOGA
    if((r/n)%2==0)
    {
        cout<<evenPos(a,left,ans)<<endl;
    }
    //ODD NUMBER OF TIMES REPEAT HUA TOH EVEN ODD POSITIONS COUNT HONGI
    else
    {
        cout<<oddpos(a,left,ans)<<endl;
    }
                
}


int main() 
{
    ios::sync_with_stdio(false);
    
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;

        vector<ll>a(n,0);
        for(ll i=0;i<n;i++)
            cin>>a[i];

        //PREPROCESS THE DATA... HERE ONLY.

        vector<ll>onepos;
        for(ll i=0;i<n;i++)
            if(a[i]==1)     onepos.push_back(i);

        //VARIOUS SEGMENT SUM.. ABHI TOTAL SUM HO DEKH RAHE HAI.. BAAD ME TOTAL SUM BHI DEKH 
        // SAKTE HAI

        ll oddsegmentSum=0;
        ll evensegmentSum=0;
        // vector<ll>oddseg;
        // vector<ll>evenseg;

        oddsegmentSum=oddpos(a,n,oddsegmentSum);
        evensegmentSum=evenPos(a,n,evensegmentSum);
        
        // cout<<"TEST sum="<<evensegmentSum<<" "<<oddsegmentSum<<endl;

        int oddflag=0;
        if(onepos.size()%2!=0)
            oddflag=1;
        
        ll q;
        cin>>q;
        while (q--)
        {
            ll r;
            cin>>r;
            //fcout<<"MOSHI\n";
            if(oddflag)
            {
                oddone(r,n,a,evensegmentSum);
            }
            //EVEN NUMBER OF 1s....
            else 
            {
               evenone(r,n,a,evensegmentSum, oddsegmentSum);
            }
        }
        

    }
    return 0;        
}
        
