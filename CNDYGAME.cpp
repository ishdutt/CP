#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

ll mod=1000000007;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

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

        int onepresent=0;
        ll oneindex=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)
            {
                onepresent=1;
                oneindex=i;
                break;
            }
        }

        //sum of all the numbers
        ll sum=0;
        ll sumtillone=0;
        ll flag=0;

        vector<ll>presum(n,0);

        // if(a[0]%2==0)
        //     presum[0]=a[0];
        

        //calculate prefix sum
        // for(ll i=1;i<n;i++)
        // {
        //     presum[i]=(presum[i-1]+a[i])%mod;
        // }

        //ARRAY ELEMENTS TO BE MADE EVEN FOR ALL THE CASE ;)
        for(ll i=0;i<n;i++)
        {
            if(a[i]==1)
                flag=1;
            
            // last element is always odd!!!
            if(i==n-1)
            {
                if(a[n-1]%2==0)
                {
                    sum=(sum +(a[n-1]-1))%mod;
                    
                    sumtillone=(sumtillone +(a[i]-1))%mod;
                } 

                else
                {
                    sum=(sum + a[i] )%mod;
                    sumtillone=(sumtillone + a[i])%mod;
                }    
            }

            else if(a[i]%2==0 || a[i]==1)
            {
                sum=(sum + a[i])%mod;
                if(flag==0)
                    sumtillone=(sumtillone + a[i])%mod;
            }
            else
            {
                sum=(sum + (a[i]-1) )%mod;

                if(flag==0)
                    sumtillone=(sumtillone + a[i])%mod;
            }

            presum[i]=sum;
        }

        // cout<<"PRESUM ARRAY=\n";
        // for(int i=0;i<n;i++)
        //     cout<<presum[i]<<" ";
        // cout<<endl;
        
       
        ll q;
        cin>>q;
        while (q--)
        {
            ll r;
            cin>>r;
            if(onepresent==0 || a[n-1]==1)
            {
                //LAST ELEMENT IS ALWAYS AS IT IS
                //LAST ELEMENT IS ALWAYS ODD SO TAKE APPROPRIATE CARE
                

                ll ans=0;
                if(a[n-1]%2==0)     ans=((r%mod/n)*(sum))%mod;

                
                
                //WHEN ODD THEN ANS IS SAME FOR R/N TIMES
                else    ans=((r%mod/n)*(sum))%mod;

                //cout<<"TEST="<<r<<" "<<n<<" "<<(r/n)*sum<<endl;
                ll left=r%n;
                
                if(left==0)
                {
                    //1 IS ADDED AS IN THE LAST ROUND.. WE WILL TAKE THE NUMBER AS IT IS..IE WHEN LAST ELEMENT IS ODD THEN 
                    // THE SAME ELEMMENT WAS TAKEN .. SO NO CHANGE.. BUT IN EVEN CASE.. +1 IS ADDED TO MAKE IT EQUAL TO THE NUMBER
                    if(a[n-1]%2==0)
                        ans= (ans+1)%mod;
                    // WHEN ODD THEN NO CHANGE
                    else    ans = ans%mod;
                }    

                else
                {
                    //take the last number as it is

                    if(left==1)     ans = (ans + (a[left-1]))%mod;

                    else    ans= (ans +presum[left-2] +a[left-1] )%mod;
                }        

                cout<<ans<<endl;
            }

            else if(a[0]==1)
            {
                //sirf one hi milega chef ko ;(
                //cout<<"MO "<<r<<" "<<n<<" "<<ceil(r/n)<<endl;
                ll ans=ceil(float(r%mod)/float(n));

                ll left=r%n;
                
                //IF LEFT IS ONE THEN CHEFINA WILL TRY TO KEEP EVEN THE LAST BITE WITH HER
                // KEEPING THE LAST ONE WITH HER(EG. IN R=6(FOR N=5) THEN SHE
                // WILL CHOOSE OPTIMALLY) AND SELECT ODD AT THE LAST ELEMENT SUCH THAT EVEN THE  LAST ONE 
                // IS CAPTURED BY HER
                if(left==1)
                {
                    // FIRST ELEMENT IS ALWAYS FOR CHEF
                    if(ans==1)  ans=ans%mod;

                    else    ans=((ans-1)%mod+mod)%mod;
                }
                    
                
                else        ans=ans%mod;
                cout<<ans<<endl;
            }
            //ONE IS SOMEWHERE MIDDLE
            else
            {

                //CHECK FOR ODD AND EVEN OF A[N-1](ALREADY HANDLED ;) AND A[1S INDEX - 1]
                if(a[oneindex-1]%2!=0)
                {
                    //1 pe chefina ko lana hai.. toh oneindex-1 pe hamesha odd hi lenge
                    //A[ONEINDEX-1] KO ODD LENGE(EXPECTED +1) AND 1 CHEFINA KE PAAS HOGA.. SO +1 -1=0 CHANGE
                    ll ans=((r%mod/n)*(sum))%mod;
                    //cout<<"MOSHI "<<ans<<endl;
                    ll left=r%n;
                    if(left==0)
                    {
                        //1 IS ADDED AS IN THE LAST ROUND.. WE WILL TAKE THE NUMBER AS IT IS..IE WHEN LAST ELEMENT IS ODD THEN 
                        // THE SAME ELEMMENT WAS TAKEN .. SO NO CHANGE.. BUT IN EVEN CASE.. +1 IS ADDED TO MAKE IT EQUAL TO THE NUMBER
                        if(a[n-1]%2==0)
                            ans= (ans+1)%mod;
                        // WHEN ODD THEN NO CHANGE
                        else    ans = ans%mod;
                    }    

                    else
                    {
                        //left ek jaada hoga... due to 0 indexing
                        //TAKE PRESUM TILL LEFT-1 AND ADD THE LAST ELEMENT AS IT IS
                        //PRESUM IS DECREASED BY 1 AS 1 WILL GOTO CHEFINA BUT SINCE IN PRESUM... ODD WILL BE CONVERTED TO EVEN
                        // BUT IN ONEINDEX-1 IT MUST BE ODD SO +1.. HENCE NO CHANGE

                        
                        //here no negative one.. all the elements till left-2 is counted and then simply add the last element 
                        // as it is
                        if(left==1)     ans = (ans + (a[left-1]))%mod;

                        else        ans= (ans + (presum[left-2] + a[left-1])%mod)%mod;
                        
                        
                    }        

                    cout<<ans<<endl;
                }

                else
                {
                    //1 pe chefina ko lana hai.. toh oneindex-1 pe hamesha odd hi lenge
                    //A[ONEINDEX-1] KO ODD LENGE(EXPECTED -1 compared to presum and sum)
                    // AND 1 CHEFINA KE PAAS HOGA.. SO -1 -1= -2 CHANGE
                    //FIXME:
                    ll ans=((r%mod/n)*(sum-2))%mod;

                    ll left=r%n;

                    if(left==0)
                    {
                        //1 IS ADDED AS IN THE LAST ROUND.. WE WILL TAKE THE NUMBER AS IT IS..IE WHEN LAST ELEMENT IS ODD THEN 
                        // THE SAME ELEMMENT WAS TAKEN .. SO NO CHANGE.. BUT IN EVEN CASE.. +1 IS ADDED TO MAKE IT EQUAL TO THE NUMBER
                        //cout<<"TEST="<<ans<<endl;
                        if(a[n-1]%2==0)
                            ans= (ans+1)%mod;
                        // WHEN ODD THEN NO CHANGE
                        else    ans = ans%mod;
                    }    

                    else
                    {
                        
                        //left ek jaada hoga... due to 0 indexing
                        if(left-1<=oneindex)
                        {
                            //cout<<left<<endl;
                            if(left==1)   ans = (ans + (a[left-1]))%mod;

                            else    ans = (ans + (presum[left-2]+a[left-1])%mod)%mod;
                        }
                            
                        
                        else
                        {
                            //1 WILL GOTO CHEFINA AND THE ONEINDEX-1 MUST BE ODD SO IT SHOULD BE CONVERTED TO ODD AND NOT EVEN 
                            //cout<<"MOSHI KOGORO\n";
                            ans = (ans + (presum[left-2] -2 + a[left-1])%mod)%mod;
                        }
                        
                    }        

                    cout<<ans<<endl;

                }
                
            }
            
        }
        

    }
    return 0;        
}
        
