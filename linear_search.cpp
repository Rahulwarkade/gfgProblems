#include<bits/stdc++.h>
using namespace std;

void linearSearch(int arr[],int n,int key)
{
	int ans = -1;
	for(int i=0; i<n; i++)
	{
		if(arr[i]==key)
		{
			ans = i;
			break;
		}
	}
	cout<<ans<<endl;
}
int main()
{
	int n,num; 
	cin>>n>>num; 
	int arr[n];

	for(int i=0; i<n; i++)
		cin>>arr[i];

	linearSearch(arr,n,num);
}