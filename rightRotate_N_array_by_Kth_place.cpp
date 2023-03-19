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

void rotateBF(int arr[],int n,int k)
{
	int temp[k];
	int j =0;
	for(int i=n-k; i<n; i++)
	{
		temp[j++] = arr[i];
	}

	for(int i=n-k-1; i>=0; i--)
	{
		arr[i+k] = arr[i];
	}
	for(int i=0; i<k; i++)
	{
		arr[i] = temp[i];
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
	rotateBF(arr,n,k);
	printArr(arr,n);
}