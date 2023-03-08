#include<bits/stdc++.h>
using namespace std;

void rotateBF(int arr[],int n)
{
	int temp[n];
	int tem = arr[0];

	for(int i=1; i<n; i++)
	{
		temp[i-1] = arr[i];
	}
	temp[n-1] = tem;

	for(int i=0; i<n; i++)
		arr[i] = temp[i];
}
void rotateOptimize(int arr[],int n)
{
	int temp[n];
	int tem = arr[0];

	for(int i=1; i<n; i++)
	{
		arr[i-1] = arr[i];
	}
	arr[n-1] = tem;
}
void printArr(int arr[],int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	printArr(arr,n);
	rotateOptimize(arr,n);
	cout<<endl;
	printArr(arr,n);
}