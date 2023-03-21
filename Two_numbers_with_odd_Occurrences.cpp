#include<bits/stdc++.h>
using namespace  std;


vector< long long int > twoOddNum(long long Arr[],long long N)
{
	vector<long long int > oddVac;
	long long oddOccur = 0;
	int start = 0,end = N-1;
	while(start<=end)
	{
		if(start==end)
			oddOccur ^= Arr[start++];
		else 
			oddOccur ^= Arr[start++]^Arr[end--];
	}

	int num = oddOccur;
	int k = 0;
	while(num)
	{
		if(num&1)
		{
			break;
		}
		k++
		num>>=1;
	}

	long long firtOdd =0, secondOdd = 0;

	int left = 0,right = N-1;

	while(left<=right)
	{
		if((Arr[left])&(1<<k))
			firtOdd ^= Arr[left++];
		else
			secondOdd ^= Arr[left++];		

		if((Arr[right])&(1<<k))
			firtOdd ^= Arr[right--];
		else
			secondOdd ^= Arr[right--];
	}

	if(firtOdd>secondOdd){
		oddVac.push_back(firtOdd);
		oddVac.push_back(secondOdd);
	}
	else{
		oddVac.push_back(secondOdd);
		oddVac.push_back(firtOdd);
	}

	return oddVac;
}
int main()
{
	int t; 
	cin>>t; 

	while(t--)
	{
		long long int N; 
		cin>>N; 
		long long Arr[N];

		for(int i=0; i<N; i++)
			cin>>Arr[i];

		vector<long long int> oddOcc = twoOddNum(Arr,N);

		for(auto val : oddOcc)
			cout<<val<<" ";
		cout<<endl;
	}
}