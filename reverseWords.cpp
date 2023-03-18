#include<bits/stdc++.h>
using namespace std;

string reverseWordBF(string str)
{
	stack<string> s;
	str+=".";
	string tempstr = "";
	for(int i=0; i<str.length(); i++)
	{
		if(str[i]=='.')
		{
			s.push(tempstr);
			tempstr = "";
		}
		else tempstr += str[i];	
	}
	string ans = "";
	while(s.size()!=1)
	{
		ans += s.top()+".";
		s.pop();
	}
	ans += s.top();

	return ans;
}

string reverseWordOptimized(string& S)
{
	int left = 0; 
	int right = S.length() -1;

	string temp = "";
	string ans = "";

	while(left<=right)
	{
		char ch = S[left];
		if(ch!='.')
		{
			temp+=ch;
		}
		else if(ch=='.')
		{
			if(ans!="") ans = temp + "." + ans;
			else ans = temp;
			temp = "";
		}
		left++;
	}

	if(temp!=""){
		if(ans!="") ans = temp + "." + ans;
		else ans = temp;
	} 

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

		cout<<reverseWordOptimized(str)<<endl;
	}
}