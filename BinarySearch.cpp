#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int n,int key)
{
	int start = 0; 
	int end = n-1;
	int mid=-1; 

	while(start<=end)
	{
		mid = start+((end-start)/2);
		if(arr[mid]==key){
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
int recbinarySearch(int arr[],int start,int end,int key)
{
	int mid = start+((end-start)/2);
	if(start>=end)
		return -1;
	if(arr[mid]==key)
		return mid;

	if(arr[mid]>key)
		recbinarySearch(arr,start,mid-1,key);
	else
		recbinarySearch(arr,mid+1,end,key);

}

bool usingStl(int arr[],int n,int key)
{
	return binary_search(arr,arr+n,key);
}

int main()
{
	int N,K;
	cin>>N>>K;

	int arr[N];
	for(int i=0; i<N; i++)
		cin>>arr[i];
	  cout<<usingStl(arr,N,K); 

}