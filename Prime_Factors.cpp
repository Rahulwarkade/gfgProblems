#include<bits/stdc++.h>
using namespace std;

vector<int> primeFactor(int N)
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

		vector<int> factors = primeFactor(N);

		for(auto val : factors)
			cout<<val<<" ";
		cout<<endl;
	}
}