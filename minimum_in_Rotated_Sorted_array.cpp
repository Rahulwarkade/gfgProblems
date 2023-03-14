#include<bits/stdc++.h>
using namespace std;


int findMin(int arr[],int n)
{
	int start = 0,end=n-1,mid;
	int minVal = INT_MAX;
	while(start<=end)
	{
		mid = start+((end-start)>>1);
		if(arr[start]<=arr[end])
			minVal = min(minVal,arr[start]);
		if(arr[start]<=arr[mid]){
			minVal = min(minVal,arr[start]);
			start = mid+1;
		}
		else{
			minVal = min(minVal,arr[mid]);
			end = mid-1;
		}
	}
	if(minVal==INT_MAX) minVal = -1;
	return minVal;
}
int main()
{
	int N;
	cin>>N;

	int arr[N];

	for(int i=0; i<N; i++)
		cin>>arr[i];

	cout<<findMin(arr,N);
}