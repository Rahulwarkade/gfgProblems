#include<bits/stdc++.h>
using namespace std;

void longestSubarrSumBF(int arr[],int n,int k)
{
	int mx = INT_MIN;

	for(int i=0; i<n; i++)
	{
		for(int j=i; j<n; j++)
		{
			int sum = 0;
			for(int k=i; k<=j; k++)
			{
				sum += arr[k];
			}

			if(sum==k)
			{
				mx = max(mx,j-i+1);
			}
		}
	}
	cout<<mx<<endl;
}
void longestSubarrSumBF1(int arr[],int n,int k)
{
	int mx = INT_MIN;
	int prefix[n];
	prefix[0] = arr[0];

	for(int i=1; i<n; i++)
		prefix[i] = prefix[i-1]+arr[i];

	for(int i=0; i<n; i++)
	{
		for(int j=i; j<n; j++)
		{
			int sum = 0;
			if(i==0)
				sum = prefix[0];
			else
				sum = prefix[j]-prefix[i];
			if(sum==k)
			{
				mx = max(mx,j-i+1);
			}
		}
	}
	cout<<mx<<endl;
}
void longestSubarrSum(int arr[],int n,int k)
{
	int i,j;
	i=j=0;
	int sum = 0;
	int mxLength = 0;
	while(i<n && j+1<n)
	{
		if(sum==k)
		{
			mxLength = max(mxLength,j-i+1);
			sum += arr[j];
			j++;
		}
		else if(sum>k)
		{
			sum-=arr[i];
			i++;
		}
		else
		{
			sum+=arr[j];
			j++;
		}
	}
	cout<<mxLength<<endl;
}	
int main()
{
	int k;
	cin>>k;

	int arr[] = {2,3,5,1,9};

	longestSubarrSumBF1(arr,5,10);
}