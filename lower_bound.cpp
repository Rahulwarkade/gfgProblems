
#include<bits/stdc++.h>
using namespace std;

int lowerBound(int arr[],int n,int key)
{
	int start = 0; 
	int end = n-1;
	int mid=-1; 

	while(start<=end)
	{
		mid = start+((end-start)/2);
		if(arr[mid]==key || (key>arr[mid] && key<arr[mid+1])){
			return mid;
		}
		else if(arr[mid]>key)
		{
			end = mid-1;
		}
		else
		{
			start = mid+1;
		}
	}
	return -1;
}
int usingStl(int arr[],int n,int key)
{
	int idx = lower_bound(arr,arr+n,key)-arr;
	idx--;

	if(idx>=0) return idx;
	else return-1;
}
int main()
{
	int N,X;
	cin>>N>>X;

	int arr[N];

	for(int i=0; i<N; i++)
		cin>>arr[i];

	cout<<usingStl(arr,N,X);

}