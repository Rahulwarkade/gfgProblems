#include<bits/stdc++.h>
using namespace std;

int romanToInt(string str)
{
	int result;

	map<char,int> mp;

	mp['I'] = 1;
	mp['V'] = 5;
	mp['X'] = 10;
	mp['L'] = 50;
	mp['C'] = 100;
	mp['D'] = 500;
	mp['M'] = 100;

	char ch = str.at(str.length()-1);
	result = mp[ch];
	for(int i=str.length()-2; i>=0; i--)
	{
		if(mp[str.at(i)]<mp[ch])
		{
			result -= mp[str.at(i)];
		}
		else
		{
			result += mp[str.at(i)];
		}
		ch = str.at(i);
	}

	return result;
}
int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		string str;
		cin>>str;

		cout<<romanToInt(str)<<endl;
	}
}