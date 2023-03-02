#include<bits/stdc++.h>
using namespace std;

void print_divisors(int n)
{
	set<int> ascending;

	for(int i = 1; i*i<=n; i++)
	{
		if(n%i==0)
		{
			cout<<i<<" ";
			int quotient = n/i;
			if(quotient!=i)
				ascending.insert(quotient);
		}
	}

	if(ascending.size()>0){
		for(auto val : ascending)
			cout<<val<<" ";
	}
}
int main()
{
	int t; 
	cin>>t;

	while(t--)
	{
		int n; 
		cin>>n; 

		print_divisors(n);
	}
}
