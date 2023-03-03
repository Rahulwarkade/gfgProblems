#include<bits/stdc++.h>
using namespace std;

int Atoi(string str)
{
	int i = 0;
	char ch = str[i];
	int sign = 1;
	if(ch=='-'){
		sign = -1;
		i++;
	}
	int ans = 0;
	for( ; i<str.length(); i++)
	{
		ch = str[i];
		int n;
		if('0'<=ch && ch<='9'){
			n = ch - '0';
			ans = ans*10+ n;
		}
		else
			return -1;
	}
	ans *= sign;
	return ans;
}

int main()
{
	int t; 
	cin>>t;

	while(t--)
	{
		string str; 
		cin>>str;

		cout<<Atoi(str)<<endl;
	}
}