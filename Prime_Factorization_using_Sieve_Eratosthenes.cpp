#include<bits/stdc++.h>
using namespace std; 


vector<int> sieveofEratosthenes(int N)
{
	vector<int> factors;

	for(int i=2; i<=N; i++)
	{
		while(N%i==0)
		{
		    factors.push_back(i);
			N/=i;
		}
	}
	return factors;
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