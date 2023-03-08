#include<bits/stdc++.h>
using namespace std;
void printArr(int arr[],int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void rotateOptimize(int arr[],int n,int k)
{
	int temp[k];
	for(int i=0; i<k; i++)
	{
		temp[i] = arr[i];
	}

	for(int i=k; i<n; i++)
	{
		arr[i-k] = arr[i];
	}
	int j=0;
	for(int i=n-k; i<n; i++)
	{
		arr[i] = temp[j++];
	}
}
int main(){
	int n,k;
	cin>>n>>k;

	int arr[n];

	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	printArr(arr,n);
	rotateOptimize(arr,n,k);
	printArr(arr,n);
}