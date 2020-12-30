// CPP program to answer queries for count of 
// primes in given range. 
#include <bits/stdc++.h> 
using namespace std; 

const long long MAX = 5000000; 

// prefix[i] is going to store count of primes 
// till i (including i). 
long long int prefix[MAX + 1]; 

void buildPrefix() 
{ 
    cout<<"MOSIH\n";
	// Create a boolean array "prime[0..n]". A 
	// value in prime[i] will finally be false 
	// if i is Not a prime, else true. 
	bool prime[MAX + 1]; 
	memset(prime, true, sizeof(prime)); 

	for (long long int p = 2; p * p <= MAX; p++) { 

		// If prime[p] is not changed, then 
		// it is a prime 
		if (prime[p] == true) { 

			// Update all multiples of p 
			for (long long int i = p * 2; i <= MAX; i += p) 
				prime[i] = false; 
		} 
	} 

	// Build prefix array 
	prefix[0] = prefix[1] = 0; 
	for (long long int p = 2; p <= MAX; p++) { 
		prefix[p] = prefix[p - 1]; 
		if (prime[p]) 
			prefix[p]++; 
	} 
} 

// Returns count of primes in range from L to 
// R (both inclusive). 
long long int query(long long int L, long long int R) 
{ 
	return prefix[R] - prefix[L - 1]; 
} 

// Driver code 
int main() 
{ 
	buildPrefix(); 

	// long long int L = 5, R = 10; 
	// cout << query(L, R) << endl; 

	long long L = 1;
    long long R = 4000000; 
	cout << query(L, R) << endl; 

	return 0; 
} 
