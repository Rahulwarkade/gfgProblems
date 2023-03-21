#include<bits/stdc++.h>
using namespace std; 


vector<int> sieveofEratosthenes(int N)
{
	vector<int> allprime;
	vector<bool> is_prime(N+1,1);

	is_prime[0] = is_prime[1] = 0;
	for(int i=2; i<=N; i++)
	{
		if(is_prime[i])
		{
			allprime.push_back(i);
			for(int j= i*i; j<=N;  j+=i)
			{
				is_prime[j] = 0;
			}
		}
	}

	return allprime;
}
int main()
{
	int t; 
	cin>>t;

	while(t--)
	{
		int N; 
		cin>>N;

		vector<int> allprime = sieveofEratosthenes(N);

		for(auto val : allprime)
			cout<<val<<" ";
	}
}