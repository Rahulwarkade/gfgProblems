#include<bits/stdc++.h>
using namespace std;


long long power(int N,int R)
{
	int M = 1000000007;
	long long ans = 1;
	while(R>0)
	{
		if((R&1)!=0)
			ans = (ans*1ll*N)%M;
		N= (N*1ll*N)%M;
		R>>=1;
	}
	return (ans%M);
}
int main()
{
	int t; 
	cin>>t; 

	while(t--)
	{
		string Nstr; 
		cin>>Nstr; 
		int N = stoi(Nstr);
		reverse(Nstr.begin(),Nstr.end());
		int R = stoi(Nstr);
		cout<<power(N,R)<<endl;
	}
}