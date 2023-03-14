#include<bits/stdc++.h>
using namespace std;

int rotation(int arr[],int n)
{
	int start = 0,end = n-1;

	while(start<=end)
	{
		int mid = start+((end - start)>>1);

		if(arr[start]<arr[end])
			return start;
		if(mid!=0 && arr[mid]<arr[mid-1])
			return mid;
		else if(arr[start]<=arr[mid])
			start = mid+1;
		else 
			end = mid-1;
	}
	return -1;
}

int main()
{
	int N; 
	cin>>N; 

	int arr[N];

	for(int i=0; i<N; i++)
		cin>>arr[i];

	cout<<rotation(arr,N);
}