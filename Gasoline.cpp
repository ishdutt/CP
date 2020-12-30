#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

struct Item  
{ 
    ll value, weight; 
  
    // Constructor 
    Item(ll value, ll weight) 
        : value(value) 
        , weight(weight) 
    { 
    } 
}; 
  
// Comparison function to sort Item according to val/weight 
// ratio 
bool cmp(struct Item a, struct Item b) 
{ 
    double r1 = ( double)a.value / ( double)a.weight; 
    double r2 = ( double)b.value / ( double)b.weight; 
    return r1 < r2; 
} 
  
double fractionalKnapsack(ll W, vector<Item> arr, ll n) 
{ 
    sort(arr.begin(), arr.end(), cmp);   
  
    ll curWeight = 0;
    double finalvalue = 0.0; 
  
    for (ll i = 0; i < n; i++)  
    { 
        if (curWeight + arr[i].weight <= W)  
        { 
            curWeight += arr[i].weight; 
            finalvalue += ( double)arr[i].value; 
        } 

        else 
        { 
            ll remain = W - curWeight; 
            finalvalue += ( double)arr[i].value * (( double)remain / ( double)arr[i].weight); 
            break; 
        } 
    } 
    // double temp=finalvalue;
    // cout<<"TEST="<<temp<<endl;
    return finalvalue; 
} 
  

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
        vector<ll> fuel(n,0);
        //ARRAY
        for(ll i=0;i<n;i++)
            cin>>fuel[i];

        vector<ll> cost(n,0);
        //COST ARRAY
        for(ll i=0;i<n;i++)
            cin>>cost[i];


        for(ll i=0;i<n;i++)
            cost[i]*=fuel[i];

        vector<Item>arr;
        for(ll i=0;i<n;i++)
            arr.push_back(Item(cost[i],fuel[i]));

        double res=fractionalKnapsack(n, arr, n);

       
        printf("%lli\n",(ll)res);


        // ll ans= (ll)fractionalKnapsack(n, arr, n);

        // cout<<ans<<endl;
    }
}
    
