#include<bits/stdc++.h>
using namespace std;

int substrCountBF(string s, int k)
{
	int n = s.length();
	vector<string> st;
	for(int i=0; i<n; i++)
	{
		for(int j=i; j<n; j++)
		{
			string sub = "";
			for(int r=i; r<=j; r++)
			{
				sub.push_back(s.at(r));
			}
			set<char> chs;
			for(int l=0; l<sub.length(); l++)
			    chs.insert(sub.at(l));
			
			if(chs.size()==k)
			    st.push_back(sub);
		}
	}
    return st.size();
}

long long int substrCountOptimized (string s, int k) {
    	//code here.
        int n = s.length();
        long long res = 0;
        int arr[26];
    	for(int i=0; i<n; i++)
    	{
    	    memset(arr,0,sizeof(arr));
    	    int dist = 0;
    		for(int j=i; j<n; j++)
    		{
                if(arr[s[j]-'a']==0)
                    dist++;
                arr[s[j]-'a']++;
                if(dist==k)
                    res++;
                if(dist>k)
                    break;
    		}
	}
        return res;
}

int atmostKdistChar(string s , int k)
{
	if(k==0) return 0;
	int n = s.length();
	int j = 0;
	long long ans  = 0;
	map<char,int> mp;
	int i=0;
	for(; i<n; i++)
	{
		mp[s.at(i)]++;

		while(mp.size()>k)
		{
			mp[s.at(j)]--;
			if(mp[s.at(j)]==0)
			{
				mp.erase(s.at(j));
			}
			j++;
		}
		ans += i-j+1;
	}
	return ans;
}

long long int substrCountOptimal (string s, int k) 
{
	return atmostKdistChar(s,k) - atmostKdistChar(s,k-1);
}
int main()
{
	string sr;
	cin>>sr;

	cout<<substrCountOptimal(sr,1)<<endl;
}