#include<bits/stdc++.h>
using namespace std;

int singleElem(int arr[],int n)
{
	int start = 0,end = n-1;
	int single = 0;
	while(start<=end)
	{	
		if(start==end)
			single ^= arr[start++];
		else
			single ^= (arr[start++]^arr[end--]);
	}
	return single;
}
int main()
{
	int N; 
	cin>>N;

	int arr[N];

	for(int i=0; i<N; i++)
		cin>>arr[i];

	cout<<singleElem(arr,N);
}