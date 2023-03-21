#include<bits/stdc++.h>
using namespace std;
int upperBound(int arr[],int n,int key)
{
	int start = 0;
	int end = n-1;
	int mid = -1;

	while(start<=end)
	{
		mid = start+((end-start)/2);
		if(arr[mid]==key)
			return mid+1;
		else if(arr[mid]>key && key>arr[mid-1])
			return mid;
		else if(key>arr[mid])
			start = mid+1;
		else
			end = mid-1;
	}
	return -1;
}

int usingStl(int arr[],int n,int x)
{
	int idx = upper_bound(arr,arr+n,x)-arr;

	if(idx<n) return idx;
	else return -1;
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