#include<bits/stdc++.h>
using namespace std;
void printArr(int arr[],int n)
{
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void moveZeroToEndOptimized(int arr[],int n)
{
	int k=0; 
	while(arr[k]!=0)
	{
		k++;
	}
	int i=k,j=k+1;

	while(i<n && j<n)
	{
		if(arr[j]!=0)
		{
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			i++;
			j++;
		}
		else
			j++;
	}
}

void moveZeroToEndBF(int arr[],int n)
{
	int temp[n];
	int j =0;
	for(int i=0; i<n; i++)
	{
		if(arr[i]!=0)
		{
			temp[j++] = arr[i];
		}
	}

	for(int i=j; i<n; i++)
	{
		temp[j++] = 0;
	}

	for(int i=0; i<n; i++)
		arr[i] = temp[i];
}
int main()
{
	int n;
	cin>>n;

	int arr[n];

	for(int i=0; i<n; i++)
		cin>>arr[i];
	printArr(arr,n);
	moveZeroToEndOptimized(arr,n);
	printArr(arr,n);
}