#include<bits/stdc++.h>
using namespace std; 

vector<string> AllPossibleStringsBF(string s)
{
	int n = s.length();
	vector<string> allstr;

	for(int i=0; i<(1<<n); i++)
	{
		string temp = "";
		for(int j=0; j<n; j++)
		{
			if((i&(1<<j))!=0)
				temp.push_back(s.at(j));
		}

		if(temp!="")
		 allstr.push_back(temp);
	}
	sort(allstr.begin(),allstr.end());
	return allstr;
}

int main()
{
	int t; 
	cin>>t; 

	while(t--)
	{
		string str; 
		cin>>str;

		vector<string> all = AllPossibleStringsBF(str);

		for(auto &val : all)
			cout<<val<<endl;
	}
}