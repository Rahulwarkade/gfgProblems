#include<bits/stdc++.h>
using namespace std;

string outerMostParentheses(string s)
{
	stack<char> status;
	string res = "";

	for(int i=0; i<s.length(); i++)
	{
		if(s[i]=='(')
		{
			if(status.size()>=1)
			{
				res.push_back(s[i]);
			}
			status.push(s[i]);
		}
		else
		{
			if(status.size()>1)
			{
				res.push_back(s[i]);
			}
			status.pop();
		}
	}

	return res;
}
int main()
{
	int t;
	cin>>t;
	while(t--){		
		string str;
		cin>>str;

		cout<<outerMostParentheses(str)<<endl;
	}
}