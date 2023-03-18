#include<bits/stdc++.h>
using namespace std;

int setBit(int n)
{	
	int num = n;
	int i = 0;
	while(num)
	{
		if((num&1)==0)
		{
			n|=(1<<i);
			break;
		}
		i++;
		num>>=1;
	}
	return n;
}

int main()
{
	int t; 
	cin>>t; 

	while(t--)
	{
		int n; 
		cin>>n; 

		cout<<setBit(n)<<endl;
	}
}