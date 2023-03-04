#include<bits/stdc++.h>
using namespace std;


class Solution{

	public :
	int findX(int y)
	{
		int x = -1;
		while(y)
		{
			x++;
			y>>=1;
		}
		return x;
	}
	int countSetBits(int n)
	{
		if(n== 1)
			return 1;
		if(n==0)
			return 0;
		int pw = n;
		int ans = 0;
		while((pw&pw-1)!=0)
		{
			pw--;
		}
	    int x = findX(pw);

	    ans = (pow(2,x-1)*x)+((n-(pow(2,x))+1))+countSetBits(n-(pow(2,x)));

	    return ans;
	}
};
	int countSetBitsOp(int n)
	{
		if(n== 1)
			return 1;
		if(n==0)
			return 0;
		int ans = 0;

	    int x = (int)log2(n);

	    ans = (pow(2,x-1)*x)+((n-(pow(2,x))+1))+countSetBits(n-(pow(2,x)));

	    return ans;
	}
int main()
{
	int t; 
	cin>>t; 


	while(t--)
	{
		int N; 
		cin>>N;

	Solution object;
	cout<<object.countSetBits(N)<<endl;
	}
}