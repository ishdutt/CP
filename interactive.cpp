#include<iostream>
typedef long long int ll;
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int n,k; ll temp;
        cin>>n;
        cout<<"1 1 3 4"<<endl;
        ll x; cin>>x;
        cout<<"1 2 3 4"<<endl;
        ll y; cin>>y;
        ll a=x^y;
        ll m[n+1];
        int p=5,q=6,r=7;
       cout<<"1 1 2 5"<<endl;
       cin>>temp;
       m[5]=a^temp;
       cout<<"1 1 2 6"<<endl;
       cin>>temp;
       m[6]=a^temp;
        for(int i=7; i<=n; i++)
        {
            cout<<"1 "<<(i-2)<<" "<<(i-1)<<" "<<i<<endl;
            cin>>temp;
            m[i]=(m[i-1]^m[i-2])^temp;
        }
        cout<<"1 3 "<<n<<" "<<(n-1)<<endl;
        cin>>temp;
        m[3]=temp^(m[n]^m[n-1]);
        cout<<"1 4 5 "<<n<<endl;
        cin>>temp;
        m[4]=temp^(m[5]^m[n]);
        m[1]=x^m[3]^m[4];
        m[2]=y^m[3]^m[4];
        cout<<"2 ";
        for(int i=1; i<=n; i++)
            cout<<m[i]<<" ";
        cout<<endl;
        cin>>k;
    }
}