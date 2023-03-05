#include<bits/stdc++.h>
using namespace std;

int appearOnes(int A[],int N)
{
	int startIdx = 0;
	int endIdx = N-1;

	int instance = 0;
	while(startIdx<=endIdx)
	{
		if(startIdx==endIdx)
			instance ^=A[startIdx];
		instance ^= (A[startIdx++] ^ A[endIdx--]);
	}
	return instance;
}
int main()
{
	int N;
	cin>>N;
	int arr[N];

	for(int i=0; i<N; i++)
		cin>>arr[i];

	cout<<appearOnes(arr,N);
}