#include<bits/stdc++.h>
using namespace std;

void printVac(vector<int> &vac)
{
	for(int &val : vac)
		cout<<val<<" ";
	cout<<endl;
}

class Solution
{
public:
	vector<int> subarraySumA(vector<int> arr,int n,long long s)
	{
		vector<int> ans;
		for(int i=0; i<n; i++)
		{
			for(int j=i; j<n; j++)
			{
				int sum =0;
				for(int k=i; k<=j; k++)
				{
					sum+=arr[k];
				}
				if(sum==s)
				{
					ans.push_back(i+1);
					ans.push_back(j+1);
					return ans;
				}
			}
		}

        if(ans.size()==0)
        {
            ans.push_back(-1);
        }
        return ans;
	}

	vector<int> subarraySumB(vector<int> arr,int n,long long s)
	{
		vector<int> ans;
		int pre[n];
		pre[0] = arr[0];
		for(int i=1; i<arr.size(); i++)
		{
			pre[i] = pre[i-1]+arr[i];
		}

		for(int i=0; i<n; i++)
		{
			for(int j=i; j<n; j++)
			{
				int sum = 0;
				if(j==0)
				{
					sum = pre[j];
				}
				else{
					sum = pre[j]-pre[i-1];
				}
				if(sum==s)
				{
					ans.push_back(i+1);
					ans.push_back(j+1);
					return ans;
				}
			}
		}
        if(ans.size()==0)
        {
            ans.push_back(-1);
        }
        return ans;
	}
};

vector<int> subarraySumC(vector<int> vac,long long n,long long s)
	{
		int left =0;
		int right = 0;
		vector<int> ans;
		int sum = vac[0];
		while(left<n || right<n)
		{
			if(sum==s)
			{
				ans.push_back(left+1);
				ans.push_back(right+1);
				return ans;
			}
			else if(sum<s)
			{
				right++;
				sum += vac[right];
			}
			else
			{
				sum -= vac[left];
				left++;
			}
		}
        if(ans.size()==0)
        {
            ans.push_back(-1);
        }
        return ans;
}
int main(){
	int t;
	cin>>t;

	while(t--)	
	{
		long long n,s;
		cin>>n>>s;

		vector<int> arr;
		for(int i=0; i<n; i++)
		{
			int x;
			cin>>x;
			arr.push_back(x);
		}
		// Solution ob;
		vector<int> res;
		// res = ob.subarraySumA(arr,n,s);
		res = subarraySumC(arr,n,s);
		// for(auto val : res)
		// 	cout<<val<<" ";

		if(res.size()==0)
		{
			cout<<-1;
		}
		else{
			for(int i=0; i<res.size(); i++)
			cout<<res[i]<<" ";
			cout<<endl;
		}
	}
}