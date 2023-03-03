#include<bits/stdc++.h>
using namespace std;

bool rotatedStringBF(string s1,string s2)
{
	int n = s1.size();
	int m = s2.length();

	if(n!=m) return false;
	if((n==1 && m==1)&& (s1.at(0) == s2.at(0)))
		return true;

	s1 += s1;
	int j= 0,i = 0;
	while(i+1<s1.size() && (s2.at(j)!=s1.at(i) || s2.at(j+1)!=s1.at(i+1)))
	{
		i++;
	}
	for(; j<m; j++)
	{
		if(s2.at(j)!=s1.at(i))
			return false;
		else
			i++;
	}

	return true;

}

int main()
{
	string str1,str2;
	cin>>str1>>str2;

	cout<<rotatedStringBF(str1,str2)<<endl;
}