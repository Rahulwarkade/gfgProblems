#include<bits/stdc++.h>
using namespace std;

string longestcomnPrefix(string arr[],int N)
{
	string ans = arr[0];
	int mincomn = INT_MAX;
	int comn;
	for(int i=1; i<N; i++)
	{
		comn =-1;
		string temp = arr[i];
		for(int j=0; j<arr[i].length(); j++)
		{
			if(ans[j]==temp[j])
				comn++;
			else if(ans[j]!=temp[j])
				break;
		}
		comn = min(mincomn,comn);
		ans = ans.substr(0,comn+1);
	}
	if(comn==-1) ans = "-1";
	return ans;
}
int main()
{
	int n; 
	cin>>n; 

	string arr[] = {"geeksforgeeks","geeks","geek","geezer"};

	// for(int i=0; i<n; i++)
	// {
	// 	cin>>arr[i];
	// }

	cout<<longestcomnPrefix(arr,n)<<endl;
}