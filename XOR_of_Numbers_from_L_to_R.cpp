#include<bits/stdc++.h>
using namespace std; 

int xr(int n)
{
	int mod = n%4;

	switch(mod)
	{
	case 0: 
		return n;
		break;
	case 1:
		return 1;
		break;
	case 2:
		return n+1;
		break;
	default :
		return 0;
	}
	return 0;
}
int findXOR(int l,int r)
{
	return (xr(l-1)^xr(r));
}
int main()
{
	int t; 
	cin>>t; 

	while(t--)
	{
		int l,r;

		cin>>l>>r;

		cout<<findXOR(l,r)<<endl;
	}
}