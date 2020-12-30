#include <stdio.h>
typedef long long      ll;

void solve()
{
    ll n;
    scanf("%lld",&n);

    ll result=n&(n-1);
    //printf("TEST %lld\n",n&(n-1));
    if(result==0)
    {
        printf("-1\n");
        return ;
    }

    // ll ans[n];
    // ans[0]=2;
    // ans[1]=3;
    // ans[2]=1;
    printf("2 3 1 ");
    ll prevpoweroftwo=2;
    for(ll i=3;i<n;i++)
    {
        if(i+1==prevpoweroftwo*2)
        {
            prevpoweroftwo=i+1;
            printf("%lld %lld ",i+2,i+1);
            // ans[i]=i+2;
            // ans[i+1]=i+1;
            i++;
        }
        else
            printf("%lld ",i+1);
            //ans[i]=i+1;
                // ans.push_back(i);
    }

    // for(ll i=0;i<n;i++)
    // {
    //     printf("%lld ",ans[i]);  
    // }
        


    printf("\n");
    return ;

}

int main() 
{    
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
    
}
