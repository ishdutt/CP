#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		int a1,a2,a3,a4,a5;
		cout<<1<<" "<<1<<" "<<2<<" "<<3<<"\n";
		cin>>a1;
		cout<<1<<" "<<1<<" "<<2<<" "<<4<<"\n";
		cin>>a2;
		cout<<1<<" "<<3<<" "<<4<<" "<<5<<"\n";
		cin>>a3;
		cout<<1<<" "<<3<<" "<<4<<" "<<6<<"\n";
		cin>>a4;
		a[5]=a1^a2^a3;
		a[6]=a1^a2^a4;
		for(int i=7;i<=n;i++){
			cout<<1<<" "<<i-2<<" "<<i-1<<" "<<i<<"\n";
			cin>>a5;
			a[i]=a[i-2]^a[i-1]^a5;
		}   
		cout<<1<<" "<<1<<" "<<n-1<<" "<<n<<"\n";
		cin>>a5;
		a[1]=a5^a[n-1]^a[n];
		cout<<1<<" "<<2<<" "<<5<<" "<<n<<"\n";
		cin>>a5;
		a[2]=a5^a[5]^a[n];
		a[3]=a1^a[1]^a[2];
		a[4]=a2^a[1]^a[2];
		cout<<2<<" ";
		for(int i=1;i<=n;i++)cout<<a[i]<<" ";
			cout<<"\n";
		cin>>a5;
	}
}