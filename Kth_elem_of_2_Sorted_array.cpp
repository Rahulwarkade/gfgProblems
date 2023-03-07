#include<bits/stdc++.h>
using namespace std;
int kthElemBF(int arr1[],int arr2[],int n,int m,int k)
{
	int temp[n+m];
	int i=0,j=0,l=0;
	while(i<n && j<m)
	{
		if(arr1[i]<=arr2[j])
		{
			temp[l++] = arr1[i++];
		}
		else
		{
			temp[l++] = arr2[j++];
		}
	}
	while(i<n)
	{
		temp[l++]=arr1[i++];
	}	
	while(j<m)
	{
		temp[l++]=arr2[j++];
	}

	return temp[k-1];
}

int kthElemOptimized(int arr1[],int arr2[],int n,int m,int k)
{
	int i =0,j=0,counter =0;
	int ans = -1;
	while(i<n && j<m)
	{
		if(counter==k){
			return ans;
		}
		if(arr1[i]<=arr2[j]){
			ans = arr1[i++];
		}
		else{
			ans = arr2[j++];
		}
		counter++;
	}

	while(i<n)
	{
		if(counter==k){
			return ans;
		}
		ans = arr1[i++];
		counter++;
	}
	while(j<m)
	{
		if(counter==k){
			return ans;
		}
		ans = arr2[j++];
		counter++;
	}

	return -1;

}

int kthElemOptimal(int arr1[],int arr2[],int n,int m,int k)
{
	if(n>m)
	{
		return kthElemOptimal(arr2,arr1,m,n,k);
	}

	int low = max(0,k-m),high = min(n,k);

	while(low<=high)
	{
		int cut1 = (low+high)>>1;
		int cut2 = k-cut1;

		int l1 = (cut1==0)? INT_MIN : arr1[cut1-1];
		int l2 = (cut2==0)? INT_MIN : arr2[cut2-1];
		int r1 = (cut1==n)? INT_MAX : arr1[cut1];
		int r2 = (cut2==m)? INT_MAX : arr2[cut2];

		if(l1<=r2 && l2<=r1)
		{
			return max(l1,l2);
		}
		else if(l1>r2)
		{
			high = cut1-1;
		}
		else
		{
			low = cut1+1;
		}
	}
	return -1;
}
int main()
{
	int N,M;
	cin>>N>>M;

	int arr[N];
	int arr2[M];

	for(int i=0; i<N; i++)
		cin>>arr[i];
	for(int i=0; i<M; i++)
		cin>>arr2[i];


	cout<<kthElemOptimized(arr,arr2,N,M,5);

/*
	cout<<kthElemBF(arr,arr2,N,M,5);

	Time complexity = O(N+M);
	Sapce complexity = O(N+M);
*/
/*
	cout<<kthElemOptimized(arr,arr2,N,M,5);

	Time complexity = O(N+M);
	Sapce complexity = O(1);
*/

/*
	cout<<KthElemOptimal(arr,arr2,N,M,5);

	Time complexity = O(log(min(m,n)));
	Sapce complexity = O(1);
*/
}