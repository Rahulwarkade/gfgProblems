#include<bits/stdc++.h>
using namespace std;


bool sisRotatedArr(int A[],int l,int h,int key)
{
	int mid;
	int n=h;
	while(l<=h)
	{
		mid = l+((h-l)/2);

		if(A[mid]==key)
			return true;
		if((mid!=0 && A[mid-1]==key)|| (mid!=n-1 && A[mid+1]==key))
			return true;

		if(A[l]<=A[mid])
		{
			if(A[l]<=key && key<A[mid])
				h = mid-1;
			else
				l = mid+1;
		}
		else
		{
			if(A[h]>=key && key>A[mid])
				l = mid+1;
			else
				h = mid-1;
		}
	}
	return false;
}
int main()
{
	int N;
	cin>>N; 
	int arr[N];

	for(int i=0; i<N; i++)
		cin>>arr[i];

	// search in sorted rotated array = sisRotatedArr;

	cout<<sisRotatedArr(arr,0,N-1,0)<<endl;
}