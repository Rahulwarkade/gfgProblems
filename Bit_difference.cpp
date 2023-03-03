#include<bits/stdc++.h>
using namespace std; 

int countBitsFlip(int a,int b)
{
	int flip = 0;
	for(int i=0; i<=31; i++)
	{
		if((a&1)!=(b&1))
			flip++;
		a>>=1;
		b>>=1;
	}

	return flip;
}

int main()
{
	int t; 
	cin>>t; 

	while(t--)
	{
		int a,b;
		cin>>a>>b;

		cout<<countBitsFlip(a,b)<<endl;
	}
}