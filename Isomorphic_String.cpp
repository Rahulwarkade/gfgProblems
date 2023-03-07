#include<bits/stdc++.h>
using namespace std;

bool isomorphicBF(string str1,string str2)
{
	int n = str1.length();
	int m = str2.length();
	set<char> s1;
    set<char> s2;
	if(n!=m)
		return false;
	char pmaping[26];
	char p1maping[26];
	
	// for(int i=0; i<n; i++)
    // 	s1.insert(str1[i]);
    	    
   	// for(int i=0; i<m; i++)
    // 	s2.insert(str2[i]);
    	   
    // if(s1.size()!= s2.size())
    // 	return false;
	for(int i=0; i<26; i++){
		pmaping[i] = ' ';
		p1maping[i] = ' ';
	}

	for(int i=0; i<n; i++)
	{
		if(pmaping[str1[i]-'a']==' ')
		{
			pmaping[str1[i]-'a'] = str2[i];	
		}
		else if (pmaping[str1[i]-'a']!=str2[i])
		{
			return false;
		}
		if(p1maping[str2[i]-'a']==' ')
		{
			pmaping[str2[i]-'a'] = str1[i];	
		}
		else if (pmaping[str2[i]-'a']!=str1[i])
		{
			return false;
		}
	}

	return true;
}
int main()
{
	string str1,str2;
	cin>>str1>>str2;

	cout<<isomorphicBF(str1,str2)<<endl;
}