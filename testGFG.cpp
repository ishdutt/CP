// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
#include <unordered_map> 
using namespace std; 

 // } Driver Code Ends


//User function Template for C++

int digSum(int n) 
{  
    int sum = 0; 
    while (n != 0) 
    { 
        sum = sum + n % 10; 
        n = n/10; 
    }
    return sum;
};

int RulingPair(vector<int> a, int n) 
{
    // code here
    unordered_map<int,vector<int>>m;
    vector<int>dsum;
    for(int i=0;i<n;i++)
    {
        int val=digSum(a[i]);
        m[val].push_back(a[i]);
    }
    
    
    int ans=0;
    for(auto it:m)
    {
        int term1=0;
        int term2=0;
        if(it.second.size()>1)
        {
            
            for(int i=0;i<it.second.size();i++)
            {
                if(term1<it.second[i])
                    term1=it.second[i];
            }
            
            for(int i=0;i<it.second.size();i++)
            {
                if(term2<it.second[i] && term1!=it.second[i])
                    term2=it.second[i];
            }
        }
        ans=max(ans,term1+term2);
    }
    return ans;
}

// { Driver Code Starts.
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		cout << RulingPair(arr,n)<<"\n";
	}
	return 0; 
} 

  // } Driver Code Ends