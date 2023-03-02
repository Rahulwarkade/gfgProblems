#include<bits/stdc++.h>
using namespace std;

bool anagramBF(string a,string b)
{
	int n = a.length();
	int m = b.length();
	if(n!=m)
		return false;
	map<char,int> freq1;
	map<char,int> freq2;

	for(int i=0; i<n; i++)
	{
		freq1[a.at(i)]++;
		freq2[b.at(i)]++;
	}

	for(int i=0; i<m; i++)
	{
		if(freq2[b.at(i)]!=freq1[b.at(i)])
			return false;
	}
	return true;	
}
bool anagramOptimized(string a,string b)
{
	int n = a.length();
	int m = b.length();
	if(n!=m)
		return false;

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	for(int i=0; i<n; i++)
	{
		if(a.at(i)!=b.at(i))
			return false;
	}
	return true;	
}

bool anagramOptimal(string a,string b)
{
	int n = a.length();
	int m = b.length();
	if(n!=m)
		return false;

	int arr[26] = {0};
	for(int i=0; i<n; i++)
	{
		arr[a.at(i)-'a']++;
	}
	for(int i=0; i<m; i++)
	{
		arr[b.at(i)-'a']--;
	}

	for(int i=0; i<26; i++)
	{
		if(arr[i]!=0)
			return false;
	}
	return true;	
}

int main()
{
	string str1,str2;
	cin>>str1>>str2;

	if(anagramOptimal(str1,str2))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}