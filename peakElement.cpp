#include<bits/stdc++.h>
using namespace std;

int peakElementBF(int arr[],int n)
{
	if(arr[0]>=arr[1])
		return arr[0];
	for(int i=1; i<n-1; i++)
	{
		if(arr[i]>=arr[i-1] && arr[i]<=arr[i+1])
			return arr[i];
	}

	return arr[n-1];
}

int peakElementOpitimized(int arr[],int n)
{
	int start = 0; 
	int end = n-1;
	int mid;
	while(start<=end)
	{
		mid = start+((end-start)/2);

		if((mid==0 || arr[mid]>=arr[mid-1]) && (mid==n-1 || arr[mid]>=arr[mid+1])){
			return mid;
		}
		else if(arr[mid-1]>=arr[mid]){
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}
	return -1;
}
int peakEleOptimal(int arr[], int n) {
  int start = 0, end = n - 1;

  while (start < end) {
    int mid = (start + end) / 2;

    if (mid == 0)
      return arr[0] >= arr[1] ? arr[0] : arr[1];

    if (mid == n - 1)
      return arr[n - 1] >= arr[n - 2] ? arr[n - 1] : arr[n - 2];

    //Cheking whether peak ele is in mid position
    if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
      return mid;

    //If left ele is greater then ignore 2nd half of the elements
    if (arr[mid] < arr[mid - 1])
      end = mid - 1;

    //Else ignore first half of the elements
    else
      start = mid + 1;
  }

  return arr[start];
}
int main()
{
	int N;
	cin>>N;

	int arr[N];

	for(int i=0; i<N; i++)
		cin>>arr[i];

	cout<<peakEleOptimal(arr,N);
}