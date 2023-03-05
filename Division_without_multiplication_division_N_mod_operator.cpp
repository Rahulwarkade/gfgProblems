#include<bits/stdc++.h>
using namespace std;

long long divideBF(int dividend,int divisor)
{
	int sign = ((dividend<0) ^ (divisor<0)) ? -1: +1;
	long long quotient = 0;
	dividend = abs(dividend);
	divisor = abs(divisor);
	while(dividend>=divisor)
	{
		dividend-=divisor;
		quotient++;
	}
	quotient*=sign;
	return quotient;
}
long long dividePro(long long dividend,long long divisor)
{
	int sign = ((dividend<0) ^ (divisor<0)) ? -1: +1;
	dividend = abs(dividend);
	divisor = abs(divisor);
	long long temp = 0,quotient = 0;

	for(int i=31; i>=0; i--)
	{
		if((temp+(divisor<<i))<=dividend)
		{
			temp += (divisor<<i);
			quotient |= (1LL<<i);
		}
	}

	quotient*=sign;
	return quotient;
}

// works on power of 2 only
long long divideOp(long long dividend,long long divisor)
{
	int sign = ((dividend<0) ^ (divisor<0)) ? -1: +1;

	dividend = abs(dividend);
	divisor = abs(divisor);
	int pos = log2(divisor);
	long long quotient = (dividend>>pos);
	quotient *= sign;

	return quotient;
}
int main()
{
	int t; 
	cin>>t; 

	while(t--)
	{
		int dividend,divisor;

		cin>>dividend>>divisor;

		cout<<divideOp(dividend,divisor)<<endl;
	}
}