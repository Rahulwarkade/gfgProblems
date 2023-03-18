#include<bits/stdc++.h>
using namespace std;
void printArr(int arr[],int n)
{
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
void reverse(int arr[],int start,int end)
{
	while(start<end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}
void reversalAlgo(int arr[],int n,int k)
{
	reverse(arr,0,n-k-1);

	reverse(arr,n-k,n-1);

	reverse(arr,0,n-1);
}
int main(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];

	printArr(arr,n);
	reversalAlgo(arr,n,k);
	printArr(arr,n);
}